#include "main_widget.h"

void MainWidget::initializeGL()
{
  qglClearColor(Qt::black);
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);  
}

void MainWidget::resizeGL(int w,int h)
{
  glViewport(0,0,(GLint)w,(GLint)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

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
