// TestPlugin.h --- This plugin used to test ToolboxInterface
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
#ifndef _TESTPLUGIN_H_
#define _TESTPLUGIN_H_

#include "ToolBoxInterface.h"
#include <stdio.h>
#include <QObject>
#include <QtPlugin>
#include <QWidget>
#include <QString>

class TestPlugin : public QObject, public ToolBoxInterface {
  Q_OBJECT
    Q_INTERFACES( ToolBoxInterface )
  public:
  TestPlugin(  ) {
    testWidget_ = new QWidget( );
    emit addToolBox( name(  ), testWidget_ );
  }
  virtual ~TestPlugin(  ) {
  }
public:
  void test_method(  ) {
    printf( "test_method from TestPlugin\n" );
  }
      
signals:
  void addToolBox( QString _name, QWidget* _widget);

public:
  QString name(  ) const {
    return QString( "TestPlugin" );
  }

  QWidget* testWidget_;
};

  
#endif /* _TESTPLUGIN_H_ */
//  
// 
// TestPlugin.h ends here
