// MainWindow.cpp --- MainWindow of app and controls the workflow 
// copyright (c) 2010 dreamway
// 
//  This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free Software Foundation;
//  Free free to contact dreamway(jingwenlai@163.com)
// 
// website: cg.xplore.cn
// 
// 

// Commentary: 
// Be seen as the Controller of MVC Design Pattern
// 

#include "MainWindow.h"
#include <QToolBar>
#include <QtGui>
#include <QApplication>
#include <QtCore>
#include "widgets/consoleWidgets/ConsoleWidgetManager.h"
#include "globals.hpp"
#include "widgets/aboutDialog/AboutDialog.hpp"
#include "widgets/statusBar/StatusBar.h"

#include "BasePlugin/BaseInterface.h"
#include "BasePlugin/LoggingInterface.h"
#include "BasePlugin/StatusBarInterface.h"
#include "BasePlugin/ToolBoxInterface.h"


void MainWindow::setupMenu()
{
   mainMenuBar = new QMenuBar(this);
   fileMenu = new QMenu(tr("&File"),mainMenuBar);
   
   openAction = new QAction(tr("&Open"),fileMenu);
   connect(openAction,SIGNAL(triggered()),this,SLOT(fileOpen()));
   fileMenu->addAction(openAction);

   actSave = new QAction(tr("&Save"),fileMenu);
   connect(actSave,SIGNAL(triggered()),this,SLOT(fileSave()));
   fileMenu->addAction(actSave);

   
   actSaveImage = new QAction(tr("&Save Image"),fileMenu);
   actSaveImage->setShortcut(QKeySequence(tr("Ctrl+S")));
   connect(actSaveImage,SIGNAL(triggered()),this,SLOT(fileSaveImage()));
   fileMenu->addAction(actSaveImage);

   fileMenu->addSeparator();

   exitAction = new QAction(tr("E&xit"),fileMenu);
   connect(exitAction,SIGNAL(triggered()),this,SLOT(fileExit()));
   fileMenu->addAction(exitAction);
   mainMenuBar->addMenu(fileMenu);

   viewMenu = new QMenu(tr("&View"),mainMenuBar);
   actViewLog = new QAction(tr("&Log"),viewMenu);
   connect(actViewLog,SIGNAL(triggered()),this,SLOT(viewLog()));
   viewMenu->addAction(actViewLog);
   actViewWireframe = new QAction(tr("&WireFrame"),viewMenu);
   connect(actViewWireframe,SIGNAL(triggered()),this,SLOT(viewWireFrame()));
   viewMenu->addAction(actViewWireframe);

   actViewSolidFlat = new QAction(tr("&Solid Flat"),viewMenu);
   connect(actViewSolidFlat,SIGNAL(triggered()),this,SLOT(viewSolidFlat()));
   viewMenu->addAction(actViewSolidFlat);
   
   actViewSolidSmooth = new QAction(tr("&Solid Smooth"),viewMenu);
   connect(actViewSolidSmooth,SIGNAL(triggered()),this,SLOT(viewSolidSmooth()));
   viewMenu->addAction(actViewSolidSmooth);
   mainMenuBar->addMenu(viewMenu);

   /*
   qglViewerMenu_ = new QMenu( tr( "Viewer Settings" ), mainMenuBar );
   actQGLViewerSetBackgroundColor_ = new QAction( tr( "Set Background Color" ), qglViewerMenu_ );
   connect( actQGLViewerSetBackgroundColor_, SIGNAL( triggered(  ) ), this, SLOT( slotChangeViewerBackgroundColor(  ) ) );
   qglViewerMenu_->addAction( actQGLViewerSetBackgroundColor_ );

   mainMenuBar->addMenu( qglViewerMenu_ );
   */

   helpMenu = new QMenu(tr("&Help"),mainMenuBar);
   aboutAction = new QAction(tr("&About"),helpMenu);
   connect(aboutAction,SIGNAL(triggered()),this,SLOT(helpAbout()));
   helpMenu->addAction(aboutAction);
   mainMenuBar->addMenu(helpMenu);

   infoMenu = new QMenu(tr("Info"),mainMenuBar);
   actInfoBoundingBox = new QAction(tr("BoundingBox"),infoMenu);
   connect(actInfoBoundingBox,SIGNAL(triggered()),this,SLOT(infoPrintBoundingBox()));
   infoMenu->addAction(actInfoBoundingBox);
   actInfoShowDebugInfo = new QAction(tr("Debug Info"),infoMenu);
   connect(actInfoShowDebugInfo,SIGNAL(triggered()),this,SLOT(infoShowDebugInfo()));
   infoMenu->addAction(actInfoShowDebugInfo);
   actInfoToggleRunningMode = new QAction(tr("ToggleRunningMode"),infoMenu);
   connect(actInfoToggleRunningMode,SIGNAL(triggered()),this,SLOT(infoToggleRunningMode()));
   infoMenu->addAction(actInfoToggleRunningMode);
				      
   mainMenuBar->addMenu(infoMenu);

   setMenuBar(mainMenuBar);
}

void MainWindow::setupToolBar()
{
  QToolBar * toolbar = new QToolBar(this);
  toolbar->addAction(openAction);
  toolbar->addAction(aboutAction);
  addToolBar(toolbar);
}

void MainWindow::setupToolBox(  ) {
  toolbox_ = new QToolBox(  );
  QPushButton* button = new QPushButton(QString("Button"),toolbox_);
  toolbox_->addItem(button,QString("TestButton"));

  QLabel* label = new QLabel(QString("label"),toolbox_);
  toolbox_->addItem(label,QString("TestLabel"));
		    
}

void MainWindow::setupMainLayout(  ) {
  mainLayout_ = new QHBoxLayout(  );
  mainLayout_->addWidget( mainViewer_ );
  mainLayout_->addWidget( toolbox_ );
}
    

void MainWindow::setupConsoleWidget()
{
	consoleWidgetManager = new ConsoleWidgetManager(this);
	consoleWidgetManager->setAllowedAreas(Qt::BottomDockWidgetArea);
	addDockWidget(Qt::BottomDockWidgetArea,consoleWidgetManager);
	consoleWidgetManager->setVisible(false);
}

void MainWindow::fileSave()
{
  consoleWidgetManager->logMessage(QString(tr("Save mesh. TODO ")));
}

void MainWindow::fileOpen()
{
	QString filename = QFileDialog::getOpenFileName(this,
		QString(tr("Open File")),
		QString(tr(".")),
		QString(tr("Mesh files(*.off *.obj *.ply *)"))
		);
	mainViewer_->reloadMesh(filename);
}

void MainWindow::fileSaveImage()
{
	QString filename = QFileDialog::getSaveFileName(this,
		QString(QObject::tr("Save File")),
		QString(QObject::tr("../result.png")),
		QString(QObject::tr("Images (*.png)"))
		);
	mainViewer_->saveImage(filename);
}

void MainWindow::fileExit()
{
  qApp->exit();
}

void MainWindow::helpAbout()
{
  AboutDialog* aboutDialog = new AboutDialog(this);
  aboutDialog->exec();
}

void MainWindow::viewLog()
{
	if(consoleWidgetManager->isVisible()){
		consoleWidgetManager->setVisible(false);
	}
	else{
		consoleWidgetManager->setVisible(true);
	}
}

void MainWindow::viewWireFrame()
{
	if(mainViewer_)
	  {
	    mainViewer_->setPolygonMode(PM_WIREFRAME);
	  }
}

void MainWindow::viewSolidFlat()
{
	if(mainViewer_)
		mainViewer_->setPolygonMode(PM_SOLID_FLAT);
}

void MainWindow::viewSolidSmooth()
{
  if(mainViewer_)
    mainViewer_->setPolygonMode(PM_SOLID_SMOOTH);
}


void MainWindow::infoPrintBoundingBox()
{
	if(mainViewer_){
	  //		mainViewer_->getModel()->printBoundingBox();
	}

}

void MainWindow::infoShowDebugInfo()
{
  if(mainViewer_){
    mainViewer_->printDebugInfo();
  }
}

void MainWindow::infoToggleRunningMode()
{
  RUNNING_AT_TEST_MODE = !RUNNING_AT_TEST_MODE; 
}


void MainWindow::slotLog(const QString& message)
{
  consoleWidgetManager->logMessage(message);
}


void MainWindow::setupStatusBar( )
{
  statusBar_ = new StatusBar( this );
  setStatusBar( statusBar_ );  
}


//StatusBar slot messages
void MainWindow::slotUpdateStatusBarMessage( const QString& message ) {
  statusBar_->showMessage( message);  
}

void MainWindow::slotAddToolBox( QString title , QWidget* widget) {
  printf( "MainWindow::slotAddToolBox...\n" );
  
  widget->setParent(toolbox_);
  toolbox_->addItem( widget, title );
}


    
//Plugin Management
void MainWindow::loadPlugins(  ) {  
  //load the dynamic plugins
  QDir pluginsDir( qApp->applicationDirPath(  ) );
  pluginsDir.cd( "plugins" );

  foreach( QString fileName, pluginsDir.entryList( QDir::Files ) ) {
    QPluginLoader pluginLoader( pluginsDir.absoluteFilePath( fileName ) );
    qDebug(  )<< QString( "plugin filename: ")<<fileName ;

    qDebug( )<<"The pluginLoader's fileName: "<<pluginLoader.fileName(  );
    qDebug(  )<<"is loaded? "<<pluginLoader.load(  );
    
    //load the plugin
    QObject* plugin = pluginLoader.instance(  );
    if( plugin ) {
      //Plugin's baseInterface
      BaseInterface* baseInterface = qobject_cast<BaseInterface*>( plugin );
      if( baseInterface ) {
        //BaseInterface connection for pluginsInitialized
        qDebug( )<<"it's a BaseInterface, setup the connection";
        connect( this, SIGNAL( pluginsInitialized(  ) ),plugin, SLOT( pluginInitialized(  ) ) );        
      }
      
      //Plugin's LoggingInterface
      LoggingInterface* loggingInterface = qobject_cast<LoggingInterface*>( plugin );
      if( loggingInterface ) {
        qDebug( )<<"it's a LoggingInterface";
        qDebug(  )<<"plugin metaObject class name: "<<plugin->metaObject(  )->className(  );
        connect( plugin, SIGNAL( log( const QString& ) ), this, SLOT( slotLog( const QString& ) ) );        
      }

      //Plugin's StatusbarInterface
      StatusBarInterface* statusBarInterface = qobject_cast<StatusBarInterface*>( plugin );
      if( statusBarInterface ) {
        qDebug(  )<<"it's a StatusBarInterface";
        connect( plugin, SIGNAL( updateStatusBarMessage( const QString& ) ), this, SLOT( slotUpdateStatusBarMessage( const QString& ) ) );
      }

      //Plugins's ToolBoxInterface
      ToolBoxInterface* toolBoxInterface = qobject_cast<ToolBoxInterface*>( plugin );
      if( toolBoxInterface ) {
        qDebug(  )<<"it's a ToolBoxInterface, setup the connection";
        connect( plugin, SIGNAL( addToolBox( QString, QWidget* ) ), this, SLOT( slotAddToolBox( QString, QWidget* ) ) );
      }
    } else {
      qDebug(  )<<"could not instance this plugin: "<<fileName;
    }
  }


  //Emit a signal to setup all plugins
  emit pluginsInitialized(  );
}
