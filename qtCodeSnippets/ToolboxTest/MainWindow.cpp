#include <QApplication>
#include "MainWindow.h"
#include <QMenuBar>
#include <QLabel>
#include <QPushButton>

#include <stdio.h>
#include "ToolBoxInterface.h"

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

  QPushButton* button = new QPushButton( QString( "Button" ), toolbox_ );
  toolbox_->addItem( button, QString( "TestButton" ) );

  QLabel* label = new QLabel( QString( "Label" ), toolbox_ );
  toolbox_->addItem( label, QString( "TestLabel" ) );
}

/** slot for adding toolbox
 */
void MainWindow::slotAddToolBox( QString _name, QWidget* _widget ) {
  printf( "MainWindow slot:: slotAddToolBox...\n" );
  toolbox_->addItem(_widget, _name );
}

void MainWindow::slotTestSignal(  ) {
  printf( "slotTestSignal in MainWindow\n" );
}

void MainWindow::loadPlugins(  ) {

  // load the dynamic plugins
  QDir pluginsDir( qApp->applicationDirPath(  ) );
  pluginsDir.cd( "plugins" );

  foreach( QString fileName, pluginsDir.entryList( QDir::Files ) ) {
    QPluginLoader pluginLoader( pluginsDir.absoluteFilePath( fileName ) );

    qDebug(  )<<"plugin filename: "<<fileName;

    //load the plugin
    QObject* plugin = pluginLoader.instance(  );
    connect( this, SIGNAL( pluginsInitialized(  ) ),plugin,SLOT( pluginInitialized(  ) ) );
    
    if( plugin ) {
      printf( "second verify: is plugin loaded? %d\n", pluginLoader.isLoaded(  ) );
      printf( "Plugin is loaded.\n" );
      ToolBoxInterface* interface = qobject_cast<ToolBoxInterface*>( plugin );
      if( interface ) {
        qDebug(  )<<"plugin methoObject class name:"<<plugin->metaObject(  )->className(  );
        bool is_connected = connect( plugin, SIGNAL( addToolBox( QString,QWidget* ) ),this, SLOT( slotAddToolBox( QString, QWidget* ) ), Qt::DirectConnection );

        printf( "toolbox item count: %d\n", toolbox_->count(  ) );
      }
    }
  }

  emit pluginsInitialized(  );

  printf( "toolbox item count after calling pluginsInitialized: %d\n", toolbox_->count(  ) );
}



