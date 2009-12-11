#include "main_window.h"
#include <QToolBar>
#include <QtGui>
#include <QApplication>
#include "QOutputLogger.hpp"

void MainWindow::setupMenu()
{
   mainMenuBar = new QMenuBar(this);
   fileMenu = new QMenu(tr("&File"),mainMenuBar);
   newAction = new QAction(tr("&New"),fileMenu);
   connect(newAction,SIGNAL(triggered()),this,SLOT(fileNew()));
   fileMenu->addAction(newAction);
   
   openAction = new QAction(tr("&Open"),fileMenu);
   connect(openAction,SIGNAL(triggered()),this,SLOT(fileOpen()));
   fileMenu->addAction(openAction);
   
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
   actViewSolid = new QAction(tr("&Solid"),viewMenu);
   connect(actViewSolid,SIGNAL(triggered()),this,SLOT(viewSolid()));
   viewMenu->addAction(actViewSolid);
   mainMenuBar->addMenu(viewMenu);

   helpMenu = new QMenu(tr("&Help"),mainMenuBar);
   aboutAction = new QAction(tr("&About"),helpMenu);
   connect(aboutAction,SIGNAL(triggered()),this,SLOT(helpAbout()));
   helpMenu->addAction(aboutAction);
   mainMenuBar->addMenu(helpMenu);

   infoMenu = new QMenu(tr("Info"),mainMenuBar);
   actInfoBoundingBox = new QAction(tr("BoundingBox"),infoMenu);
   connect(actInfoBoundingBox,SIGNAL(triggered()),this,SLOT(infoPrintBoundingBox()));
   infoMenu->addAction(actInfoBoundingBox);
   mainMenuBar->addMenu(infoMenu);

   setMenuBar(mainMenuBar);
}

void MainWindow::setupToolBar()
{
  QToolBar * toolbar = new QToolBar(this);
  toolbar->addAction(newAction);
  toolbar->addAction(openAction);
  toolbar->addAction(aboutAction);
  addToolBar(toolbar);
}

void MainWindow::setupLogger()
{
	QOutputLogger::logger = new QOutputLogger(QString(tr("Logger")),this);
	QOutputLogger::getInstance()->setAllowedAreas(Qt::BottomDockWidgetArea);
	addDockWidget(Qt::BottomDockWidgetArea,QOutputLogger::getInstance());
	QOutputLogger::getInstance()->setVisible(false);
}

void MainWindow::fileNew()
{
}

void MainWindow::fileOpen()
{
	QString filename = QFileDialog::getOpenFileName(this,
		QString(tr("Open File")),
		QString(tr("../*.*")),
		QString(tr("Mesh files(*.off,*.obj,*.ply)"))
		);
	mainWidget->GetAppData()->loadMesh(filename);
}

void MainWindow::fileSaveImage()
{
	QString filename = QFileDialog::getSaveFileName(this,
		QString(QObject::tr("Save File")),
		QString(QObject::tr("../result.png")),
		QString(QObject::tr("Images (*.png)"))
		);
	mainWidget->saveImage(filename);
}

void MainWindow::fileExit()
{
  qApp->exit();
}

void MainWindow::helpAbout()
{
  qApp->aboutQt();
}

void MainWindow::viewLog()
{
	if(QOutputLogger::getInstance()->isVisible()){
		QOutputLogger::getInstance()->setVisible(false);
	}
	else{
		QOutputLogger::getInstance()->setVisible(true);
	}
}

void MainWindow::viewWireFrame()
{
	if(mainWidget)
	  {
	    mainWidget->setPolygonMode(PM_WIREFRAME);
	  }
}

void MainWindow::viewSolid()
{
	if(mainWidget)
		mainWidget->setPolygonMode(PM_SOLID);
}


void MainWindow::infoPrintBoundingBox()
{
	if(mainWidget){
		mainWidget->GetAppData()->printBoundingBox();
	}

}