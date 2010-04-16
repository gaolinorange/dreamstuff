#include <QApplication>
#include "MainWindow.h"
#include <QMenuBar>
#include <QLabel>
#include <QPushButton>

#include <stdio.h>

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
}

/** slot for adding toolbox
 */
void MainWindow::slotAddToolBox( QString _name, QWidget* _widget ) {
  printf( "MainWindow:: slotAddToolBox...\n" );
  toolbox_->addItem(_widget, _name );
}

void MainWindow::loadPlugins(  ) {
    // load the plugins
  QDir pluginsDir( qApp->applicationDirPath(  ) );
  pluginsDir.cd( "plugins" );

  foreach( QString fileName, pluginsDir.entryList( QDir::Files ) ) {
    QPluginLoader pluginLoader( pluginsDir.absoluteFilePath( fileName ) );

    qDebug(  )<<"plugin filename: "<<fileName;
    
    QObject* plugin = pluginLoader.instance(  );
    if( plugin ) {
      printf( "Plugin is loaded.\n" );
      ToolBoxInterface* interface = qobject_cast<ToolBoxInterface*>( plugin );
      if( interface ) {
        qDebug(  )<<"plugin methoObject class name:"<<plugin->metaObject(  )->className(  );
        QObject::connect( plugin, SIGNAL( addToolBox( QString,QWidget* ) ),this, SLOT( slotAddToolBox( QString, QWidget* ) ) );
      }
    }
  }

}
