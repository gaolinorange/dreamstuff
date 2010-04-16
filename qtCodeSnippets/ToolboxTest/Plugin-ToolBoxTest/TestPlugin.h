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
#include "BaseInterface.h"

#include <stdio.h>
#include <QObject>
#include <QtPlugin>
#include <QWidget>
#include <QString>
#include <QPushButton>

class TestPlugin : public QObject,public BaseInterface, public ToolBoxInterface {
  Q_OBJECT
    Q_INTERFACES( ToolBoxInterface )
      Q_INTERFACES( BaseInterface )
      
  public:
  TestPlugin(  ) {
    testWidget_ = new QPushButton( );
    testWidget_->setText( QString( "TestPlugin widget" ) );    
  }
  
  virtual ~TestPlugin(  ) {
  }
 public slots:
  void initializePlugin(  ) {
    
  }
  
  void pluginInitialized(  ) {
    printf( "pluginInitialized: emitting addToolBox signal\n" );
    emit addToolBox( name(  ), testWidget_ );
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

  QPushButton* testWidget_;
};

  
#endif /* _TESTPLUGIN_H_ */
//  
// 
// TestPlugin.h ends here
