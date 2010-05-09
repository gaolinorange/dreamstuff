/* MainWidget.h --- 
 * copyright (c) 2010 dreamway
 */

/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the Free Software Foundation;
 *  Feel free to contact dreamway(jingwenlai@163.com)
 * 
 * website: cg.xplore.cn
 */

/* Commentary: 
 * 
 */
#ifndef _MAINWIDGET_H_
#define _MAINWIDGET_H_

//#include <QGLViewer.h>
#include <QGLViewer/qglviewer.h>

class MainWidget : public QGLViewer {
public:
MainWidget( QWidget* parent = 0,const QGLWidget* shareWidget = 0, Qt::WindowFlags flags = 0 ) : QGLViewer( parent,shareWidget,flags ) {
    
  }
  MainWidget::~MainWidget(  ) {
    
  }
protected:
  void draw(  );
  void testDrawCube(  );
};


#endif /* _MAINWIDGET_H_ */
/* MainWidget.h ends here */
