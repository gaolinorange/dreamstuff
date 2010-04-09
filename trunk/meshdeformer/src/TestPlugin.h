#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include <QtDebug>
#include <QObject>

#include "BasePlugin/LoggingInterface.h"
#include "BasePlugin/StatusBarInterface.h"

class TestPlugin : public QObject,
  public LoggingInterface,
  public StatusBarInterface
{
  Q_OBJECT
      Q_INTERFACES(LoggingInterface)
      Q_INTERFACES( StatusBarInterface )
    
 public:
  TestPlugin(){}
  ~TestPlugin(){}
 public:
  void callTest()
  {
    emit log(QString("callTest from TestPlugin"));
    emit updateStatusBarMessage( QString( "test update status bar message from Test Plugin" ) );
  }
 signals:
  void log(const QString& logMessage);
  void updateStatusBarMessage( const QString& message );
 public:
  QString description() const
  {
    return QString("TestPlugin");
  }
};



#endif
