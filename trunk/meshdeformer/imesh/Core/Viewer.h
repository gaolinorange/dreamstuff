/**
   Mesh Deformer
   An experimental environment for mesh deformation
   @author: jingwenlai@163.com
   @website: blog.csdn.net/jingwenlai_scut
*/

#ifndef MESHDEFORMER_MAINWIDGET_H
#define MESHDEFORMER_MAINWIDGET_H

#include <QGLWidget>
#include <QObject>


#include "MeshCore/MeshCore.h"
#include "MeshCore/MeshBuilder.h"
#include "MeshCore/MeshLoader.h"
#include "BasePlugin/LoggingInterface.h"

//#include "widgets/consoleWidgets/ConsoleWidgetManager.h"

#include <QGLViewer/qglviewer.h>


enum PolygonMode{
	PM_WIREFRAME=0x01,
	PM_SOLID_FLAT=0x02,
	PM_SOLID_SMOOTH=0x04,
	
	PM_POINT=0x08
};

/**
   Viewer: MainWidget for displaying
   @brief: The Main displaying widget for displaying OpenGL Views
   @details: inherite the QGLViewer, a part of libQGLViewer library,
   to make the creation of Rendering more easy
*/
class Viewer : public QGLViewer,
               public LoggingInterface
{
  Q_OBJECT
  Q_INTERFACES( LoggingInterface )
    
public:
  Viewer(QWidget * parent = 0,const QGLWidget * shareWidget = 0,Qt::WindowFlags flags = 0)
    : QGLViewer(parent,shareWidget,flags)
  {
    mesh_ = 0;
    polygonMode = PM_WIREFRAME;
    pCamera = new qglviewer::Camera();
  }
  ~Viewer()
  {
    if(pCamera){
      delete pCamera; pCamera = 0;
    }
    if( mesh_ ) {
      delete mesh_; mesh_ = 0;
    }
  }


  //LoggingInterface
 signals:
  void log( const QString&  );
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
  MeshCore* mesh(  ) {
    return mesh_;
  }  
public:
	void printDebugInfo();
private:
  //  MeshModel * pMeshModel;
  MeshCore* mesh_;
  
  qglviewer::Camera* pCamera;
  PolygonMode polygonMode;
};

#endif
