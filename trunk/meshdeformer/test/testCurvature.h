/* testCurvature.h --- 
 * copyright (c) 2010 dreamway
 */

/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the Free Software Foundation;
 *  Feel free to contact dreamway(jingwenlai@163.com)
 * 
 * website: cg.xplore.cn
 */

/* Commentary: 
 * 
 */
#ifndef _TESTCURVATURE_H_
#define _TESTCURVATURE_H_

#include <gtest/gtest.h>
#include <cmath>
#include <stdio.h>

#include "MeshCore/MeshCore.h"
#include "Plugin-Curvature/Curvature.h"

class CurvatureTest : public ::testing::Test
{
 protected:
  virtual void SetUp(  ) {
    mesh_ = new MeshCore(  );
    Halfedge_handle h = mesh_->make_tetrahedron( Point_3( 0,0,0 ),
                                                 Point_3( 0,1,0 ),
                                                 Point_3( 0,0,1 ),
                                                 Point_3( 1,0,0 )
                                                 );
    mesh_->set_indices( );
    mesh_->init_index_to_vertex_map(  );

    curvature_ = new Curvature(  );
    curvature_->setMesh( mesh_ );

    cot45Value = 1.0/tan( ( 45.0/180.0 ) * CGAL_PI );
    cot60Value = 1.0/tan( ( 60.0/180.0 ) *CGAL_PI );
    cot90Value = 1.0/tan( 0.5 * CGAL_PI );
    epislon = 1e-6;
  }
  
  virtual void TearDown(  ) {
    delete mesh_;
    delete curvature_;
  }

  MeshCore* mesh_;
  Curvature * curvature_;

protected: //precalculated data
  float cot45Value;
  float cot90Value;
  float cot60Value;
  float epislon;
};

TEST_F( CurvatureTest, testInit ) {
  //no need to do things
}

TEST_F( CurvatureTest, testPrintMesh ) {
  std::size_t i = 0;
  for( Vertex_iterator pVertex = mesh_->vertices_begin(  );
       pVertex != mesh_->vertices_end(  ); pVertex++) {
    printf( "id: %ld: ( %.2f, %.2f, %.2f )\n",
            pVertex->id(  ),
            pVertex->point(  ).x(  ),
            pVertex->point(  ).y(  ),
            pVertex->point(  ).z(  ));

    //using getVertexHandle
    Vertex_handle ref_v_handle = mesh_->get_vertex_handle( i );
    ASSERT_FLOAT_EQ( ref_v_handle->point().x(),pVertex->point(  ).x(  ) );
    ASSERT_FLOAT_EQ( ref_v_handle->point(  ).y(  ), pVertex->point(  ).y(  ) );
    ASSERT_FLOAT_EQ( ref_v_handle->point(  ).z(  ), pVertex->point(  ).z(  ) );
    
    i++;
  }
}

TEST_F( CurvatureTest, printPrecalculateCotValues ) {
  printf( "Cot45Value: %.5f\n", cot45Value );
  EXPECT_FLOAT_EQ( 1, cot45Value );
  printf( "Cot60Value: %.5f\n", cot60Value );
  EXPECT_FLOAT_EQ( sqrt( 3.0 )/3, cot60Value );
  printf( "Cot90Value: %.5f\n", cot90Value );
  EXPECT_NEAR( 0.0, cot90Value, epislon );
}

TEST_F( CurvatureTest, testCalculateAngle ) {
  Halfedge_handle h = mesh_->halfedges_begin(  );
  Vertex_handle v0 = h->vertex(  );
  Vertex_handle v1 = h->next(  )->vertex(  );
  Vertex_handle v2 = h->next(  )->next(  )->vertex(  );

  //debugging helper: for judging which triangle you're using
/*   printf( "v0: ( %.2f,%.2f,%.2f )\n",v0->point(  ).x(  ),v0->point(  ).y(  ),v0->point(  ).z(  ) ); */
/*   printf( "V1: ( %.2f, %.2f,%.2f) \n",v1->point(  ).x(  ),v1->point(  ).y(  ),v1->point(  ).z(  ) ); */
/* printf ("v2: ( %.2f, %.2f, %.2f )\n",v2->point(  ).x(  ),v2->point(  ).y(  ),v2->point(  ).z(  )); */
  float value = curvature_->calculateAngle( v0, v1, v2 )  ;
  printf( "the angle value is : %.2f\n",value );
  float expected_angle = ( 45.0/180.0 ) * CGAL_PI;
  EXPECT_NEAR( expected_angle, value, epislon );
}

TEST_F( CurvatureTest, testCalculateVecLength ) {
  Halfedge_handle h = mesh_->halfedges_begin(  );
  Vertex_handle v0 = h->vertex(  );
  Vertex_handle v1 = h->next(  )->vertex(  );
  float length = curvature_->calculateVecLength( v0,v1 );
  EXPECT_FLOAT_EQ( 1.0, length );
}

TEST_F( CurvatureTest, testEdgeCotValues ) {
  curvature_->calculateEdgeCotValues(  );

  Vertex_handle  v0,v1;
  Vector_3 vec;
  float length;
  float expected;
  float actual;

  //Checking all edge's corresponding cot_sum_values  
  for (Halfedge_iterator pHalfedge = mesh_->halfedges_begin( );
       pHalfedge != mesh_->halfedges_end( ); pHalfedge++)
  {
    v0 = pHalfedge->vertex(  );
    v1 = pHalfedge->opposite( )->vertex(  );
    vec = v1->point(  )-v0->point(  );
    length = sqrt(vec.x(  )*vec.x(  )+
                  vec.y(  )*vec.y(  )+
                  vec.z(  )*vec.z(  ));
    if( fabs( length-1.0 ) < epislon ) {
      expected = cot45Value+cot45Value;
      actual = curvature_->getHalfedgeCotValue( pHalfedge );
      EXPECT_FLOAT_EQ( expected, actual );
    }

    if( fabs( length - sqrt( 2 ) ) < epislon ) {
      expected = cot60Value+cot90Value;
      actual = curvature_->getHalfedgeCotValue( pHalfedge );
      EXPECT_FLOAT_EQ( expected, actual );
    }    
  }  
}

TEST_F( CurvatureTest, testVoronoiAreas ) {
  curvature_->calculateVoronoiAreas(  );
  //TODO: add some assertions
  for (Vertex_iterator pVertex =  mesh_->vertices_begin(  );
       pVertex != mesh_->vertices_end(  ); ++pVertex)
  {
    //two kind of test_cases
    //1. around ( 0,0,0 )
    if( fabs(pVertex->point(  ).x(  )-0.0) < epislon &&
        fabs( pVertex->point(  ).y(  )-0.0 ) < epislon &&
        fabs( pVertex->point(  ).z(  )-0.0 ) < epislon ) {
      float one_voronoi = 1.0/8 * ( 1+1 );
      float expect_voronoi_area = 3 * one_voronoi;
      EXPECT_FLOAT_EQ( expect_voronoi_area, curvature_->getVertexVoronoiArea( pVertex ) );
    } else {     //2. around( ?,1,? )
      float angle45_voronoi = 1.0/8 * ( 1 );
      float angle60_voronoi = 1.0/8 * ( 2*sqrt( 3.0 )/3 + 2*sqrt( 3.0 )/3 );
      float expect_voronoi_area = 2*angle45_voronoi + angle60_voronoi;
      EXPECT_FLOAT_EQ( expect_voronoi_area, curvature_->getVertexVoronoiArea( pVertex ) );
    }    
  }  
}

TEST_F( CurvatureTest, testMeanCurvature ) {
  curvature_->slotCalculateMeanCurvatures(  );
  //TODO: add some assertions
  
}

TEST_F( CurvatureTest, testGaussianCurvature ) {
  curvature_->slotCalculateGaussianCurvatures(  );
  //TODO: add some assertions
  
}


#endif /* _TESTCURVATURE_H_ */
/* testCurvature.h ends here */
