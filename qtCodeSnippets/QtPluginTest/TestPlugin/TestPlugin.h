#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include "TestInterface.h"
#include <QObject>
#include <QtPlugin>

#include <stdio.h>


class TestPlugin : public QObject,public TestInterface{
  Q_OBJECT
    Q_INTERFACES(TestInterface)
public:
  TestPlugin() {
  }
  virtual ~TestPlugin(){}
public:
  void initializePlugin(  ) {
    printf( "TestPlugin constrctor, emit test_signal...\n" );
    emit test_signal( QString( "emit from test_plugin" ) );
  }

  

signals:
  void test_signal( const QString& );
public:
  void test_method( ) {
    printf( "Test method of Test Plugin\n" );
  }
public:
  QString name() const
  {
    return QString("TestPlugin");
  }
  
};



#endif
