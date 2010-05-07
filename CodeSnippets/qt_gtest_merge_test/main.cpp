// main.cpp --- 
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
#include <QApplication>
#include "TestWidget.h"

int main(int argc, char *argv[])
{
  QApplication app( argc,argv );

  TestWidget* widget = new TestWidget(  );
  widget->show(  );
  
  return app.exec(  );
}

//  
// 
// main.cpp ends here
