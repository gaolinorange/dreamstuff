#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include "main_widget.h"


class QOutputLogger;

class MainWindow : public QMainWindow
{
  Q_OBJECT
 public:
  MainWindow(QWidget * parent = 0,Qt::WindowFlags flags = 0)
    : QMainWindow(parent,flags)
    {
      setupMenu();
      setupToolBar();
      setupLogger();
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
  void setupLogger();
 protected:

  private slots:
  void fileNew();
  void fileOpen();
  void fileSaveImage();
  void fileExit();
  void viewLog();
  void viewWireFrame();
  void viewSolid();
  void helpAbout();
 private:
  MainWidget * mainWidget;

  QMenuBar * mainMenuBar;
  QMenu * fileMenu;
  QMenu * viewMenu;
  QMenu * helpMenu;

  QAction * newAction;
  QAction * openAction;
  QAction* actSaveImage;
  QAction * exitAction;

  QAction* actViewLog;
  QAction* actViewWireframe;
  QAction* actViewSolid;
  
  QAction * aboutAction;

  QOutputLogger* logger;
};


#endif
