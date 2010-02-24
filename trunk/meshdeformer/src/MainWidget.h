/**
   Mesh Deformer
   An experimental environment for mesh deformation
   @author: jingwenlai@163.com
   @website: blog.csdn.net/jingwenlai_scut
*/

#ifndef MESHDEFORMER_MAINWIDGET_H
#define MESHDEFORMER_MAINWIDGET_H

#include <QGLWidget>
#include <QtGui>
#include "AppData.h"
#include <QGLViewer/qglviewer.h>


enum PolygonMode{
	PM_WIREFRAME=0x01,
	PM_SOLID_FLAT=0x02,
	PM_SOLID_SMOOTH=0x04,
	
	PM_POINT=0x08
};

/**
   MainWidget
   @brief: The Main displaying widget for displaying OpenGL Views
   @details: inherite the QGLViewer, a part of libQGLViewer library,
   to make the creation of Rendering more easy
 */
class MainWidget : public QGLViewer
{
  Q_OBJECT
public:
  MainWidget(QWidget * parent = 0,const QGLWidget * shareWidget = 0,Qt::WindowFlags flags = 0)
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
  /**
     save the rendered view to an Image
   */
	void saveImage(const QString& filename);
	/**
	   load a mesh
	   @param: filename, the filename of the mesh
	   @detailed: currently, I use assimp library to load the mesh.
	 */
	void reloadMesh(QString& filename);
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
	/**
	   AppData is the model part of MVC design pattern
	 */
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
