#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QGLWidget>
#include <QtGui>
#include "app_data.h"
#include <QGLViewer/qglviewer.h>


enum PolygonMode{
	PM_WIREFRAME=0,
	PM_SOLID,
	PM_POINT
};

//class MainWidget : public QGLWidget
class MainWidget : public QGLViewer
{
  Q_OBJECT
public:
  MainWidget(QWidget * parent = 0,const QGLWidget * shareWidget = 0,Qt::WindowFlags flags = 0)
    //   : QGLWidget(parent,shareWidget,flags)
    : QGLViewer(parent,shareWidget,flags)
   {
      pData =  new AppData();
      polygonMode = PM_WIREFRAME;
      pCamera = new qglviewer::Camera();
  }
  ~MainWidget()
    {
      if(pData)
	{
	  delete pData; pData = 0;
	}
      if(pCamera){
	delete pCamera; pCamera = 0;
      }
  }
public:
	void saveImage(const QString& filename);
 protected:
  void initializeGL();
  void resizeGL(int w,int h);
  void updateGL();
  void paintGL();
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
 public:
	void printDebugInfo();
 private:
  AppData * pData;
  qglviewer::Camera* pCamera;
  PolygonMode polygonMode;
};

#endif
