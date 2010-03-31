#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBox>
#include <QToolBar>
#include <QMenu>


class MainWindow : public QMainWindow{
 public:
  MainWindow(QWidget* parent = 0, Qt::WindowFlags flag = 0)
    : QMainWindow(parent,flag)
    {
      setupMenu();
      setupToolbar();
      setupToolbox();
    }
  ~MainWindow()
    {}
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
