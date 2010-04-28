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
                                                 Point_3( 0,0,1 ),
                                                 Point_3( 0,1,0 ),
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
  for( Vertex_iterator pVertex = mesh_->vertices_begin(  );
       pVertex != mesh_->vertices_end(  ); pVertex++) {
    printf( "id: %ld: ( %.2f, %.2f, %.2f )\n",
            pVertex->id(  ),
            pVertex->point(  ).x(  ),
            pVertex->point(  ).y(  ),
            pVertex->point(  ).z(  ));
  }
}

TEST_F( CurvatureTest, printPrecalculateCotValues ) {
  printf( "Cot45Value: %.5f", cot45Value );
  printf( "Cot60Value: %.5f", cot60Value );
  printf( "Cot90Value: %.5f", cot90Value );
}

TEST_F( CurvatureTest, testHalfedgeCotValues ) {
  curvature_->calculateEdgeCotValues(  )  ;

  float value;
  for (Halfedge_iterator pHalfedge = mesh_->halfedges_begin(  );
       pHalfedge != mesh_->halfedges_end(  ); ++pHalfedge)
  {
    //    value = curvature_->getHalfedgeCotValue( pHalfedge );
  }
}

TEST_F( CurvatureTest, testEdgeCotValues ) {
  curvature_->calculateEdgeCotValues(  );
  //TODO: add some assertions
  Vertex_handle  v0,v1;
  Vector_3 vec;
  float length;
  float expected;
  float actual;
  
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
