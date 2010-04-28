// test_dialog.cpp --- test the about dialog
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
//
#include <QApplication>
#include "AboutDialog.hpp"

int main(int argc, char *argv[])
{
  QApplication app( argc, argv );

  AboutDialog dlg;
  dlg.show(  );
  
  return app.exec(  );
}

// 
// test_dialog.cpp ends here
