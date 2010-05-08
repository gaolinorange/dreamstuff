// testMeshCore.h --- Test the Core of Mesh Data structure
// copyright (c) 2010 dreamway
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free Software Foundation;
//  Feel free to contact dreamway(jingwenlai@163.com)
// 
// website: cg.xplore.cn
// 
// 

// Commentary: 
// 
// 
//  
#ifndef _TESTMESHCORE_H_
#define _TESTMESHCORE_H_



#include "MeshCore/MeshCore.h"
#include <fstream>
#include <gtest/gtest.h>

class MeshCoreTest : public ::testing::Test
{
 protected:
  virtual void SetUp()
  {
    mesh_ = new MeshCore();
    Halfedge_handle h = mesh_->make_tetrahedron(Point_3(0,0,0),Point_3(0,0,1),Point_3(0,1,0),Point_3(1,0,0));

    mesh_->set_indices();
    mesh_->init_index_to_vertex_map();
  }
  virtual void TearDown()
  {
    delete mesh_;
  }

  MeshCore * mesh_;
};

TEST_F(MeshCoreTest,testInit)
{
  //do not need to add code here
}

TEST_F(MeshCoreTest,testMeshCoreIsTetrahedron)
{
  Halfedge_handle h = mesh_->halfedges_begin( );
  EXPECT_EQ(true,mesh_->is_tetrahedron(h));
}

TEST_F(MeshCoreTest,testWriteTetrahedron)
{
  //Important: the test_tetrahedron.off file is further used by MeshBuilder
  std::ofstream outFile("test_tetrahedron.off",std::ios::out);
  outFile<<(*mesh_);
}

TEST_F(MeshCoreTest,testBoundingBox)
{
  mesh_->compute_bounding_box();
  Iso_cuboid_3 box = mesh_->get_bounding_box();
  EXPECT_FLOAT_EQ(0,box.xmin());
  EXPECT_FLOAT_EQ(0,box.ymin());
  EXPECT_FLOAT_EQ(0,box.zmin());

  EXPECT_FLOAT_EQ(1,box.xmax());
  EXPECT_FLOAT_EQ(1,box.ymax());
  EXPECT_FLOAT_EQ(1,box.zmax());  
}

TEST_F(MeshCoreTest,testVertexHandlePrint)
{
  //  mesh_->test_print_vertex_handles(); 
}

TEST_F(MeshCoreTest,testHalfedgeHandlePrint)
{
  //  mesh_->test_print_halfedge_handles();
}

TEST_F(MeshCoreTest,testFacetHandlePrint)
{
  //  mesh_->test_print_facet_handles();
}

TEST_F(MeshCoreTest,testInitIndexToVertexMap)
{
  mesh_->init_index_to_vertex_map();

  //Verify it by comparing the position of index_to_vertex_map
  // printf("print by using builder\n");
  // for(Vertex_iterator pVertex = pMesh->vertices_begin();
  //     pVertex != pMesh->vertices_end(); pVertex++)
  // {
  //   printf("id: %ld  , pos: (%.2f,%.2f,%.2f)\n",pVertex->id(),
  //          pVertex->point().x(),
  //          pVertex->point().y(),
  //          pVertex->point().z());
  // }
  
  // printf("print by using index_to_vertex_map\n");
  // std::size_t num_vertices = pMesh->size_of_vertices();
  // for (std::size_t i = 0; i < num_vertices; ++i)
  // {
  //   printf("id : %ld,  pos: (%.2f,%.2f,%.2f)\n",i,
  //          pMesh->get_vertex_handle(i)->point().x(),
  //          pMesh->get_vertex_handle(i)->point().y(),
  //          pMesh->get_vertex_handle(i)->point().z()
  //          );    
  // }

  //Verify for furthing testing
  std::size_t i = 0;
  for (Vertex_iterator pVertex = mesh_->vertices_begin(); pVertex != mesh_->vertices_end(); pVertex++)
  {
    EXPECT_EQ(i,pVertex->id());
    Point_3 vertex_pos = pVertex->point();
    Point_3 vertex_pos_by_idx = mesh_->get_vertex_handle(i)->point();
    EXPECT_FLOAT_EQ(vertex_pos.x(),vertex_pos_by_idx.x());
    EXPECT_FLOAT_EQ(vertex_pos.y(),vertex_pos_by_idx.y());
    EXPECT_FLOAT_EQ(vertex_pos.z(),vertex_pos_by_idx.z());

    i++;
  }  
}
      
TEST_F( MeshCoreTest, testFacetDegree )
{
  for( Facet_iterator pFacet = mesh_->facets_begin( );
       pFacet != mesh_->facets_end( ); pFacet++) {
    EXPECT_EQ( 3 , mesh_->degree( pFacet ) );
  }
}

TEST_F( MeshCoreTest, testVertexValence )
{
  for( Vertex_iterator pVertex = mesh_->vertices_begin( );
       pVertex != mesh_->vertices_end(  ); pVertex++) {
    EXPECT_EQ( 3, mesh_->valence( pVertex ) );
  }  
}
  
TEST_F( MeshCoreTest, testAverageLength ) {
  float expected_length = (float)(sqrt( 2.0 )*3+1*3)/6;
  float actual = mesh_->get_average_edge_length(  ) ;
  //  printf( "actual edge average length = %.3f\n",actual );
  
  EXPECT_FLOAT_EQ( expected_length, actual);
}

			   

#endif /* _TESTMESHCORE_H_ */

// 
// testMeshCore.h ends here
