#ifndef BASEPLUGINS_CONSOLEWIDGETINTERFACE_H
#define BASEPLUGINS_CONSOLEWIDGETINTERFACE_H

/**
 * /brief: Virtual class for adding widgets to the ConsoleWidgetContainer
 */
class AbstractConsoleWidget : public QObject{
 public:
  virtual ~AbstractConsoleWidget(){}
  virtual QString name() const = 0;  
};



#endif
