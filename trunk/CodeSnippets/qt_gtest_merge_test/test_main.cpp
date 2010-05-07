// test_main.cpp --- 
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
#include <gtest/gtest.h>
#include "testTestWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app( argc,argv );
  
  ::testing::InitGoogleTest( &argc,argv );

  
  return RUN_ALL_TESTS(  );
}

//  
// 
// test_main.cpp ends here
