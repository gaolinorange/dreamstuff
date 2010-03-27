#include "PythonConsoleWidget.h"

PythonConsoleWidget::PythonConsoleWidget(QWidget* parent,const PythonQtObjectPtr& context)
  : PythonQtScriptingConsole(parent,context)
{
}

PythonConsoleWidget::~PythonConsoleWidget()
{
}
