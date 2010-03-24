#include <QCoreApplication>
#include <QDir>
#include <QPluginLoader>
#include "TestPlugin.h"


int main(int argc,char** argv)
{
  QCoreApplication* app = new QCoreApplication(argc,argv);

  TestInterface* interface = 0;
  
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
      }
      else{
	printf("plugin not load.\n");
      }
    }    
  }


  return app->exec();
}
