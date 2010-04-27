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
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QtDebug>

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
    layout_ = new QVBoxLayout( test_widget_ );
    button_ = new QPushButton( tr( "TestButton One") );
    label_ = new QLabel( tr( "Test Label" ) );
    checkbox_ = new QCheckBox( tr( "Test Checkbox" ) );
    layout_->addWidget( button_ );
    layout_->addWidget( label_ );
    layout_->addWidget( checkbox_ );
    test_widget_->setLayout( layout_ );    
  }
  ~TestPlugin(  ) {
    delete test_widget_;
    delete button_;
    delete label_;
    delete checkbox_;
    delete layout_;    
  }
  
 private:
  QPushButton* button_;
  QLabel* label_;
  QCheckBox* checkbox_;
  QVBoxLayout* layout_;

  QWidget* test_widget_;

public slots:
  //BaseInterface
  void pluginInitialized(  ) {
    emit log( QString( "test string from TestPlugin log signal" ) );
    emit updateStatusBarMessage( QString( "test string from TestPlugin updateStatusBarMessage" ) );
    printf( "emit a signal : addToolBox   from TestPlugin\n");
    qDebug( )<<"meta info of test_widget_: "<<test_widget_->metaObject(  )->className(  );
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


};

#endif /* _TESTPLUGIN_H_ */
//  
// 
// TestPlugin.h ends here
