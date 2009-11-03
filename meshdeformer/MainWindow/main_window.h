#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include "main_widget.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT
 public:
  MainWindow(QWidget * parent = 0,Qt::WindowFlags flags = 0)
    : QMainWindow(parent,flags)
    {
      setupMenu();
      setupToolBar();
       mainWidget = new MainWidget(this,NULL,flags);
        setCentralWidget(mainWidget);
    }
  ~MainWindow()
    {
      delete mainWidget;
    }
 private:
  void setupMenu();
  void setupToolBar();
 protected:

  private slots:
  void fileNew();
  void fileOpen();
  void fileExit();
  void helpAbout();
 private:
  MainWidget * mainWidget;

  QMenuBar * mainMenuBar;
  QMenu * fileMenu;
  QMenu * helpMenu;
  QAction * newAction;
  QAction * openAction;
  QAction * exitAction;
  
  QAction * aboutAction;
};


#endif
