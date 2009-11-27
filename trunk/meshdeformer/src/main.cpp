#include <QApplication>
#include "main_window.h"
#include <gtest/gtest.h>
#include "Common/globals.hpp"

#include "test/test.h" //the test cases


int main(int argc,char ** argv)
{
  QApplication app(argc,argv);

  MainWindow * mainWindow = new MainWindow();
  mainWindow->resize(800,600);
  mainWindow->show();

  ::testing::InitGoogleTest(&argc,argv);
  RUN_ALL_TESTS();
  
  return app.exec();
}
