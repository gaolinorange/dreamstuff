#include <QApplication>
#include "main_window.h"
#include <gtest/gtest.h>
//#include "MeshCore.h"

#include "test/test.h" //the test cases



int main(int argc,char ** argv)
{
  QApplication app(argc,argv);

  MainWindow * mainWindow = new MainWindow();
  mainWindow->resize(640,480);
  mainWindow->show();

//   MeshCore * pMesh = new MeshCore();
//   pMesh->make_tetrahedron();

  ::testing::InitGoogleTest(&argc,argv);
  RUN_ALL_TESTS();
  
  return app.exec();
}
