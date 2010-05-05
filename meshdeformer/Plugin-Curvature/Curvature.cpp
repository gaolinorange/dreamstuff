// MeanCurvature.cpp --- 
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
#include "Curvature.h"
#include "Common/glheaders.hpp"


void Curvature::calculateEdgeCotValues(  ) {
  Vertex_handle v0,v1,v2;    
  float alpha,beta;
    
  for (Halfedge_iterator pHalfedge = mesh_->halfedges_begin(  );
       pHalfedge != mesh_->halfedges_end(  ); pHalfedge++)
  {
    v0 = pHalfedge->vertex(  );
    v1 = pHalfedge->next(  )->vertex(  );
    v2 = pHalfedge->next(  )->next(  )->vertex(  );
    alpha = calculateAngle( v0, v1, v2 );

    v0 = pHalfedge->opposite(  )->vertex(  );
    v1 = pHalfedge->opposite(  )->next(  )->vertex(  );
    v2 = pHalfedge->opposite(  )->next(  )->next(  )->vertex(  );
    beta = calculateAngle( v0,v1,v2 );

    float value = 1.0/tan( alpha )+1.0/tan( beta );
    halfedge_cotvalue_map_.insert(make_pair( pHalfedge, value )  );//
  }    
}

float Curvature::calculateVertexVoronoiArea( Vertex_handle pVertex ) {
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
    angleP = calculateAngle( Q,P,R );
    angleQ = calculateAngle( P,Q,R );
    angleR = calculateAngle( P,R,Q );
    length_PQ = calculateVecLength( P,Q );
    length_PR = calculateVecLength( P,R );
    length_QR = calculateVecLength( Q,R );
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



void Curvature::calculateVoronoiAreas(  ) {
  float area;
  for (Vertex_iterator pVertex = mesh_->vertices_begin(  );
       pVertex != mesh_->vertices_end(  ) ; ++pVertex)
  {
    area = calculateVertexVoronoiArea( pVertex );
    vertex_voronoiarea_map_.insert( make_pair( pVertex, area ) );
  }    
}

//Public slots for extenal calling
void Curvature::slotCalculateMeanCurvatures(  ) {
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

void Curvature::slotCalculateGaussianCurvatures(  ) {
  if( prebuild_coefficients_flag_ == false )
    prebuild_coefficients(  );

  //do the actual work
  float gaussian_curvature;
  float Amixed;
  float theta, theta_sum;
  Vertex_handle pre_vertex,next_vertex;
  Halfedge_around_vertex_circulator pHalfedge,pHalfedgeEnd;
  for (Vertex_iterator pVertex = mesh_->vertices_begin(  );
       pVertex != mesh_->vertices_end(); ++pVertex)
  {
    theta_sum = 0.0;
    pHalfedge = pHalfedgeEnd = pVertex->vertex_begin(  );
    do{
      pre_vertex = pHalfedge->opposite(  )->vertex(  );
      next_vertex = pHalfedge->next(  )->vertex(  );
      theta = calculateAngle( pre_vertex, pVertex, next_vertex );
      theta_sum += theta;
    }while( ++pHalfedge != pHalfedgeEnd );

    Amixed = getVertexVoronoiArea( pVertex );

    gaussian_curvature = 1.0/Amixed * ( 2*CGAL_PI-theta_sum );
    vertex_gaussiancurvature_map_.insert( make_pair( pVertex,gaussian_curvature ) );
  }    
}


//Render the extra data of the original mesh
void Curvature::render(  ) {
  emit log( QString( tr( "Curvature::render..." ) ) );
  
  glDisable( GL_LIGHTING );
  if( render_meancurvature_value_flag_ ) {
    render_mean_curvature_value(  );
  }
  if( render_meancurvature_normal_flag_ ) {
    render_mean_curvature_normal(  );
  }
  if( render_gaussiancurvature_value_flag_ ) {
    render_gaussian_curvature_value(  );
  }
  
  glEnable( GL_LIGHTING );
}

//TODO: colorcoding 
void Curvature::render_mean_curvature_value(  ) {
  
}

void Curvature::render_mean_curvature_normal(  ) {
  
}

void Curvature::render_gaussian_curvature_value(  ) {
  
}








Q_EXPORT_PLUGIN2(curvature, Curvature)
  
//  
// 
// MeanCurvature.cpp ends here

