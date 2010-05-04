#include <QApplication>
#include <QDir>
#include <QPluginLoader>
#include <QPushButton>
#include <QObject>
#include <QtDebug>

#include "TestInterface.h"
#include "TestClass.h"


int main(int argc,char** argv)
{
  QApplication* app = new QApplication(argc,argv);

  TestInterface* interface = 0;

  TestClass* testClass = new TestClass(  );
  
  
  //Load plugins
  QDir pluginsDir(qApp->applicationDirPath());
  pluginsDir.cd("TestPlugin");
  
  foreach(QString fileName,pluginsDir.entryList(QDir::Files)){
    QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
    QObject* plugin = pluginLoader.instance();
    if(plugin){
      interface = qobject_cast<TestInterface*>(plugin);
     
      if(interface){
        printf("plugin load ok\n");
        bool connected = QObject::connect( plugin, SIGNAL( test_signal( const QString& ) ), testClass, SLOT( test_slot( const QString& ) ) );

        printf( "connected? %d\n",connected );

        interface->initializePlugin(  );
      }
      else {
        printf("plugin not load.\n");
      }
    }    
  }

 

  return app->exec();
}
