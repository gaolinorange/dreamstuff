/**
   Mesh Deformer
   An experimental environment for mesh deformation
   @authro: jingwenlai@163.com
   @website: blog.csdn.net/jingwenlai_scut
 */

#ifndef MESHDEFORMER_MAINWINDOW_H
#define MESHDEFORMER_MAINWINDOW_H

#include <QtGui>

#include "Viewer.h"
#include "Model.h"


class ConsoleWidgetManager;
class StatusBar;

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
      setupToolBox(  );
      
      mainModel_ = new Model();
      mainViewer_ = new Viewer(mainModel_,this,NULL,flags);

      setupMainLayout(  );
      
      setCentralWidget(mainLayout_);

      loadPlugins(  );
    }
  ~MainWindow()
    {
      delete mainModel_;
      delete mainViewer_;
      delete mainLayout_;
      delete toolbox_;
    }
  
 private:
  void setupMainLayout(  );
  void setupMenu();
  void setupToolBar();
  void setupStatusBar( );
  void setupConsoleWidget();
  void setupToolBox(  );

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

  //Plugin Management
public:
  void loadPlugins(  );

  //For BaseInterface
signals:
  void pluginsInitialized(  );
  
private slots:
  //StatusBarInterface
  void slotUpdateStatusBarMessage( const QString& message );
  //LoggingInterface
  void slotLog(const QString& message);
  //ToolBoxInterface
  void slotAddToolBox( QString, QWidget* );

  
 private:
  //The main displaying widget
  Viewer * mainViewer_;
  Model* mainModel_;



 private://UI related
  QHBoxLayout* mainLayout_;
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

  QToolBox* toolbox_;
};


#endif
