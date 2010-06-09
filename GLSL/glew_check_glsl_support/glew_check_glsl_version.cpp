// glew_check_glsl_version.cpp --- check the glsl ability using glew
// ref: www.lighthouse3d.com/opengl/glsl/index.php?ogloverview
// copyright (c) 2010 dreamway
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free Software Foundation;
//  Feel free to contact dreamway(jingwenlai@163.com)
// 
// website: cg.xplore.cn
// 
// 

// Commentary: 
// 
//
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
  glutInit( &argc, argv );
  glutCreateWindow( "GLEW Check Test" );
  GLenum err = glewInit(  );
  if( GLEW_OK != err ) {
    printf( "ERROR: %s\n",glewGetErrorString( err ) );
  }
  
  if( GLEW_VERSION_2_0 )
    printf( "Ready for OpenGL 2.0\n" );
  else {
    printf( "OpenGL 2.0 not supported\n" );
    return -1;
  }
  
  //  glutMainLoop(  );

  return 0;
}

//  
// 
// glew_check_glsl_version.cpp ends here
