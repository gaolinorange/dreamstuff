#include "main_widget.h"
#include "QOutputLogger.hpp"


#include "Viewport.hpp"
#include "Camera.hpp"
#include "Arcball.hpp"


void MainWidget::initializeGL()
{
  qglClearColor(Qt::black);
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE); 
  glDisable(GL_LIGHTING);

  //setup render related class
  m_pViewport = new CViewport();
  m_pCamera = new CCamera();

  m_pCamera->SetPosition(CVector3d(0,0,5));
  m_pCamera->SetOrientation(0,1,0,0);
  m_pCamera->SetHeightAngle(45.0f);
  m_pCamera->SetNearDistance(0.1f);
  m_pCamera->SetFarDistance(1000.0f);

  m_pArcball = new CArcball();
  m_pArcball->SetCenter(CVector3d(0,0,0));
  m_pArcball->SetRadius(10.0f);  
}

void MainWidget::resizeGL(int w,int h)
{
	if(m_pViewport)
	{
		m_pViewport->SetOrigin(0,0);
		m_pViewport->SetSize(w,h);
	}
	else
	{
		m_pViewport = new CViewport(w,h);
	}
	m_pViewport->glDraw();
	m_pCamera->glDraw(*m_pViewport);
	m_pViewport->Trace();
	m_pCamera->Trace();
	m_pArcball->Trace();
}

void MainWidget::updateGL()
{
  //for animation 
}

void MainWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*
  if(m_pArcball)
  {
	  m_pArcball->glDraw();
  }
*/  
  draw();
  swapBuffers();
}


void MainWidget::mousePressEvent(QMouseEvent * event)
{
}

void MainWidget::mouseMoveEvent(QMouseEvent * event)
{
}

void MainWidget::mouseDoubleClickEvent(QMouseEvent * event)
{
}

void MainWidget::draw()
{
	testDrawCube();
/*
	if(pData)
    {
      pData->render();
    }  
*/
}

void MainWidget::testDrawCube()
{
	QOutputLogger::getInstance()->appendMessage(QString(tr("testDrawCube")));
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