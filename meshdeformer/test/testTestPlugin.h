/* testTestPlugin.h --- Test case for TestPlugin
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
#ifndef _TESTTESTPLUGIN_H_
#define _TESTTESTPLUGIN_H_

#include <gtest/gtest.h>
#include "Plugin-TestPlugin/TestPlugin.h"


class TestPluginTest : public ::testing::Test
{
protected:
  virtual void SetUp(  ) {
    plugin = new TestPlugin(  );
  }
  virtual void TearDown(  ) {
    delete plugin;    
  }

  TestPlugin* plugin;
};

TEST_F( TestPluginTest, testInit ) {
  printf( "in TestPluginTest::testInit \n" )  ;

}

TEST_F( TestPluginTest, testGetDescription ) {
  //TODO
  printf( "TestPluginTest::testGetDescription \n" );
}

TEST_F( TestPluginTest, testGetName ) {
  //TODO
}



#endif /* _TESTTESTPLUGIN_H_ */
/* testTestPlugin.h ends here */
