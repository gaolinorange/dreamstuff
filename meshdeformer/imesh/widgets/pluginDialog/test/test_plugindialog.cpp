// test_plugindialog.cpp --- 
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
#include "PluginDialog.h"

int main(int argc, char *argv[])
{
  QApplication app( argc,argv );

  PluginDialog plugin_dialog;
  plugin_dialog.exec(  );
  
  return app.exec(  );
}

//  
// 
// test_plugindialog.cpp ends here
