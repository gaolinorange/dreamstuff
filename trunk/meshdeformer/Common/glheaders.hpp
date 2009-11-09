#ifndef MESHDEFORMER_COMMON_GLHEADERS_H
#define MESHDEFORMER_COMMON_GLHEADERS_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif

#ifdef __WIN32__
//for windows
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#endif

#ifdef __LINUX__  //for linux
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif



#endif
