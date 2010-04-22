#include <QApplication>
#include "Core/MainWindow.h"
#include "Common/globals.hpp"

bool RUNNING_AT_TEST_MODE = false;

int main(int argc,char ** argv)
{
  QApplication app(argc,argv);

  MainWindow * mainWindow = new MainWindow();
  mainWindow->resize(800,600);
  mainWindow->showMaximized();

  return app.exec();
}
