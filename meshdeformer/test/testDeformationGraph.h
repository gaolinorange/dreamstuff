/* testDeformationGraph.h --- 
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
#ifndef _TESTDEFORMATIONGRAPH_H_
#define _TESTDEFORMATIONGRAPH_H_

#include <gtest/gtest.h>
#include "../Plugin-EDS/DeformationGraph.h"
#include "testMeshCore.h"


class DeformationGraphTest : public MeshCoreTest
 {
  protected:
   virtual void SetUp(  ) {
     MeshCoreTest::SetUp(  );
     deformation_graph_ = new DeformationGraph(  );
     setupTheTestData(  );
   }
   virtual void TearDown(  ) {
     delete deformation_graph_;
     MeshCoreTest::TearDown(  );
   }
   DeformationGraph* deformation_graph_;
private:
   void setupTheTestData(  ) {
     DeformationGraphNode node1;
     node1.set_id( 0 );
     node1.position_[ 0 ] = node1.position_[ 1 ] = node1.position_[ 2 ] = 0.0;
     node1.insert_neighbor_node( 1 );
     node1.set_parent_deformation_graph( deformation_graph_ );
     deformation_graph_->nodes_.push_back( node1 );

     DeformationGraphNode node2( 1 );
     node2.position_[ 0 ] = node2.position_[ 1 ] = 0.0;
     node2.position_[ 2 ] = 1.0f;
     node2.insert_neighbor_node( 0 );
     node2.set_parent_deformation_graph( deformation_graph_ );
     deformation_graph_->nodes_.push_back( node2 );


     DeformationGraphNode node3( 2 );
     node3.position_[ 0 ] = 0.0;
     node3.position_[ 1 ] = 1.0;
     node3.position_[ 2 ] = 0.0;
     node3.insert_neighbor_node( 0 );
     node3.insert_neighbor_node( 1 );
     node3.set_parent_deformation_graph( deformation_graph_ );
     deformation_graph_->nodes_.push_back( node3 );     
   }
 };

TEST_F( DeformationGraphTest, testInit ) {
  //no need to do things  
}

TEST_F( DeformationGraphTest, testConstruct ) {
  assert( deformation_graph_ != NULL );
  deformation_graph_->construct( pMesh, 4 )  ;
}

TEST_F( DeformationGraphTest, printNodes ) {
  vector<DeformationGraphNode>::iterator pNode;
  for( pNode = deformation_graph_->nodes_.begin(  );
       pNode != deformation_graph_->nodes_.end(  ); pNode++ ) {
    pNode->print(  );
    printf( "\n" );
  }
}

TEST_F( DeformationGraphTest, testRenderConnection ) {
  vector<DeformationGraphNode>::iterator pNode;
  for (pNode = deformation_graph_->nodes_.begin(  );
       pNode != deformation_graph_->nodes_.end(); ++pNode) {
    pNode->renderConnection(  );    
  }
}


#endif /* _TESTDEFORMATIONGRAPH_H_ */
/* testDeformationGraph.h ends here */




