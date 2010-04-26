// MeanCurvature.h --- calculate mesh curvatures
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
//  
#ifndef _MEANCURVATURE_H_
#define _MEANCURVATURE_H_

#include <QObject>
#include <QtGui>

#include "BasePlugin/BaseInterface.h"
#include "BasePlugin/MeshRenderInterface.h"
#include "BasePlugin/LoggingInterface.h"
#include "BasePlugin/ToolBoxInterface.h"

/**
   @brief: for calculate mesh curvatures
*/
class Curvature : public QObject,
                  public BaseInterface,
                  public MeshRenderInterface,
                  public LoggingInterface,
                  public ToolBoxInterface                      
{
  Q_OBJECT
  Q_INTERFACES( BaseInterface );
  Q_INTERFACES( LoggingInterface );
  Q_INTERFACES( MeshRenderInterface );
  Q_INTERFACES( ToolBoxInterface );
      
 public:
  Curvature() {
    calMeanCurvatureButton_ = new QPushButton( QString( tr( "Mean Curvature" ) ) );
    calGaussCurvatureButton_ = new QPushButton( QString( tr( "Gauss Curvature" ) ) );
    layout_ = new QVBoxLayout(  );
    layout_->addWidget( calMeanCurvatureButton_ );
    layout_->addWidget( calGaussCurvatureButton_ );
    widget_ = new QWidget(  );
    widget_->setLayout( layout_ );
  }
  virtual ~Curvature() {
    delete calMeanCurvatureButton_;
    delete calGaussCurvatureButton_;
    delete layout_;
    delete widget_;
  }

  //BaseInterface
 public slots:
  void pluginInitialized(  ) {
    emit addToolBox( QString( tr( "Curvatures" ) ), widget_ );
    emit log( QString( "Curvature Plugin" ) );
  }
 signals:
  //LoggingInterface
  void LoggingInterface( const QString& logMessage );
  //ToolBoxInterface
  void addToolBox( QString, QWidget* );
  //MeshRenderInterface
 public:
  void render(  );
  
 private:
  QPushButton* calGaussCurvatureButton_;
  QPushButton* calMeanCurvatureButton_;
  QVBoxLayout* layout_;
  QWidget* widget_;//main widget for toolbox
};

#endif /* _MEANCURVATURE_H_ */
// 
// MeanCurvature.h ends here
