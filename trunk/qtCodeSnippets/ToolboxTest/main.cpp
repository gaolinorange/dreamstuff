#include <QApplication>
#include <QDir>
#include <QPluginLoader>
#include <stdio.h>
#include <QtDebug>

#include "MainWindow.h"


int main(int argc,char** argv)
{
  QApplication app(argc,argv);

  MainWindow* mainWindow = new MainWindow(  );

  
  
  mainWindow->show(  );

  return app.exec();
}
