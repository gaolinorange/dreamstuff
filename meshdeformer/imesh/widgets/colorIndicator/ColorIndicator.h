// -*-c++-*-
// Colorindicator.h --- 
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
#ifndef HCOLORINDICATOR_H
#define HCOLORINDICATOR_H

#include <QLinearGradient>
#include <QWidget>
#include <QColor>
#include <QVector>
#include <QtGlobal>

#define INVALID_INDICATOR_VALUE -1.0f

class QColorIndicator : public QWidget
{
public:
QColorIndicator(QWidget * parent = 0) : QWidget(parent) {
    _minValue = _maxValue = INVALID_INDICATOR_VALUE;
	  numSpan = 0;
  }
  ~QColorIndicator() {
  }
public:
  void setMinMaxValue(qreal minValue,qreal maxValue);
  void setNumSpan(int num);
  void setSpanIdxValue(int idx,qreal value);
  void setSpanIdxColor(int idx,const QColor & color);
protected:
  bool _minMaxIsValid();
protected:
	virtual void paintEvent(QPaintEvent * event);
protected:
	void actualPaint();
protected:
  qreal _minValue,_maxValue;
  int numSpan;
  QVector<qreal> spans;
  QVector<QColor> spanColors;
  QLinearGradient linearGradient;//with default interpolate (0,0) and (1,1)
};

class QHColorIndicator : public QColorIndicator
{
public:
QHColorIndicator(QWidget * parent = 0)
		: QColorIndicator(parent) {
	}
	~QHColorIndicator() {
	}
protected: 
	virtual void paintEvent(QPaintEvent* event);
};

class QVColorIndicator : public QColorIndicator
{
public:
  QVColorIndicator(QWidget * parent = 0) : QColorIndicator(parent) {
	}
	~QVColorIndicator() {
	}
protected:
	virtual void paintEvent(QPaintEvent * event);
};

#endif

// 
// Colorindicator.h ends here
