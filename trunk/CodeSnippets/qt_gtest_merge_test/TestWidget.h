/* -*-c++-*-
 * TestWidget.h --- 
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
#ifndef _TESTWIDGET_H_
#define _TESTWIDGET_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class TestWidget : public QWidget
{
 public:
  TestWidget(QWidget* parent = 0);
  virtual ~TestWidget();

  QLabel* label_;
  QPushButton* button_;
  QVBoxLayout* layout_;
};


#endif /* _TESTWIDGET_H_ */
/* TestWidget.h ends here */
