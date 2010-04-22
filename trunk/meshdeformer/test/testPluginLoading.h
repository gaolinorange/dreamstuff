// testPluginLoading.h --- Test for Testing TestPlugin
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
#ifndef _TESTPLUGINLOADING_H_
#define _TESTPLUGINLOADING_H_

#include <gtest/gtest.h>

#include "imesh/BasePlugin/BaseInterface.h"
#include "imesh/BasePlugin/LoggingInterface.h"
#include "imesh/BasePlugin/StatusBarInterface.h"

#include "imesh/Core/MainWindow.h"


class PluginLoadingTest : public ::testing::Test {
 protected:
  virtual void SetUp(  ) {    
    main_window_ = new MainWindow(  );
  }
  virtual void TearDown(  ) {
    delete main_window_;
  }

  MainWindow* main_window_;
};


TEST_F( PluginLoadingTest, testInit ) {
  //no need to do things
}

TEST_F( PluginLoadingTest, testPluginLoading ) {
  main_window_->loadPlugins(  );  
}

#endif /* _TESTPLUGINLOADING_H_ */

