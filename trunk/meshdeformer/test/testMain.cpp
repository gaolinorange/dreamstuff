#include <QApplication>
#include <gtest/gtest.h>
#include "test.h"

int main(int argc,char** argv)
{
  QApplication app( argc, argv );
  
  ::testing::InitGoogleTest(&argc,argv);

  RUN_ALL_TESTS();
  
  return app.exec(  );
}
