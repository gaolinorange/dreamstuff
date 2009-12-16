#include "main_widget.h"
#include "QOutputLogger.hpp"

#include "globals.hpp"
#include <QtDebug>
#include <QtGui>
#include <iostream>

void MainWidget::initializeGL()
{
  printf("entering initializeGL.. \n");
  qglClearColor(Qt::black);
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE); 
  glDisable(GL_LIGHTING);

  //setup render related class
  pData->initATetrahedron();

  pCamera->setPosition(qglviewer::Vec(0,0,-2));
  pCamera->setViewDirection(qglviewer::Vec(0,0,1));
  pCamera->setUpVector(qglviewer::Vec(0,1,0));
  setCamera(pCamera);
  
  setSceneRadius(10.0);
  setSceneCenter(qglviewer::Vec(0,0,0));
  camera()->showEntireScene();

  QGLViewer::initializeGL();
}

void MainWidget::resizeGL(int w,int h)
{
  printf("resizeGL \n");
  camera()->setAspectRatio(float(w)/h);
  camera()->setScreenWidthAndHeight(w,h);

  QGLViewer::resizeGL(w,h);
}

void MainWidget::updateGL()
{
  printf("updateGL \n");
  paintGL();
  
  QGLViewer::updateGL();
}

void MainWidget::paintGL()
{
    printf("paintGL \n");
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  switch(polygonMode){
	  case PM_WIREFRAME:
		  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		  break;
	  case PM_SOLID:
		  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
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


void MainWidget::draw()
{
  printf("draw \n");
  testDrawCube();
#if 0
  if(true ==RUNNING_AT_TEST_MODE ){
		testDrawCube();
	}
	else{
		if(pData){
			pData->render();
		}  
	}
#endif
}

void MainWidget::testDrawCube()
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


void MainWidget::saveImage(const QString& filename)
{
	//when you open a dialog, the glbuffer is overlap by a dialog, so you
	//select the back buffer to grab
	glReadBuffer(GL_BACK);
	QImage image = grabFrameBuffer(true);
	image.save(filename);
}


void MainWidget::printDebugInfo()
{

}
