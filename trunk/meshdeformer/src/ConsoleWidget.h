/**
   MeshDeformer
   An experimental environment for mesh deformation
   author: jingwenlai@163.com
   links: blog.csdn.net/jingwenlai_scut
 */

#ifndef MESHDEFORMER_COMMON_CONSOLEWIDGET_H
#define MESHDEFORMER_COMMON_CONSOLEWIDGET_H

#include <QListWidget>
#include <QDockWidget>
#include "LoggerWidget.h"
#include "PythonConsoleWidget.h"

/**
   ConsoleWidget
   @brief:
   A widget for displaying Logging messages and showing Python Console
   @details: an singleton instance of logger
 */

class ConsoleWidget : public QDockWidget
{
public:
  static ConsoleWidget* getInstance()
  {
	  Q_ASSERT(consoleWidget!= NULL);
	  return consoleWidget;
  }
public:
  static ConsoleWidget* consoleWidget;
private:
  QTabWidget* tabWidget;
  LoggerWidget* loggerWidget;
  PythonConsoleWidget* pythonConsoleWidget;
    
public:
  ConsoleWidget(QWidget * parent = 0)
    : QDockWidget(QString(tr("App Console")),parent)
  {
    tabWidget = new QTabWidget(this);
    loggerWidget = new LoggerWidget(tabWidget);
    tabWidget->addTab(loggerWidget,QString(tr("Logger")));

    setupPythonConsole();
        
    setWidget(tabWidget);
  }
  ~ConsoleWidget()
  {
    delete loggerWidget;
    delete pythonConsoleWidget;
    delete tabWidget;
  }
 private:
  void setupPythonConsole()
  {
    PythonQt::init(PythonQt::IgnoreSiteModule | PythonQt::RedirectStdOut);

    PythonQtObjectPtr mainContext = PythonQt::self()->getMainModule();
    pythonConsoleWidget = new PythonConsoleWidget(tabWidget,mainContext);

    tabWidget->addTab(pythonConsoleWidget,QString(tr("Python Console")));
  }
public:
  /**
     logMessage:
     @param: message, the message append to the logger
   */
  void logMessage(const QString& message)
  {
    loggerWidget->appendMessage(message);
  }
};



#endif /* MESHDEFORMER_COMMON_QOUTPUTLOGGER_H */

