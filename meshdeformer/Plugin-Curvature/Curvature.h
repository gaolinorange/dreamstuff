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

struct VertexHandleCmp{
  bool operator(  )( Vertex_handle lhs, Vertex_handle rhs  ) {
    if( lhs->id(  ) < rhs->id(  ) )
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

    halfedge_cot_value_properties_ = boost::make_assoc_property_map<HalfedgeCotMap>( halfedge_cotvalue_map_);
    vertex_voronoiarea_properties_ = boost::make_assoc_property_map<VertexVoroniAreaMap>( vertex_voronoiarea_map_ );

    vertex_meancurvature_properties_ = boost::make_assoc_property_map<Vertex_MeanCurvature_Map>( vertex_meancurvature_map_ );
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
  
public:
  float getHalfedgeCotValue( Halfedge_handle pHalfedge ) {
    return get( halfedge_cot_value_properties_,pHalfedge );
  }
  float getVertexVoronoiArea( Vertex_handle pVertex ) {
    return get( vertex_voronoiarea_properties_, pVertex );
  }
public: //should be private
  /**\brief: calculate the angle between between two vector
     v1v0,v2v1
     @param: v0, the first point
     @param: v1, the second point( related with the angle )
     @param: v2, the third point
  */
  float _calculateAngle( Vertex_handle v0, Vertex_handle v1, Vertex_handle v2 ) {
    float length_v0v1, length_v1v2, length_v2v0;
    //calculate <v0v1v2
    //a^2 = b^2+c^2-2*b*c*cos( alpha )
    //so: v2v0^2 = v0v1^2+v1v2^2-2*v0v1*v1v2*cos( alpha )
    length_v0v1 = _calculateVecLength( v0,v1 );    // b
    length_v1v2 = _calculateVecLength(v1,v2);    //c
    length_v2v0 = _calculateVecLength( v2,v0 );    //a
    float cosAlpha = (length_v0v1*length_v0v1+
                      length_v1v2*length_v1v2-
                      length_v2v0*length_v2v0)/( 2*length_v0v1*length_v1v2);

    return acos( cosAlpha );
  }

  float _calculateVecLength( Vertex_handle v0, Vertex_handle v1 ) {
     Vector_3 v0v1 = v1->point(  )-v0->point(  );
     float length_v0v1 = ( v0v1.x(  )*v0v1.x(  ) +
                        v0v1.y(  )*v0v1.y(  ) +
                        v0v1.z(  )*v0v1.z(  ));

     return sqrt( length_v0v1 );     
  }
  
public:
  void setMesh( MeshCore* _mesh ) {
    mesh_ = _mesh;
    prebuild_coefficients_flag_ = false;
  }
  
  void calculateEdgeCotValues(  ) {
    Vertex_handle v0,v1,v2;    
    float alpha,beta;
    
    for (Halfedge_iterator pHalfedge = mesh_->halfedges_begin(  );
         pHalfedge != mesh_->halfedges_end(  ); pHalfedge++)
    {
      v0 = pHalfedge->vertex(  );
      v1 = pHalfedge->next(  )->vertex(  );
      v2 = pHalfedge->next(  )->next(  )->vertex(  );
      alpha = _calculateAngle( v0, v1, v2 );

      v0 = pHalfedge->opposite(  )->vertex(  );
      v1 = pHalfedge->opposite(  )->next(  )->vertex(  );
      v2 = pHalfedge->opposite(  )->next(  )->next(  )->vertex(  );
      beta = _calculateAngle( v0,v1,v2 );

      float value = 1.0/tan( alpha )+1.0/tan( beta );
      halfedge_cotvalue_map_.insert(make_pair( pHalfedge, value )  );//
    }    
  }

  float calculateVertexVoronoiArea( Vertex_handle pVertex ) {
    //Three different type of triangles
    Halfedge_around_vertex_circulator pHalfedge = pVertex->vertex_begin(  );
    Halfedge_around_vertex_circulator pHalfedgeEnd = pHalfedge;

    //see the related 2005 PPT for these notation
    Vertex_handle P = pVertex;
    Vertex_handle Q,R;    
    float angleP, angleQ, angleR;
    float length_PQ,length_PR,length_QR;
    float Amixed = 0;
    float area;
    do {
      Q = pHalfedge->next()->vertex(  );
      R = pHalfedge->next(  )->next(  )->vertex(  );
      angleP = _calculateAngle( Q,P,R );
      angleQ = _calculateAngle( P,Q,R );
      angleR = _calculateAngle( P,R,Q );
      length_PQ = _calculateVecLength( P,Q );
      length_PR = _calculateVecLength( P,R );
      length_QR = _calculateVecLength( Q,R );
      if( angleP <= CGAL_PI*0.5 && angleQ <= CGAL_PI*0.5 && angleR <= CGAL_PI*0.5 ) {
        area = 1.0/8.0*( length_PR*length_PR*1.0/tan( angleQ ) +
                         length_PQ*length_PQ*1.0/tan( angleR ));
        Amixed += area;
      } else {
        //Hellon method
        area = 0.25 * sqrt( ( length_PR+length_QR+length_PQ ) *
                            ( length_PR+length_QR-length_PQ ) *
                            ( length_PR+length_PQ-length_QR ) *
                            ( length_PQ+length_QR-length_PR ));        
        if( angleP > CGAL_PI*0.5 ) {
          area *= 0.5;
        } else {
          area *= 0.25;
        }
        Amixed += area;
      }      
    } while (++pHalfedge != pHalfedgeEnd);

    return Amixed;
  }
  
  void calculateVoronoiAreas(  ) {
    float area;
    for (Vertex_iterator pVertex = mesh_->vertices_begin(  );
         pVertex != mesh_->vertices_end(  ) ; ++pVertex)
    {
      area = calculateVertexVoronoiArea( pVertex );
      vertex_voronoiarea_map_.insert( make_pair( pVertex, area ) );
    }    
  }

  void prebuild_coefficients(  ) {
    assert( mesh_ != NULL );

    calculateVoronoiAreas(  );
    calculateEdgeCotValues(  );

    prebuild_coefficients_flag_ = true;
  }

public slots:
  void slotCalculateMeanCurvatures(  ) {
    if( prebuild_coefficients_flag_ == false )
      prebuild_coefficients(  );

    //do the actual work
    Vertex_handle v0,v1;
    Halfedge_around_vertex_circulator pHalfedge,pHalfedgeEnd;
    Vector_3 mean_curvature( 0.0,0.0,0.0 );
    float voronoi_area,cot_sum_value;
    
    for( Vertex_iterator pVertex = mesh_->vertices_begin(  );
         pVertex != mesh_->vertices_end(  ); pVertex++) {
      pHalfedge = pVertex->vertex_begin(  );
      pHalfedgeEnd = pHalfedge;
      do{
        v0 = pHalfedge->vertex(  );
        cot_sum_value = get( halfedge_cot_value_properties_, pHalfedge );
        voronoi_area = get( vertex_voronoiarea_properties_, v0 );

        v1 = pHalfedge->opposite(  )->vertex(  );
        
        mean_curvature = mean_curvature +
            1.0/( 2*voronoi_area ) * cot_sum_value * ( Vector_3(v1->point(),v0->point(  )) );
      }while( ++pHalfedge != pHalfedgeEnd );

      vertex_meancurvature_map_.insert( make_pair( pVertex, mean_curvature ) );
    }    
  }

  void slotCalculateGaussianCurvatures(  ) {
    if( prebuild_coefficients_flag_ == false )
      prebuild_coefficients(  );

    //do the actual work
    
  }
  
 private:
  bool prebuild_coefficients_flag_;
  QPushButton* calGaussCurvatureButton_;
  QPushButton* calMeanCurvatureButton_;
  QVBoxLayout* layout_;
  QWidget* widget_;//main widget for toolbox
};

#endif /* _MEANCURVATURE_H_ */
// 
// Curvature.h ends here
