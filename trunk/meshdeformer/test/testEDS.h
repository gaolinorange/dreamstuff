/* -*-c++-*-
 * testEDS.h --- 
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
#ifndef _TESTEDS_H_
#define _TESTEDS_H_

#include "testMeshCore.h"
#include "../Plugin-EDS/EDS.h"
#include "MockDeformationGraph.h"

using ::testing::Return;

class EDSTest : public MeshCoreTest
{
 public:
  virtual void SetUp(  ) {
    MeshCoreTest::SetUp(  );
    
    eds_ = new EDS(  );
    eds_->setMesh( mesh_ );    
  }
  virtual void TearDown(  ) {
    delete eds_;
    MeshCoreTest::TearDown(  );
  }

  EDS* eds_;
 };

 TEST_F( EDSTest, testInit ) {
   //no need to do things
 }


 TEST_F( EDSTest, testPrintMesh ) {
   assert( mesh_ != NULL );
   mesh_->test_print_vertex_handles(  );
   EXPECT_EQ( 4, mesh_->size_of_vertices(  ) );
   EXPECT_EQ( 4, mesh_->size_of_facets(  ) );
   EXPECT_EQ( 12, mesh_->size_of_halfedges(  ) );
 }

TEST_F( EDSTest, testConstructDeformationGraph ) {
  assert( eds_ != NULL );
  eds_->construct_deformation_graph( 4 );
  
  EXPECT_EQ( 4,eds_->deformation_graph(  )->num_nodes(  ) );
}

/*
TEST_F( EDSTest, testCalculateKNearestNodesUsingPoint ) {
  assert( eds_ != NULL );
  eds_->construct_deformation_graph( 4 );//important
  EXPECT_EQ( 4,eds_->deformation_graph(  )->num_nodes(  ) );
  
  eds_->calculate_k_nearest_nodes_using_point(  );
  //TODO: add some assertion
  
}
*/

TEST_F( EDSTest, testCalculateKNearestNodesUsingDGNode ) {
  assert( eds_ != NULL );
  eds_->construct_deformation_graph( 4 );
  EXPECT_EQ( 4,eds_->deformation_graph(  )->num_nodes(  ) );
  
  eds_->calculate_k_nearest_nodes_using_dgnode(  );
  //todo: add some assertion
}

/**
   This test is actually the same as above
*/
TEST_F( EDSTest, testCalculate_K_Nearest_Nodes ) {
  assert( eds_ != NULL );
  eds_->construct_deformation_graph( 4 );
  EXPECT_EQ( 4, eds_->deformation_graph(  )->num_nodes(  ) );
  
  eds_->deformation_graph(  )->print(  );
  eds_->calculate_k_nearest_nodes(  );
  //TODO: add some assertion1
}




#endif /* _TESTEDS_H_ */

/* testEDS.h ends here */
