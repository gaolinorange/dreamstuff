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
#include <QtGui>

#include <stdio.h>

#include "BasePlugin/BaseInterface.h"
#include "BasePlugin/LoggingInterface.h"
#include "BasePlugin/StatusBarInterface.h"
#include "BasePlugin/ToolBoxInterface.h"

/**
   @brief: testing plugin architecture, a simple test plugin
*/

class TestPlugin : public QObject,
                   public BaseInterface,
                   public LoggingInterface,
                   public StatusBarInterface,
                   public ToolBoxInterface
{
  Q_OBJECT
  Q_INTERFACES( BaseInterface );
  Q_INTERFACES( LoggingInterface );
  Q_INTERFACES( StatusBarInterface );
  Q_INTERFACES( ToolBoxInterface )

 public:
  TestPlugin(  ) {
    test_widget_ = new QWidget(  );
    QVBoxLayout* layout = new QVBoxLayout( test_widget_ );
    QPushButton* button = new QPushButton( tr( "TestButton One") );
    QLabel* label = new QLabel( tr( "Test Label" ) );
    QCheckBox* checkbox = new QCheckBox( tr( "Test Checkbox" ) );
    layout->addWidget( button );
    layout->addWidget( label );
    layout->addWidget( checkbox );
    test_widget_->setLayout( layout );
  }
  ~TestPlugin(  ) {
    delete test_widget_;    
  }
  
 public:
  void callTest(  ) {
    emit log( "call_test from plugin: "+name(  ) );
    emit updateStatusBarMessage( QString( "message from testplugin" ) );
    emit addToolBox( QString( tr( "Testplugin toolbox" ) ), test_widget_ );
  }

public slots:
  //BaseInterface
  void pluginInitialized(  ) {
    printf( "TestPlugin initialized.\n" );
    emit log( QString( "test string from TestPlugin log signal" ) );
    emit updateStatusBarMessage( QString( "test string from TestPlugin updateStatusBarMessage" ) );
    emit addToolBox( QString( tr( "TestPlugin Toolbox" ) ),test_widget_ );
  }
  
 signals:
  //LoggingInterface
  void log( const QString& logMessage );
  //StatusBarInterface
  void updateStatusBarMessage( const QString& message );
  //ToolBoxInterface
  void addToolBox( QString, QWidget* );
 public:
  //BaseInterface 
  QString description(  ) const {
    return QString( "TestPlugin description" );
  }
  QString name(  ) const {
    return QString( "Test Plugin" );
  }

 private:
  QWidget* test_widget_;
};

#endif /* _TESTPLUGIN_H_ */
//  
// 
// TestPlugin.h ends here
