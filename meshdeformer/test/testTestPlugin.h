// testTestPlugin.h --- Test for Testing TestPlugin
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
//
#ifndef _TESTTESTPLUGIN_H_
#define _TESTTESTPLUGIN_H_

#include <gtest/gtest.h>

class TestPluginTest : public ::testing::Test {
 protected:
  virtual void SetUp(  ) {
    
  }
  virtual void TearDown(  ) {
    
  }
  
};


TEST_F( TestPluginTest, testInit ) {
  //no need to do things
}


#endif /* _TESTTESTPLUGIN_H_ */
// 
// testTestPlugin.h ends here
