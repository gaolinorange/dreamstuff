/**
   Mesh Deformer
   An experimental environment for mesh deformation
   @authro: jingwenlai@163.com
   @website: blog.csdn.net/jingwenlai_scut
 */

#ifndef MESHDEFORMER_MAINWINDOW_H
#define MESHDEFORMER_MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include "main_widget.h"


class QOutputLogger;

/**
   MainWindow:
   @brief: The MainWindow of the application
 */
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
  //The main displaying widget
  MainWidget * mainWidget;

  QMenuBar * mainMenuBar;
  //File Menu
  QMenu * fileMenu;
  QAction * openAction;
  QAction * actSave;
  QAction* actSaveImage;
  QAction * exitAction;
  //View Menu
  QMenu * viewMenu;
  QAction* actViewLog;
  QAction* actViewWireframe;
  QAction* actViewSolidFlat;
  QAction* actViewSolidSmooth;
  //Help Menu
  QMenu * helpMenu;  
  QAction * aboutAction;
  //Info Menu(some extra and tmp debug message)
  QMenu * infoMenu;
  QAction* actInfoBoundingBox;
  QAction* actInfoShowDebugInfo;
  QAction* actInfoToggleRunningMode;
  
  QOutputLogger* logger;
};


#endif
