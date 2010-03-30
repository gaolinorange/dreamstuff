#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include <QtDebug>
#include <QObject>

#include "BasePlugins/LoggingInterface.h"

class TestPlugin : public QObject,public LoggingInterface{
  Q_OBJECT
    //   Q_INTERFACES(LoggingInterface)
    
 public:
  TestPlugin(){}
  ~TestPlugin(){}
 public:
  void callTest()
  {
    emit log(QString("callTest from TestPlugin"));
  }
 signals:
  void log(const QString& logMessage);
 public:
  QString description() const
  {
    return QString("TestPlugin");
  }
};



#endif
