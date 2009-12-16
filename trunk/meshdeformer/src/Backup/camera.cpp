#include "camera.hpp"

Camera::Camera()
{
  pos = CVector3d(0,0,2);
  target = CVector3d(0,0,0);
  up = CVector3d(0,0,1);
}

Camera::~Camera()
{
}

void Camera::setPos(float x,float y,float z)
{
  pos = CVector3d(x,y,z);
}

void Camera::setTarget(float x,float y,float z)
{
  target = CVector3d(x,y,z);
}

void Camera::setUp(float x,float y,float z)
{
  up = CVector3d(x,y,z);
}

void Camera::buildProjMatrix()
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(pos.x(),pos.y(),pos.z(),
	    target.x(),target.y(),target.z(),
	    up.x(),up.y(),up.z()
	    );
}

void Camera::setViewport(int width,int height)
{
  aspectRatio = (float)width/(float)height;
  glViewport(0,0,width,height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45,aspectRatio,0.1f,100.0f);
}


  

