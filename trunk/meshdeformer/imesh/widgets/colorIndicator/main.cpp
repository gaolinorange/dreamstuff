#include<QApplication>
#include "ColorCodingWidget.h"

int main(int argc,char** argv)
{
  QApplication app(argc,argv);

  //  QVColorIndicator indicator;
  VColorCodingWidget indicator;
  indicator.setMinMaxValue(-10,10);
  indicator.setNumSpan(2);
  indicator.setSpanIdxValue(0,-10);
  indicator.setSpanIdxColor(0,QColor(255,0,0));

  indicator.setSpanIdxValue(1,0);
  indicator.setSpanIdxColor(1,QColor(0,255,0));

  indicator.setSpanIdxValue(2,10);
  indicator.setSpanIdxColor(2,QColor(0,0,255));
    
  indicator.resize(400,50);
  indicator.show();

  return app.exec();
}
