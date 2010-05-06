/* ColorCodingWidget.h --- 
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
#ifndef _COLORCODINGWIDGET_H_
#define _COLORCODINGWIDGET_H_

#include <QBoxLayout>
#include "ColorIndicator.h"

class ColorCodingWidget : public QWidget {
  Q_OBJECT
  public:
  ColorCodingWidget(QWidget* parent = 0) : QWidget( parent ) {
    layout_ = new QBoxLayout( this );
  }
  virtual ~ColorCodingWidget() {
    delete layout_;
  }
 public:
  virtual void setMinMaxValue( float ,float ) {
    
  }
  virtual void setNumSpan( int num ) {
    
  }
  
 protected:
  QBoxLayout* layout_;
};

class HColorCodingWidget : public ColorCodingWidget {
  Q_OBJECT
  public:
  HColorCodingWidget(QWidget* parent = 0) : ColorCodingWidget( parent ) {
    indicator_ = new QHColorIndicator(  );
    layout_->addWidget( min_value_label_,0,0 );
    layout_->addWidget( max_value_label_,0,4 );
    layout_->addWidget( indicator_,1,0,1,5 );

    setLayout( layout_ );
  }
  virtual ~HColorCodingWidget() {
    delete indicator_;
  }

 public:
  void setMinMaxValue( float _min_value,float _max_value ) {
    indicator_->setMinMaxValue( _min_value,_max_value );
    min_value_label_->setText( QString::number( _min_value ) );
    max_value_label_->setText( QString::number( _max_value ) );
  }
  void setNumSpan( int num ) {
    indicator_->setNumSpan( num );
  }
 private:
  QHColorIndicator* indicator_;  
};

class VColorCodingWidget : public ColorCodingWidget {
  Q_OBJECT
  
  public:
  VColorCodingWidget(QWidget* parent = 0) : ColorCodingWidget( parent ) {
    indicator_ = new QVColorIndicator;
    layout_->addWidget( min_value_label_,0,1 );
    layout_->addWidget( max_value_label_,4,1 );
    layout_->addWidget( indicator_,0,0,5,1 );

    setLayout( layout_ );
  }
  virtual ~VColorCodingWidget() {
    
  }

 public:
  void setMinMaxValue( float _min_value,float _max_value ) {
    indicator_->setMinMaxValue( _min_value,_max_value );
    min_value_label_->setText( QString::number( _min_value ) );
    max_value_label_->setText( QString::number( _max_value ) );
  }
  void setNumSpan( int num ) {
    indicator_->setNumSpan( num );
  }

 private:
  QVColorIndicator* indicator_;
};

#endif /* _COLORCODINGWIDGET_H_ */
/* ColorCodingWidget.h ends here */
