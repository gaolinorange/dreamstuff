#include <QApplication>
#include "Core/MainWindow.h"

#include "Common/globals.hpp"

//Google logging library, see 3rdparty/glog_doc for documentation
#include <glog/logging.h>

bool RUNNING_AT_TEST_MODE = false;

int main(int argc,char ** argv)
{
  QApplication app(argc,argv);
  google::InitGoogleLogging( argv[ 0 ] );
  LOG( INFO ) <<"====== Begin Loggiing ======";

  MainWindow * mainWindow = new MainWindow();
  mainWindow->resize(800,600);
  //  mainWindow->showMaximized();
  mainWindow->show( );

  LOG( INFO ) <<"====== End Logging =======";
  return app.exec();
}
