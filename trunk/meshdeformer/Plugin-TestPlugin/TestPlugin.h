// TestPlugin.h --- for testing plugin architecture
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

#include <QObject>
#include <stdio.h>

#include "BasePlugin/BaseInterface.h"
#include "BasePlugin/LoggingInterface.h"
#include "BasePlugin/StatusBarInterface.h"

class TestPlugin : public QObject,
                   public BaseInterface,
                   public LoggingInterface,
                   public StatusBarInterface {
  Q_OBJECT
  Q_INTERFACES( BaseInterface );
  Q_INTERFACES( LoggingInterface );
  Q_INTERFACES( StatusBarInterface );

 public:
  TestPlugin(  ) {
    
  }
  ~TestPlugin(  ) {
    
  }
 public:
  void callTest(  ) {
    emit log( "call_test from plugin: "+name(  ) );
    emit updateStatusBarMessage( QString( "message from testplugin" ) );
  }

public slots:
  //BaseInterface
  void pluginInitialized(  ) {
    printf( "TestPlugin initialized.\n" );
    emit log( QString( "test string from TestPlugin log signal" ) );
    emit updateStatusBarMessage( QString( "test string from TestPlugin updateStatusBarMessage" ) );    
  }
  
 signals:
  //LoggingInterface
  void log( const QString& logMessage );
  //StatusBarInterface
  void updateStatusBarMessage( const QString& message );

 public:
  //BaseInterface 
  QString description(  ) const {
    return QString( "TestPlugin description" );
  }
  QString name(  ) const {
    return QString( "Test Plugin" );
  }  
};

#endif /* _TESTPLUGIN_H_ */
//  
// 
// TestPlugin.h ends here
