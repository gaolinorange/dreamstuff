#include "main_widget.h"
#include "Viewport.hpp"
#include "Camera.hpp"
#include "Arcball.hpp"

void MainWidget::initializeGL()
{
  qglClearColor(Qt::black);
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE); 

  //setup render related class
  m_pViewport = new CViewport();
  m_pCamera = new CCamera();
  m_pCamera->SetPosition(CVector3d(0,0,20));
  m_pCamera->SetOrientation(0,0,-1,0);
  m_pCamera->SetHeightAngle(PI*0.5);
  m_pCamera->SetNearDistance(0.1f);
  m_pCamera->SetFarDistance(100.0f);

  m_pArcball = new CArcball();
  m_pArcball->SetCenter(CVector3d(0,0,0));
  m_pArcball->SetRadius(10.0f);  
}

void MainWidget::resizeGL(int w,int h)
{
/*
	glViewport(0,0,(GLint)w,(GLint)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
*/
	if(m_pViewport)
	{
		m_pViewport->SetSize(w,h);
	}
	else
	{
		m_pViewport = new CViewport(w,h);
	}

  //todo


  
}

void MainWidget::updateGL()
{
  //for animation 
}

void MainWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  draw();
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
  if(pData)
    {
      pData->render();
    }  
}
