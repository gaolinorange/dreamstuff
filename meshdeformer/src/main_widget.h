#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QGLWidget>
#include <QtGui>
#include "app_data.h"

class CViewport;
class CCamera;
class CArcball;


enum PolygonMode{
	PM_WIREFRAME=0,
	PM_SOLID,
	PM_POINT
};

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
	  polygonMode = PM_WIREFRAME;
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
public:
	void saveImage(const QString& filename);
 protected:
  void initializeGL();
  void resizeGL(int w,int h);
  void updateGL();
  void paintGL();
  
//  void wheelEvent(QWheelEvent* event);

  void mousePressEvent(QMouseEvent * event);
  void mouseReleaseEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent* event);

  
protected:
  void draw();
  void testDrawCube();
public:
	void setPolygonMode(PolygonMode mode)
	{
		polygonMode = mode;
		updateGL();
	}
public:
	AppData* GetAppData()
	{
		return pData;
	}
 private:
  AppData * pData;

  CArcball* m_pArcball;
  CViewport* m_pViewport;
  CCamera* m_pCamera;

  bool bArcballIsDragging;
  PolygonMode polygonMode;
};

#endif
