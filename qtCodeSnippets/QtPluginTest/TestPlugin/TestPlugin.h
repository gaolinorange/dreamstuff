#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include "TestInterface.h"
#include <QObject>
#include <QtPlugin>

class TestPlugin : public QObject,public TestInterface{
  Q_OBJECT
    Q_INTERFACES(TestInterface)
public:
  TestPlugin(){}
  virtual ~TestPlugin(){}  
public:
  QString name() const
  {
    return QString("TestPlugin");
  }
  
};



#endif
