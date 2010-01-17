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
  void fileOpen();
  void fileSave();
  void fileSaveImage();
  void fileExit();
  void viewLog();
  void viewWireFrame();
  void viewSolidFlat();
  void viewSolidSmooth();
  void helpAbout();
  void infoPrintBoundingBox();
  void infoShowDebugInfo();
  void infoToggleRunningMode();
 private:
  MainWidget * mainWidget;

  QMenuBar * mainMenuBar;
  QMenu * fileMenu;
  QMenu * viewMenu;
  QMenu * helpMenu;

  QAction * actSave;
  QAction * openAction;
  QAction* actSaveImage;
  QAction * exitAction;

  QAction* actViewLog;
  QAction* actViewWireframe;
  QAction* actViewSolidFlat;
  QAction* actViewSolidSmooth;
  
  QAction * aboutAction;

  QMenu * infoMenu;
  QAction* actInfoBoundingBox;
  QAction* actInfoShowDebugInfo;
  QAction* actInfoToggleRunningMode;
  
  QOutputLogger* logger;
};


#endif
