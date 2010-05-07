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
 }

TEST_F( EDSTest, testConstructDeformationGraph ) {
  assert( eds_ != NULL );
  eds_->construct_deformation_graph(  )  ;
}

TEST_F( EDSTest, testCalculateKNearestNodesUsingPoint ) {
  assert( eds_ != NULL );
  eds_->construct_deformation_graph(  );//important
  eds_->calculate_k_nearest_nodes_using_point(  );
}


TEST_F( EDSTest, testCalculateKNearestNodesUsingDGNode ) {
  assert( eds_ != NULL );
  eds_->construct_deformation_graph(  );
  eds_->calculate_k_nearest_nodes_using_dgnode(  );
}


TEST_F( EDSTest, testCalculate_K_Nearest_Nodes ) {
  assert( eds_ != NULL );
  eds_->construct_deformation_graph(  );
  eds_->calculate_k_nearest_nodes(  );
}


#endif /* _TESTEDS_H_ */

/* testEDS.h ends here */
