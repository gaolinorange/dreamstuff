#ifndef PYTHONCONSOLEWIDGET_H
#define PYTHONCONSOLEWIDGET_H

#include "PythonQt.h"
#include "gui/PythonQtScriptingConsole.h"
#include <QWidget>
#include "../AbstractConsoleWidget.h"

class PythonConsoleWidget : public PythonQtScriptingConsole,public AbstractConsoleWidget
{
  Q_OBJECT
 public:
  PythonConsoleWidget(QWidget* parent,const PythonQtObjectPtr& context);
  ~PythonConsoleWidget();
 public:
  QString name() const
  {
    return QString("PythonConsoleWidget");
  }
};

#endif
