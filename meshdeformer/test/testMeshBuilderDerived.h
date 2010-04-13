// testMeshBuilderDerived.h --- Test How to Derived an existing test case
// to simplify the testing procedure

// copyright (c) 2010 dreamway
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free Software Foundation;
//  Free free to contact dreamway(jingwenlai@163.com)
// 
// website: cg.xplore.cn
// 
// 

// Commentary: 
// 
// 

#ifndef _TESTMESHBUILDERDERIVED_H_
#define _TESTMESHBUILDERDERIVED_H_

#include "testMeshBuilder.h"

/**
   Test wheather I can use the MeshBuilder loading method to
   investigate further functions
 */
class DerivedMeshBuilderTest : public MeshBuilderTest {
  virtual void SetUp( ){
    this->MeshBuilderTest::SetUp(  );
  }

  virtual void TearDown(  ) {
    this->MeshBuilderTest::TearDown( );
  }
};

TEST_F( DerivedMeshBuilderTest, testInit ) {
  /* no need to do things*/
}


#endif /* _TESTMESHBUILDERDERIVED_H_ */

// 
// testMeshBuilderDerived.h ends here
