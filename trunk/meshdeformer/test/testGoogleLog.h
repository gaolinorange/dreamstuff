// testGoogleLog.h --- A test file for testing Google glog initialization and logging
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
#ifndef _TESTGOOGLELOG_H_
#define _TESTGOOGLELOG_H_


#include <gtest/gtest.h>
#include <glog/logging.h>

class GoogleLogTest : public ::testing::Test
{
 public:
  GoogleLogTest() {
    
  }
  virtual ~GoogleLogTest() {
    
  }
 protected:

};

TEST_F( GoogleLogTest, testInit ) {
  //no need to do things
}

TEST_F( GoogleLogTest, testLogging ) {
  LOG( INFO )<<"A Info GoogleLog test message";
  LOG( ERROR )<<" An Error GoogleLog Test message. the number is "<<1;  
}

#endif /* _TESTGOOGLELOG_H_ */
//  
// 
// testGoogleLog.h ends here
