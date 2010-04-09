//-*-c++-*-
/* StatusBar.h --- Displaying the status message in main window
 * copyright (c) 2010 dreamway

/*  This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the Free Software Foundation;
 *  Free free to contact dreamway(jingwenlai@163.com)
 * 
 * website: cg.xplore.cn
 */
#ifndef WIDGETS_STATUSBAR_STATUSBAR_H
#define WIDGETS_STATUSBAR_STATUSBAR_H


#include <QStatusBar>


/* Commentary: 
 * 
 */
class StatusBar : public QStatusBar
{
 public:
  StatusBar(QWidget* parent = 0)
      : QStatusBar(parent ) {
  }
  virtual ~StatusBar() {
    
  }
};

#endif
/* StatusBar.h ends here */
