#include <QCoreApplication>

#include "TestClass.h"
#include "MainClass.h"



int main(int argc,char** argv)
{
  QCoreApplication app(argc,argv);

  MainClass* mainClass = new MainClass();
  TestClass* testClass = new TestClass();

  QObject::connect(testClass,SIGNAL(log(const QString&)),mainClass,SLOT(slotLog(const QString&)));

  testClass->call_test();

  return app.exec();
}


  
  
