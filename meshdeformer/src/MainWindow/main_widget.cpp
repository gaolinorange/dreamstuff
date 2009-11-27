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

  m_pCamera->SetPosition(CVector3d(0,0,10));
  m_pCamera->SetOrientation(0,1,0,0);
  m_pCamera->SetHeightAngle(45.0f);
  m_pCamera->SetNearDistance(0.1f);
  m_pCamera->SetFarDistance(1000.0f);

  m_pArcball = new CArcball();
  m_pArcball->SetCenter(CVector3d(0,0,0));
  m_pArcball->SetRadius(1.0f);  
}

void MainWidget::resizeGL(int w,int h)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

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
//	glDrawBuffer(GL_BACK);

	m_pArcball->Show();
}

void MainWidget::updateGL()
{
  //for animation 
	paintGL();
}

void MainWidget::paintGL()
{
	qDebug()<<"paintGL";
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if(m_pArcball)
  {
	  m_pArcball->glDraw();
  }

  draw();
  swapBuffers();
}

/*
void MainWidget::wheelEvent(QWheelEvent* event)
{
	qDebug()<<"MainWidget::wheelEvent: delta "<<event->delta();
	if(m_pArcball){
		int numDegrees = event->delta()/8;
		int numSteps = numDegrees/15;
		CVector3d offsetVec = CVector3d(0,0.2,0);

		m_pArcball->SetMode(ARCBALL_TRANSLATE_Z);	
		int x = event->pos().x();
		int y = event->pos().y();
		CVector3d vec = m_pArcball->Intersect(x,
			m_pViewport->yRes()-y,
			*m_pCamera,
			*m_pViewport
			);
		m_pArcball->BeginDrag(vec);
		m_pArcball->Motion(vec+offsetVec*numSteps);
		m_pArcball->EndDrag(vec);
		updateGL();
		event->accept();
	}
	event->ignore();
}
*/

void MainWidget::mousePressEvent(QMouseEvent * event)
{
	if(event->button() == Qt::RightButton){
		qDebug()<<"event pos: "<<event->pos();
		int x = event->pos().x();
		int y = event->pos().y();
	
		CVector3d vec = m_pArcball->Intersect(x,
			m_pViewport->yRes()-y,
			*m_pCamera,
			*m_pViewport
			);
		m_pArcball->EndDrag(vec);

		if(event->modifiers() == Qt::NoModifier){
			m_pArcball->SetMode(ARCBALL_ROTATE);
		}
		/*else if(event->modifiers() == Qt::ShiftModifier){
			m_pArcball->SetMode(ARCBALL_TRANSLATE_XY);
		}*/
		else if(event->modifiers() == Qt::ControlModifier){
			m_pArcball->SetMode(ARCBALL_TRANSLATE_Z);
		}

		vec = m_pArcball->Intersect(x,
			m_pViewport->yRes()-y,
			*m_pCamera,
			*m_pViewport);
		m_pArcball->BeginDrag(vec);
		bArcballIsDragging = true;
		event->accept();
	}
	else
		event->ignore();
}

void MainWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if(event->button() == Qt::RightButton){
		qDebug()<<"event pos: "<<event->pos();
		int x = event->pos().x();
		int y = event->pos().y();
		CVector3d vec = m_pArcball->Intersect(x,
			m_pViewport->yRes()-y,
			*m_pCamera,
			*m_pViewport
			);
		m_pArcball->EndDrag(vec);
		bArcballIsDragging = false;
		updateGL();
		event->accept();
	}
	else
		event->ignore();
}

void MainWidget::mouseMoveEvent(QMouseEvent * event)
{
	qDebug()<<"mouseMoveEvent: ";
	if(bArcballIsDragging){
		qDebug()<<"mouseMoveEvnet event pos: "<<event->pos();
		int x = event->pos().x();
		int y = event->pos().y();
		CVector3d vec = m_pArcball->Intersect(x,
			m_pViewport->yRes()-y,
			*m_pCamera,
			*m_pViewport
			);
		m_pArcball->Motion(vec);
		//		updateGL();
		paintGL();
		event->accept();
	}
	else
		event->ignore();
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