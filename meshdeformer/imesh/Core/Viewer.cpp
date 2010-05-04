#include <glog/logging.h> //google log

#include <QtDebug>
#include <QtGui>
#include <iostream>
#include <QString>

#include "Common/globals.hpp"
#include "Viewer.h"


void Viewer::initializeGL()
{
  qglClearColor(Qt::black);
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  
  glDisable(GL_LIGHTING);


  pCamera->setPosition(qglviewer::Vec(0,0,-2));
  pCamera->setViewDirection(qglviewer::Vec(0,0,1));
  pCamera->setUpVector(qglviewer::Vec(0,1,0));
  setCamera(pCamera);
  
  setSceneRadius(1.0);
  setSceneCenter(qglviewer::Vec(0,0,0));
  camera()->showEntireScene();

  QGLViewer::initializeGL();
}

void Viewer::resizeGL(int w,int h)
{
  camera()->setAspectRatio(float(w)/h);
  camera()->setScreenWidthAndHeight(w,h);

  QGLViewer::resizeGL(w,h);
}

void Viewer::updateGL()
{
  paintGL();
  
  QGLViewer::updateGL();
}

void Viewer::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glDisable(GL_LIGHTING); //the lighting of QGLViewer may not you wanted.

  switch(polygonMode){
	  case PM_WIREFRAME:
		  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		  break;
	  case PM_SOLID_SMOOTH:
	    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	    glShadeModel(GL_SMOOTH);
	    break;
  case PM_SOLID_FLAT:
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);
    break;
	  case PM_POINT:
		  glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
		  break;
	  default:
		  break;  
  }

  draw();
  glFlush();
  swapBuffers();
  
  QGLViewer::paintGL();
}


void Viewer::draw()
{
  if(true ==RUNNING_AT_TEST_MODE ){
		testDrawCube();
	}
	else{
		if(mesh_){
			mesh_->render();
		}  
	}
}

void Viewer::reloadMesh(QString& filename)
{
  // converte aiMesh to MeshCore format
  if(mesh_)
  {
    delete mesh_; mesh_ = 0;
  }
  if(mesh_ == 0)
    mesh_ = new MeshCore();

  //TODO: copy the data in aiMesh to MeshCore style pMesh
  MeshLoader * loader = new MeshLoader();
  bool ret = loader->load(filename.toAscii().data());
  if(ret == false)
  {
    emit log(QString(tr( "MeshLoader failed to load the mesh")));
  }
  else{
    emit log(QString(QObject::tr("MeshLoader load the mesh ok")));
  }
  
  MeshBuilder<Polyhedron::HalfedgeDS> builder(loader);
  mesh_->delegate(builder);
  mesh_->set_indices();

  QString message;
  QTextStream(&message)<<"Mesh info: vertices num: "<<mesh_->size_of_vertices()<<" facet num: "<<mesh_->size_of_facets();
  emit log(message);

  delete loader;//delete local meshloader to save memory
    
	Iso_cuboid_3 box = mesh_->get_bounding_box();

	LOG(INFO)<<"retrived bounding box: ("
			     <<box.xmin()<<","
			     <<box.ymin()<<","
			     <<box.zmin()<<")"
			     <<"    >>    ("
			     <<box.xmax()<<","
			     <<box.ymax()<<","
			     <<box.zmax()<<")";

	pCamera->setSceneBoundingBox(qglviewer::Vec(box.xmin(),box.ymin(),box.zmin()),
				     qglviewer::Vec(box.xmax(),box.ymax(),box.zmax()));

	pCamera->showEntireScene();
	updateGL();
}

void Viewer::testDrawCube()
{
  printf("testDrawCube \n");
	glTranslatef(0.0f,0.0f,0.0f);
		// Code from http://www.morrowland.com/apron/tutorials/gl/gl_rotating_cube.php
		glBegin(GL_QUADS);
		glColor3f(0.0f,1.0f,0.0f);// Color Blue
		glVertex3f( 1.0f, 1.0f,-1.0f);// Top Right Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f,-1.0f);// Top Left Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f, 1.0f);// Bottom Left Of The Quad (Top)
		glVertex3f( 1.0f, 1.0f, 1.0f);// Bottom Right Of The Quad (Top)

		glColor3f(1.0f,0.5f,0.0f);// Color Orange
		glVertex3f( 1.0f,-1.0f, 1.0f);// Top Right Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f, 1.0f);// Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f,-1.0f);// Bottom Left Of The Quad (Bottom)
		glVertex3f( 1.0f,-1.0f,-1.0f);// Bottom Right Of The Quad (Bottom)

		glColor3f(1.0f,0.0f,0.0f);// Color Red
		glVertex3f( 1.0f, 1.0f, 1.0f);// Top Right Of The Quad (Front)
		glVertex3f(-1.0f, 1.0f, 1.0f);// Top Left Of The Quad (Front)
		glVertex3f(-1.0f,-1.0f, 1.0f);// Bottom Left Of The Quad (Front)
		glVertex3f( 1.0f,-1.0f, 1.0f);// Bottom Right Of The Quad (Front)

		glColor3f(1.0f,1.0f,0.0f);// Color Yellow
		glVertex3f( 1.0f,-1.0f,-1.0f);// Top Right Of The Quad (Back)
		glVertex3f(-1.0f,-1.0f,-1.0f);// Top Left Of The Quad (Back)
		glVertex3f(-1.0f, 1.0f,-1.0f);// Bottom Left Of The Quad (Back)
		glVertex3f( 1.0f, 1.0f,-1.0f);// Bottom Right Of The Quad (Back)

		glColor3f(0.0f,0.0f,1.0f);// Color Blue
		glVertex3f(-1.0f, 1.0f, 1.0f);// Top Right Of The Quad (Left)
		glVertex3f(-1.0f, 1.0f,-1.0f);// Top Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f,-1.0f);// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f, 1.0f);// Bottom Right Of The Quad (Left)

		glColor3f(1.0f,0.0f,1.0f);// Color Violet
		glVertex3f( 1.0f, 1.0f,-1.0f);// Top Right Of The Quad (Right)
		glVertex3f( 1.0f, 1.0f, 1.0f);// Top Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f, 1.0f);// Bottom Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f,-1.0f);// Bottom Right Of The Quad (Right)
		glEnd();
}


void Viewer::saveImage(const QString& filename)
{
	//when you open a dialog, the glbuffer is overlap by a dialog, so you
	//select the back buffer to grab
	glReadBuffer(GL_BACK);
	QImage image = grabFrameBuffer(true);
	image.save(filename);
}


void Viewer::printDebugInfo()
{

}
