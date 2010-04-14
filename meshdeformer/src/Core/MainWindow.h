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

#include "Viewer.h"
#include "Model.h"


class ConsoleWidgetManager;
class StatusBar;

#include "../TestPlugin.h"

/**
   MainWindow:
   @brief: The MainWindow of the application
   @detail: this class should be seen as a Controller class
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
      setupConsoleWidget();
      setupStatusBar( );
      
      mainModel_ = new Model();
      mainViewer_ = new Viewer(mainModel_,this,NULL,flags);

      //TODO: add Layout and splitter support to suppport multiviewer
      setCentralWidget(mainViewer_);


      testPlugin = new TestPlugin();

      connect(testPlugin,SIGNAL(log(const QString&)),this,SLOT(slotLog(const QString&)));
      connect( testPlugin,SIGNAL( updateStatusBarMessage( const QString& ) ), this, SLOT( slotUpdateStatusBarMessage( const QString& ) ) );

      testPlugin->callTest();
    }
  ~MainWindow()
    {
      delete mainModel_;
      delete mainViewer_;
    }
  
 private:
  void setupMenu();
  void setupToolBar();
  void setupConsoleWidget();
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

  void slotChangeViewerBackgroundColor(  );

private:
  void setupStatusBar( );
private slots:
  void slotUpdateStatusBarMessage( const QString& message );
  
  //LoggingInterface
public slots:
  void slotLog(const QString& message);
 private:
  //The main displaying widget
  Viewer * mainViewer_;
  Model* mainModel_;



 private://UI related
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

  //QGLViewer menu for options settings
  QMenu* qglViewerMenu_;
  QAction* actQGLViewerSetBackgroundColor_;
  
  
  //Help Menu
  QMenu * helpMenu;  
  QAction * aboutAction;
  //Info Menu(some extra and tmp debug message)
  QMenu * infoMenu;
  QAction* actInfoBoundingBox;
  QAction* actInfoShowDebugInfo;
  QAction* actInfoToggleRunningMode;
  
  ConsoleWidgetManager* consoleWidgetManager;
  StatusBar* statusBar_;

  TestPlugin* testPlugin;
};


#endif
