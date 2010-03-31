#include "MainWindow.h"
#include <QMenuBar>
#include <QLabel>
#include <QPushButton>


void MainWindow::setupMenu()
{
  QMenu* fileMenu = new QMenu(QString("File"));
  QAction* actOpen = new QAction(QString("Open"),fileMenu);
  fileMenu->addAction(actOpen);

  menuBar()->addMenu(fileMenu);
}

void MainWindow::setupToolbar()
{
  QToolBar* toolBar = new QToolBar(this);
  addToolBar(toolBar);
}

void MainWindow::setupToolbox()
{
  toolbox_ = new QToolBox(this);
  setCentralWidget(toolbox_);

  QPushButton* testButton1 = new QPushButton("Button1",toolbox_);
  toolbox_->addItem(testButton1,QString("TestButton1"));

  QPushButton* testButton2 = new QPushButton("Button2",toolbox_);
  toolbox_->addItem(testButton2,QString("TestButton2"));
  
}
