#ifndef BASEPLUGIN_LOGGINGINTERFACE_H
#define BASEPLUGIN_LOGGINGINTERFACE_H

#include <QtPlugin>

class LoggingInterface{
 public:
  virtual ~LoggingInterface(){}
 signals:
  virtual void log(const QString& ) = 0;
};

Q_DECLARE_INTERFACE(LoggingInterface,"imesh.baseplugin.logginginterface");


#endif
