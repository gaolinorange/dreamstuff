#include "main_window.h"
#include <QToolBar>
#include <QApplication>
#include "QOutputLogger.hpp"

void MainWindow::setupMenu()
{
   mainMenuBar = new QMenuBar(this);
   fileMenu = new QMenu(tr("File"),mainMenuBar);
   newAction = new QAction(tr("&New"),fileMenu);
   connect(newAction,SIGNAL(triggered()),this,SLOT(fileNew()));
   fileMenu->addAction(newAction);
   
   openAction = new QAction(tr("&Open"),fileMenu);
   connect(openAction,SIGNAL(triggered()),this,SLOT(fileOpen()));
   fileMenu->addAction(openAction);
   
   fileMenu->addSeparator();

   exitAction = new QAction(tr("E&xit"),fileMenu);
   connect(exitAction,SIGNAL(triggered()),this,SLOT(fileExit()));
   fileMenu->addAction(exitAction);
   mainMenuBar->addMenu(fileMenu);

   viewMenu = new QMenu(tr("&View"),mainMenuBar);
   actViewLog = new QAction(tr("&Log"),viewMenu);
   connect(actViewLog,SIGNAL(triggered()),this,SLOT(viewLog()));
   viewMenu->addAction(actViewLog);
   mainMenuBar->addMenu(viewMenu);

   helpMenu = new QMenu(tr("Help"),mainMenuBar);
   aboutAction = new QAction(tr("&About"),helpMenu);
   connect(aboutAction,SIGNAL(triggered()),this,SLOT(helpAbout()));
   helpMenu->addAction(aboutAction);
   mainMenuBar->addMenu(helpMenu);

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