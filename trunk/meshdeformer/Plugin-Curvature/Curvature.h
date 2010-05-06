//-*-c++-*- Curvature.h --- calculate mesh curvatures
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
#include <QCheckBox>
#include <QWidget>

#include <map>
#include <boost/property_map.hpp>

#include "BasePlugin/BaseInterface.h"
#include "BasePlugin/RenderInterface.h"
#include "BasePlugin/LoggingInterface.h"
#include "BasePlugin/ToolBoxInterface.h"
#include "BasePlugin/MeshCoreInterface.h"

#include "MeshCore/MeshCore.h"
#include "Common/ColorCoding.h"

/**
   @brief: for calculate mesh curvatures
*/
class Curvature : public QObject,
                  public BaseInterface,
                  public RenderInterface,
                  public LoggingInterface,
                  public ToolBoxInterface,
                  public MeshCoreInterface    
{
  Q_OBJECT
  Q_INTERFACES( BaseInterface );
  Q_INTERFACES( LoggingInterface );
  Q_INTERFACES( RenderInterface );
  Q_INTERFACES( ToolBoxInterface );
  Q_INTERFACES( MeshCoreInterface );
      
 public:
  Curvature() : toolbox_widget_( 0 ) {}
  virtual ~Curvature() {
    delete calMeanCurvatureButton_;
    delete calGaussCurvatureButton_;
    delete enable_render_mean_curvature_value_checkbox_;
    delete enable_render_mean_curvature_normal_checkbox_;
    delete enable_render_gaussian_curvature_value_checkbox_;
    delete layout_;
    delete toolbox_widget_;
  }

  //BaseInterface
 public slots:
  void initializePlugin(  ) {
     emit log( QString( "initializing Curvature Plugin..." ) );
     calMeanCurvatureButton_                          = new QPushButton( QString( tr( "Mean Curvature" ) ) );
     calGaussCurvatureButton_                         = new QPushButton( QString( tr( "Gauss Curvature" ) ) );

     enable_render_mean_curvature_value_checkbox_     = new QCheckBox( QString( tr( "MeanCurvature Value" ) ) );
     connect( enable_render_mean_curvature_value_checkbox_, SIGNAL( stateChanged( int  ) ), this, SLOT( toggleMeanCurvatureValueFlag( int ) ) );
     
     render_meancurvature_value_flag_                 = false;
     
     enable_render_mean_curvature_normal_checkbox_    = new QCheckBox( QString( tr( "MeanCurvature Normal" ) ) );
     connect( enable_render_mean_curvature_normal_checkbox_, SIGNAL( stateChanged( int ) ), this, SLOT( toggleMeanCurvatureValueFlag( int ) ) );
     render_meancurvature_normal_flag_                = false;
     
     enable_render_gaussian_curvature_value_checkbox_ = new QCheckBox( QString( tr( "GaussianCurvature Value" ) ) );
     connect( enable_render_gaussian_curvature_value_checkbox_, SIGNAL( stateChanged( int ) ), this, SLOT( toggleGaussianCurvatureValueFlag( int ) ) );
     render_gaussiancurvature_value_flag_             = false;
     
     layout_                                          = new QVBoxLayout(  );
     layout_->addWidget( calMeanCurvatureButton_ );
     layout_->addWidget( calGaussCurvatureButton_ );
     toolbox_widget_                                  = new QWidget(  );
     toolbox_widget_->setLayout( layout_ );

     halfedge_cot_value_properties_                   = boost::make_assoc_property_map<HalfedgeCotMap>( halfedge_cotvalue_map_);
     vertex_voronoiarea_properties_                   = boost::make_assoc_property_map<VertexVoroniAreaMap>( vertex_voronoiarea_map_ );

     vertex_meancurvature_properties_                 = boost::make_assoc_property_map<Vertex_MeanCurvature_Map>( vertex_meancurvature_map_ );
     vertex_gaussiancurvature_properties_             = boost::make_assoc_property_map<Vertex_GaussianCurvature_Map>( vertex_gaussiancurvature_map_ );
  }
  
  void pluginInitialized(  ) {
    emit addToolBox( QString( tr( "Curvatures" ) ), toolbox_widget_ );
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

  //RenderInterface
 public:
  void render(  );

  //The extra data for computing curvatures
private:
  MeshCore* mesh_;
private:
  typedef std::map<Halfedge_handle,float,HalfedgeHandleCmp> HalfedgeCotMap;
  HalfedgeCotMap halfedge_cotvalue_map_;
  boost::associative_property_map<HalfedgeCotMap> halfedge_cot_value_properties_;

  typedef std::map<Vertex_handle, float, VertexHandleCmp> VertexVoroniAreaMap;
  VertexVoroniAreaMap vertex_voronoiarea_map_;
  boost::associative_property_map<VertexVoroniAreaMap> vertex_voronoiarea_properties_;

  typedef std::map<Vertex_handle,Vector_3,VertexHandleCmp> Vertex_MeanCurvature_Map;
  Vertex_MeanCurvature_Map vertex_meancurvature_map_;
  boost::associative_property_map<Vertex_MeanCurvature_Map> vertex_meancurvature_properties_;

  typedef std::map<Vertex_handle,float,VertexHandleCmp> Vertex_GaussianCurvature_Map;
  Vertex_GaussianCurvature_Map vertex_gaussiancurvature_map_;
  boost::associative_property_map<Vertex_GaussianCurvature_Map> vertex_gaussiancurvature_properties_;
  
public:
  float getHalfedgeCotValue( Halfedge_handle pHalfedge ) {
    return get( halfedge_cot_value_properties_,pHalfedge );
  }
  float getVertexVoronoiArea( Vertex_handle pVertex ) {
    return get( vertex_voronoiarea_properties_, pVertex );
  }
  Vector_3 get_vertex_mean_curvature( Vertex_handle pVertex ) {
    return get( vertex_meancurvature_properties_, pVertex );
  }
  float get_vertex_gaussian_curvature( Vertex_handle pVertex ) {
    return get( vertex_gaussiancurvature_properties_, pVertex );
  }
  
public: //should be private
  /**\brief: calculate the angle between between two vector
     v1v0,v2v1
     @param: v0, the first point
     @param: v1, the second point( related with the angle )
     @param: v2, the third point
  */
  float calculateAngle( Vertex_handle v0, Vertex_handle v1, Vertex_handle v2 ) {
    float length_v0v1, length_v1v2, length_v2v0;
    //calculate <v0v1v2
    //a^2 = b^2+c^2-2*b*c*cos( alpha )
    //so: v2v0^2 = v0v1^2+v1v2^2-2*v0v1*v1v2*cos( alpha )
    length_v0v1 = calculateVecLength( v0,v1 );    // b
    length_v1v2 = calculateVecLength(v1,v2);    //c
    length_v2v0 = calculateVecLength( v2,v0 );    //a
    float cosAlpha = (length_v0v1*length_v0v1+
                      length_v1v2*length_v1v2-
                      length_v2v0*length_v2v0)/( 2*length_v0v1*length_v1v2);

    return acos( cosAlpha );
  }

  float calculateVecLength( Vertex_handle v0, Vertex_handle v1 ) {
     Vector_3 v0v1 = v1->point(  )-v0->point(  );
     float length_v0v1 = ( v0v1.x(  )*v0v1.x(  ) +
                        v0v1.y(  )*v0v1.y(  ) +
                        v0v1.z(  )*v0v1.z(  ));

     return sqrt( length_v0v1 );     
  }
  
public slots: 
  void setMesh( MeshCore* _mesh ) {
    mesh_ = _mesh;
    prebuild_coefficients_flag_ = false;
  }

  void calculateEdgeCotValues(  );
  float calculateVertexVoronoiArea( Vertex_handle pVertex );
  void calculateVoronoiAreas(  );

  void prebuild_coefficients(  ) {
    assert( mesh_ != NULL );

    calculateVoronoiAreas(  );
    calculateEdgeCotValues(  );

    prebuild_coefficients_flag_ = true;
  }

public slots:
  void slotCalculateMeanCurvatures(  );
  void slotCalculateGaussianCurvatures(  );
  
 public:
  void render_mean_curvature_value(  );
  void render_mean_curvature_normal(  );
  void render_gaussian_curvature_value(  );
 private:
  void prebuild_mean_curvature_color_coding_value(  );
  void prebuild_gaussian_curvature_color_coding_value(  );
  ColorCoding<float>* mean_curvature_color_coding_;
  ColorCoding<float>* gaussian_curvature_color_coding_;
 private slots:
  void toggleMeanCurvatureValueFlag( int state ) {
    render_meancurvature_value_flag_ = !render_meancurvature_value_flag_;
    if( render_meancurvature_value_flag_ == true )
      prebuild_mean_curvature_color_coding_value(  );
  }
  void toggleMeanCurvatureNormalFlag( int state ) {
    render_meancurvature_normal_flag_ = !render_meancurvature_normal_flag_;
  }
  void toggleGaussianCurvatureValueFlag( int state ) {
    render_gaussiancurvature_value_flag_ = !render_gaussiancurvature_value_flag_;
    if( render_gaussiancurvature_value_flag_ )
      prebuild_gaussian_curvature_color_coding_value(  );
  }
 private:
  //rendering flags
  bool render_meancurvature_value_flag_;
  bool render_meancurvature_normal_flag_;
  bool render_gaussiancurvature_value_flag_;
  //Toolbox widgets
  bool prebuild_coefficients_flag_;
  QPushButton* calGaussCurvatureButton_;
  QPushButton* calMeanCurvatureButton_;
  QCheckBox* enable_render_mean_curvature_value_checkbox_;
  QCheckBox* enable_render_mean_curvature_normal_checkbox_;
  QCheckBox* enable_render_gaussian_curvature_value_checkbox_;
  
  QVBoxLayout* layout_;
  QWidget* toolbox_widget_;//main widget for toolbox
};

#endif /* _MEANCURVATURE_H_ */
// 
// Curvature.h ends here
