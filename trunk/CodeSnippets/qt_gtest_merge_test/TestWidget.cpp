// TestWidget.cpp --- 
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
#include "TestWidget.h"

TestWidget::TestWidget( QWidget* parent ) : QWidget( parent ) {
  label_ = new QLabel( QString( tr( "Test label" ) ) );
  button_ = new QPushButton( QString( tr( "Test Button" ) ) );
  layout_ = new QVBoxLayout;
  layout_->addWidget( label_ );
  layout_->addWidget( button_ );

  setLayout( layout_ );
}

TestWidget::~TestWidget(  ) {
  delete label_;
  delete button_;
  delete layout_;
}

//  
// 
// TestWidget.cpp ends here
