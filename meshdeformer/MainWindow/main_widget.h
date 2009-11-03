#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QGLWidget>
#include "app_data.h"

class MainWidget : public QGLWidget
{
  Q_OBJECT
public:
  MainWidget(QWidget * parent = 0,const QGLWidget * shareWidget = 0,Qt::WindowFlags flags = 0)
    : QGLWidget(parent,shareWidget,flags)
    {
      pData =  new AppData();
    }
  ~MainWidget()
    {
      if(pData)
	{
	  delete pData; pData = 0;
	}
    }
 protected:
  void initializeGL();
  void resizeGL(int w,int h);
  void updateGL();
  void paintGL();

  void mousePressEvent(QMouseEvent * event);
  void mouseMoveEvent(QMouseEvent* event);
  void mouseDoubleClickEvent(QMouseEvent * event);
  
 private:
  void draw();

 private:
  AppData * pData;
};

#endif
