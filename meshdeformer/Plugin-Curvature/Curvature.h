//Curvature.h --- calculate mesh curvatures
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
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include <map>
#include <boost/property_map.hpp>

#include "BasePlugin/BaseInterface.h"
#include "BasePlugin/MeshRenderInterface.h"
#include "BasePlugin/LoggingInterface.h"
#include "BasePlugin/ToolBoxInterface.h"

#include "MeshCore/MeshCore.h"

struct HalfedgeHandleCmp {
  bool operator()( Halfedge_handle e1, Halfedge_handle e2 ) {
    if( e1->id( ) < e2->id(  ) )
      return true;
    return false;
  }  
};

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
public:
  //BaseInterface
  QString description(  ) const {
    return QString( tr( "Curvature Plugin description" ) );
  }
  QString name(  ) const {
    return QString( "CurvaturePlugin" );
  }
signals:
  //LoggingInterface
  void log( const QString& logMessage );
  //ToolBoxInterface
  void addToolBox( QString, QWidget* );
  //MeshRenderInterface
 public:
  void render(  );

  //The extra data for computing curvatures
private:
  MeshCore* pMesh;
private:
  typedef std::map<Halfedge_handle,float,HalfedgeHandleCmp> HalfedgeCotMap;
  HalfedgeCotMap cotValueMap;
  
  boost::associative_property_map<HalfedgeCotMap> edgeCotValues;
public:
  float getHalfedgeCotValue( Halfedge_handle pHalfedge ) {
    return get( edgeCotValues,pHalfedge );
  }
private:
  /**\brief: calculate the angle between between two vector
     v1v0,v2v1
     @param: v0, the first point
     @param: v1, the second point( related with the angle )
     @param: v2, the third point
  */
  float _calculateAngle( Vertex_handle v0, Vertex_handle v1, Vertex_handle v2 ) {
    Vector_3 v0v1, v1v2, v2v0;
    float length_v0v1, length_v1v2, length_v2v0;
    //calculate <v0v1v2
    //a^2 = b^2+c^2-2*b*c*cos( alpha )
    //so: v2v0^2 = v0v1^2+v1v2^2-2*v0v1*v1v2*cos( alpha )
    v0v1 = v1->point(  )-v0->point(  );
    v1v2 = v2->point(  )-v1->point(  );
    v2v0 = v0->point(  )-v2->point(  );
    // b^2
    length_v0v1 = ( v0v1.x(  )*v0v1.x(  ) +
                        v0v1.y(  )*v0v1.y(  ) +
                        v0v1.z(  )*v0v1.z(  ));
    //c^2
    length_v1v2 = ( v1v2.x(  )*v1v2.x(  ) +
                        v1v2.y(  )*v1v2.y(  ) +
                        v1v2.z(  )*v1v2.z(  ));
    //a^2
    length_v2v0 = ( v2v0.x(  )*v2v0.x(  ) +
                        v2v0.y(  )*v2v0.y(  ) +
                        v2v0.z(  )*v2v0.z(  ));
    //b
    float length_v0v1_sqrt = sqrt( length_v0v1 );
    //c
    float length_v1v2_sqrt = sqrt( length_v1v2 );
    
    float cosAlpha = (length_v0v1+length_v1v2-length_v2v0)/( 2*length_v0v1_sqrt*length_v1v2_sqrt );

    return acos( cosAlpha );
  }
  
public:
  void setMesh( MeshCore* _mesh ) {
    pMesh = _mesh;
  }
  void calculateEdgeCotValues(  ) {
    Vertex_handle v0,v1,v2;    
    float alpha;
    
    for (Halfedge_iterator pHalfedge = pMesh->halfedges_begin(  );
         pHalfedge != pMesh->halfedges_end(  ); pHalfedge++)
    {
      v0 = pHalfedge->vertex(  );
      v1 = pHalfedge->next(  )->vertex(  );
      v2 = pHalfedge->next(  )->next(  )->vertex(  );

      alpha = _calculateAngle( v0, v1, v2 );

      float value = 1/tan( alpha );
      put( edgeCotValues, pHalfedge, value );
    }    
  }

  void calculateVoronoiAreas(  ) {
    
  }

public slots:
  void slotCalculateMeanCurvatures(  ) {
    
  }

  void slotCalculateGaussianCurvatures(  ) {
    
  }
      
  
 private:
  QPushButton* calGaussCurvatureButton_;
  QPushButton* calMeanCurvatureButton_;
  QVBoxLayout* layout_;
  QWidget* widget_;//main widget for toolbox
};

#endif /* _MEANCURVATURE_H_ */
// 
// Curvature.h ends here
