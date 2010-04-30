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
   }
   virtual void TearDown(  ) {
     delete deformation_graph_;
     MeshCoreTest::TearDown(  );
   }
   DeformationGraph* deformation_graph_;
 };

TEST_F( DeformationGraphTest, testInit ) {
  //no need to do things  
}

TEST_F( DeformationGraphTest, testConstruct ) {
  assert( deformation_graph_ != NULL );
  deformation_graph_->construct( pMesh, 4 )  ;
}



#endif /* _TESTDEFORMATIONGRAPH_H_ */
/* testDeformationGraph.h ends here */




