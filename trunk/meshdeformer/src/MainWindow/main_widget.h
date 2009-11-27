#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QGLWidget>
#include <QtGui>
#include "app_data.h"

class CViewport;
class CCamera;
class CArcball;
//#include "Viewport.hpp"

class MainWidget : public QGLWidget
{
  Q_OBJECT
public:
  MainWidget(QWidget * parent = 0,const QGLWidget * shareWidget = 0,Qt::WindowFlags flags = 0)
    : QGLWidget(parent,shareWidget,flags)
    {
      pData =  new AppData();
	  m_pArcball = 0;
	  m_pCamera = 0;
	  m_pViewport = 0;
  }
  ~MainWidget()
    {
      if(pData)
	{
	  delete pData; pData = 0;
	}
	  if(m_pViewport)
		  delete m_pViewport;
	  m_pViewport = 0;
	  if(m_pCamera)
		  delete m_pCamera;
	  m_pCamera = 0;
	  if(m_pArcball)
		  delete m_pArcball;
	  m_pArcball = 0;
  }
 protected:
  void initializeGL();
  void resizeGL(int w,int h);
  void updateGL();
  void paintGL();

//  void wheelEvent(QWheelEvent* event);
  void mousePressEvent(QMouseEvent * event);
  void mouseReleaseEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent* event);
//  void mouseDoubleClickEvent(QMouseEvent * event);
  
 private:
  void draw();
  void testDrawCube();

 private:
  AppData * pData;

  CArcball* m_pArcball;
  CViewport* m_pViewport;
  CCamera* m_pCamera;
  bool bArcballIsDragging;
};

#endif
