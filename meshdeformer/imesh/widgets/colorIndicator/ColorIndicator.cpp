#include "Colorindicator.h"
#include <QPainter>
#include <QtDebug>
#include <QLinearGradient>
#include <cmath>
using namespace std;

void QColorIndicator::setMinMaxValue(qreal minValue,qreal maxValue)
{
  _minValue = minValue;
  _maxValue = maxValue;
}

void QColorIndicator::setNumSpan(int num)
{
  numSpan = num;
  spans.clear();
  spans.resize(numSpan+1);
}

bool QColorIndicator::_minMaxIsValid()
{
	if( (fabs(_minValue-INVALID_INDICATOR_VALUE)<1e-3) ||
		(fabs(_maxValue-INVALID_INDICATOR_VALUE)<1e-3) )
	{
		return false;
	}
  return true;  
}

void QColorIndicator::setSpanIdxValue(int idx,qreal value)
{
  if(idx > numSpan)
    return;
  if(!_minMaxIsValid())
    return;
  
  spans[idx] = value;
}

void QColorIndicator::setSpanIdxColor(int idx,const QColor& color)
{
  if(idx > numSpan)
    return;
  if(!_minMaxIsValid())
    return;
  
  spanColors[idx] = color;
}



//common painting method
void QColorIndicator::actualPaint()
{
	QPainter painter(this);
	//second: interpolate the middles with the range
	qreal pos;
	qreal range = _maxValue-_minValue;

	for(int i = 0; i <= numSpan; i++)
	{
		pos = (spans[i]-_minValue)/range; //translate user set value to (0,1)
		linearGradient.setColorAt(pos,spanColors[i]);
	}
	//third, fill the rect
	painter.fillRect(rect(),linearGradient);
}

void QColorIndicator::paintEvent(QPaintEvent* event)
{
	if(numSpan == 0)
		return;

	//first, set the widgets start and final stop
	linearGradient.setStart(0,0);
	linearGradient.setFinalStop(width(),height());

	actualPaint();
}


void QHColorIndicator::paintEvent(QPaintEvent* event)
{
	if(numSpan == 0)
		return;

	linearGradient.setStart(0,0);
	linearGradient.setFinalStop(width(),0);

	actualPaint();
}

void QVColorIndicator::paintEvent(QPaintEvent* event)
{
	if(numSpan == 0)
		return;

	linearGradient.setStart(0,0);
	linearGradient.setFinalStop(0,height());

	actualPaint();
}

