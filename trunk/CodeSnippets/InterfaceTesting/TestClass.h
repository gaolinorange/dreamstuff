#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QtDebug>
#include "TestInterface.h"
#include <QObject>

class TestClass : public QObject,public TestInterface{
  Q_OBJECT
 public:
  TestClass(){}
  ~TestClass(){}
 public:
  void call_test()
  {
    qDebug()<<"TestClass::call_test...";
    emit log(QString("call from TestClass"));
  }
  
 signals:
  void log(const QString& message);
};

#endif
