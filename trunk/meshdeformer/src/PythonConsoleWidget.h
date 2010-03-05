#ifndef PYTHONCONSOLEWIDGET_H
#define PYTHONCONSOLEWIDGET_H

#include "PythonQt.h"
#include "gui/PythonQtScriptingConsole.h"
#include <QWidget>

class PythonConsoleWidget : public PythonQtScriptingConsole
{
 public:
  PythonConsoleWidget(QWidget* parent,const PythonQtObjectPtr& context);
  ~PythonConsoleWidget();
};

#endif
