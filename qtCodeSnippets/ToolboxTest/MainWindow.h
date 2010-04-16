#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBox>
#include <QToolBar>
#include <QMenu>

#include <QDir>
#include <QPluginLoader>
#include <stdio.h>
#include <QtDebug>

#include "ToolBoxInterface.h"


class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QWidget* parent = 0, Qt::WindowFlags flag = 0)
    : QMainWindow(parent,flag)
    {
      setupMenu();
      setupToolbar();
      setupToolbox();
      
      loadPlugins(  );
     }
  ~MainWindow()
    {}
 signals:
  void pluginsInitialized(  );
public slots:
  void slotAddToolBox( QString _name, QWidget* _widget );
  void slotTestSignal(  );
private:
  void testSlot(  );
 private:
  void loadPlugins(  );
 protected:
  void setupMenu();
  void setupToolbar();
  void setupToolbox();
 private:
  QToolBox* toolbox_;
  QMenu* menu_;
  QToolBar* toolbar_;
};

#endif
