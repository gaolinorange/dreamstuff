// EDS.cpp --- 
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
#include <QInputDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

#include "EDS.h"

//for spatial searching
#include <CGAL/Search_traits_3.h>
#include <CGAL/Search_traits.h>
#include <CGAL/Orthogonal_k_neighbor_search.h>

#include "glog/logging.h"

//Set Toolbox Widgets
void EDS::setupWidgets(  ) {
    toolbox_widget_                   = new QWidget(  );
    labelK                            = new QLabel( QString( tr( "Nearest Node Number:" ) ) );
    lineeditK                         = new QLineEdit( QString::number( K ) );
    connect( lineeditK, SIGNAL( textEdited( const QString& ) ), this, SLOT( slotChangeK( const QString& ) ) );
    layoutK                           = new QHBoxLayout( );
    layoutK->addWidget( labelK );
    layoutK->addWidget( lineeditK );
    
    
    construct_dg_button_              = new QPushButton( QString( tr( "Construct DeformationGraph" ) ) );
    connect( construct_dg_button_, SIGNAL( clicked(  ) ), this, SLOT( slot_construct_deformation_graph(  ) ) );

    show_deformation_graph_button_    = new QPushButton( QString( tr( "Show Deformation Graph" ) ) );
    connect( show_deformation_graph_button_, SIGNAL( clicked(  ) ), this, SLOT( show_deformation_graph(  ) ) );

    calculate_k_nearest_nodes_button_ = new QPushButton( QString( tr( "Calculate K nearest nodes" ) ) );
    connect( calculate_k_nearest_nodes_button_, SIGNAL( clicked(  ) ), this, SLOT( calculate_k_nearest_nodes(  ) ) );

    QVBoxLayout* layout               = new QVBoxLayout(  );
    layout->addLayout( layoutK );
    layout->addWidget( construct_dg_button_ );
    layout->addWidget( show_deformation_graph_button_ );
    layout->addWidget( calculate_k_nearest_nodes_button_ );
    
    toolbox_widget_->setLayout( layout );
}

void EDS::releaseWidgets(  ) {
  delete toolbox_widget_;
  delete labelK; delete lineeditK;
  delete layoutK;
  delete construct_dg_button_;
  delete show_deformation_graph_button_;
  delete calculate_k_nearest_nodes_button_;
}

void EDS::slot_construct_deformation_graph(  ) {
  int target_number = QInputDialog::getInt( NULL, QString( tr( "Please input the target_number of deformation nodes" ) ),QString( tr( "target number nodes:" ) ),50,1,mesh_->size_of_vertices(  ) );

  construct_deformation_graph( target_number );
}

/**
   \brief: private method, construct defomation graph according the given number
   @param: the target number of defomation graph nodes
*/
void EDS::construct_deformation_graph( int target_number ) {
  if( mesh_ ) {
    emit log( QString( tr( "Constructing DeformationGraph..." ) ) );
    deformation_graph_->construct( mesh_, target_number );
  } else {
    emit log( QString( tr( "You have not load a mesh for EDS plugin, please load it first" ) ) );
  }  
}

void EDS::render(  ) {
  LOG( INFO )<<"EDS::render...."<<std::endl;
  show_deformation_graph(  );
}

void EDS::show_deformation_graph(  ) {
  if( deformation_graph_ ) {
    deformation_graph_->render(  );
  }
}

/**
   \brief: calcualte vertex's k+1 nearest nodes
   \detail: use CGAL dD Spatial Search functionality,
   see CGAL manual Chapter 57 for reference
*/
void EDS::calculate_k_nearest_nodes(  ) {
  //calculate_k_nearest_nodes_using_point(  )  ;
  calculate_k_nearest_nodes_using_dgnode(  );

  normalize_vertex_node_weights(  );
}

/**private test method*/
//deprecated
void EDS::calculate_k_nearest_nodes_using_point(  ) {
  typedef CGAL::Search_traits_3<Kernel> TreeTraits;
  typedef CGAL::Orthogonal_k_neighbor_search<TreeTraits> K_neighbor_search;
  typedef K_neighbor_search::Tree Tree;

  //TODO:you should use DeformationGraphNode with id instend only the Point_3
  std::list<Point_3> graph_node_points;
  for( vector<DeformationGraphNode>::iterator pNode = deformation_graph_->nodes_.begin(  );
       pNode != deformation_graph_->nodes_.end(  ); pNode++ ) {
    graph_node_points.push_back( Point_3( pNode->position_[ 0 ],pNode->position_[ 1 ],pNode->position_[ 2 ] ) );
  }

  Tree tree( graph_node_points.begin(  ),graph_node_points.end(  ) );
  Point_3 query;
  
  for( Vertex_iterator pVertex = mesh_->vertices_begin(  );
       pVertex != mesh_->vertices_end(  ); pVertex++ ) {
    query = pVertex->point(  );
    K_neighbor_search search( tree,query,K+1 );

    std::cout<<"query is :"<<query.x( )<<","<<query.y(  )<<","<<query.z(  )<<std::endl;

    int i = 0;
    for (K_neighbor_search::iterator it = search.begin(  );
         it != search.end(  ); ++it) {
      std::cout<<"neighbor:"<<it->first<<",distance: "<<std::sqrt( it->second )<<std::endl;
      i++;
      //now , store the results
      
    }
  }  
  
}


//internal structs for k-Neighbor_search
namespace CGAL {
template <>
struct Kernel_traits<DeformationGraphNode> {
  struct Kernel {
    typedef float FT;
    typedef float RT;
  };
};
}

struct Construct_coord_iterator {
  const float* operator(  )( const DeformationGraphNode& node ) const {
    return static_cast<const float*>( node.position_ );
  }
  const float* operator(  )( const DeformationGraphNode& node, int ) const {
    return static_cast<const float*>( node.position_+3 );
  }
};

struct Distance {
  typedef DeformationGraphNode Query_item;
  double transformed_distance( const Query_item& n1, const Query_item& n2 ) const {
    double distx = n1.position_[ 0 ]-n2.position_[ 0 ];
    double disty = n1.position_[ 1 ]-n2.position_[ 1 ];
    double distz = n1.position_[ 2 ]-n2.position_[ 2 ];
    return distx*distx+disty*disty+distz*distz;    
  }

  double transformed_distance( float d ) const {
    return d*d;
  }
  double new_distance( float& dist, float& old_off, float& new_off, int& ) const {
    return dist+new_off*new_off-old_off*old_off;
  }
  

  template <typename TreeTraits>
  float min_distance_to_rectangle( const DeformationGraphNode& node,
                                   const CGAL::Kd_tree_rectangle<TreeTraits>& b) const {
    float distance( 0.0 ), h = node.position_[ 0 ];
    if( h < b.min_coord( 0 ) ) distance += ( b.min_coord( 0 )-h )*( b.min_coord( 0 )-h );
    if( h > b.max_coord( 0 ) ) distance += ( h-b.max_coord( 0 ) )*( h-b.max_coord( 0 ) );
    
    h = node.position_[ 1 ];
    if( h < b.min_coord( 1 ) ) distance += ( b.min_coord( 1 )-h )*( b.min_coord( 1 )-h );
    if( h > b.max_coord( 1 )) distance += ( h-b.max_coord( 1 ) )*( h-b.max_coord( 1 ) );

    h = node.position_[ 2 ];
    if( h<b.min_coord( 2 ) ) distance += ( b.min_coord( 2 )-h )*( b.min_coord( 2 )-h );
    if( h>b.max_coord( 2 ) ) distance += ( h-b.max_coord( 2 ) )*( h-b.max_coord( 2 ) );

    return distance;
  }

  template <typename TreeTraits>
  float max_distance_to_rectangle( const DeformationGraphNode& node,
                                   const CGAL::Kd_tree_rectangle<TreeTraits>& b) const {
    float h = node.position_[ 0 ];
    float d0 = ( h>=( b.min_coord( 0 )+b.max_coord( 0 ) )/2.0 ) ?
        ( h-b.min_coord( 0 ) )*( h-b.min_coord( 0 ) ) :
        ( b.max_coord( 0 )-h )*( b.max_coord( 0 )-h );

    h = node.position_[ 1 ];
    float d1 = ( h>=( b.min_coord( 1 )+b.max_coord( 1 ) )/2.0 ) ?
        ( h-b.min_coord( 1 )*( h-b.min_coord( 1 ) ) ) :
        ( b.max_coord( 1 )-h )*( b.max_coord( 1 )-h );

    h = node.position_[ 2 ];
    float d2 = ( h>= ( b.min_coord( 2 )+b.max_coord( 2 ) )/2.0 ) ?
        ( h-b.min_coord( 2 ) )*( h-b.min_coord( 2 ) ) :
        ( b.max_coord( 2 )-h )*( b.max_coord( 2 )-h );

    return d0+d1+d2;    
  }
};

/**private test method*/
void EDS::calculate_k_nearest_nodes_using_dgnode(  ) {
  typedef CGAL::Search_traits<float,DeformationGraphNode,const float*,Construct_coord_iterator> TreeTraits;
  typedef CGAL::Orthogonal_k_neighbor_search<TreeTraits,Distance> K_neighbor_search;
  typedef K_neighbor_search::Tree Tree;
  
  Tree tree( deformation_graph_->nodes_.begin(  ),deformation_graph_->nodes_.end(  ) );
  DeformationGraphNode query;
    
  for( Vertex_iterator pVertex = mesh_->vertices_begin(  );
       pVertex != mesh_->vertices_end(  ); pVertex++ ) {
    query.position_[ 0 ] = pVertex->point(  ).x(  );
    query.position_[ 1 ] = pVertex->point(  ).y(  );
    query.position_[ 2 ] = pVertex->point(  ).z(  );

    printf("Vertex %ld : (%.2f, %.2f, %.2f) \n", pVertex->id(),
	   pVertex->point().x(),
	   pVertex->point().y(),
	   pVertex->point().z());
    
    K_neighbor_search search( tree,query,K+1 );

    //calculat the dmax
    K_neighbor_search::iterator max_it = search.end(  );
    float max_distance = sqrt( max_it->second );
    
    //set the vertex's k-nodes&weights
    DGNodeWeight node_weight;
    Vertex_DeformationGraphNode_Vector node_weight_vector;
    float distance;
    //Begin Searching
    int i = 0;
    for (K_neighbor_search::iterator it = search.begin(  );
         it != search.end(  ); ++it) {
      LOG( INFO )<<"Result "<<i<<": "<<it->first<<"   distance:  "<< it->second <<std::endl;
      i++;
      //Store the results:
      node_weight_vector.clear(  );
      DeformationGraphNode node = it->first; //tmp convenience node
      int node_id = node.get_id(  );
      node_weight.node_id = node_id;
      
      distance = ( pVertex->point(  ).x(  )-deformation_graph_->nodes_[node_id].position_[ 0 ] )*( pVertex->point(  ).x(  )-deformation_graph_->nodes_[node_id].position_[ 0 ] ) +
          ( pVertex->point(  ).y(  )-deformation_graph_->nodes_[ node_id ].position_[ 1 ] )*( pVertex->point(  ).y(  )-deformation_graph_->nodes_[ node_id ].position_[ 1 ] ) +
          ( pVertex->point(  ).z(  )-deformation_graph_->nodes_[ node_id ].position_[ 2 ] )*( pVertex->point(  ).z(  )-deformation_graph_->nodes_[ node_id ].position_[ 2 ] );
      distance = sqrt( distance );
      node_weight.weight = ( 1-distance/max_distance )*( 1-distance/max_distance );
      //now , store the results ( see CGAL3.5 Manual( p3196 ), the result is std::pair<Point_d,FT) Point_with_transformed_distance. so first is the reslut, second is the transformed_distance. )
      node_weight_vector.push_back( node_weight );
    }//K Search
    //Store the results
    vertex_deformationgraphnodes_map_.insert( make_pair(pVertex,node_weight_vector) );      
  }  //Per Vertex
}

void EDS::normalize_vertex_node_weights(  ) {
  float weight_sum;
  Vertex_DeformationGraphNode_Vector v_k_nodes;
  for (Vertex_iterator pVertex = mesh_->vertices_begin(  );
       pVertex != mesh_->vertices_end( ); ++pVertex) {
    v_k_nodes = get( vertex_k_nearest_deformationgraphnodes_properties_,pVertex );
    weight_sum = 0.0;
    for( std::vector<DGNodeWeight>::iterator pNode = v_k_nodes.begin(  );
         pNode != v_k_nodes.end(  ); pNode++) {
      weight_sum += pNode->weight;
    }
    //normalize
    for( std::vector<DGNodeWeight>::iterator pNode = v_k_nodes.begin(  );
         pNode != v_k_nodes.end(  ); pNode++ ) {
      pNode->weight /= weight_sum;
    }
    //writeback the property
    put( vertex_k_nearest_deformationgraphnodes_properties_,pVertex,v_k_nodes );    
  }  
}


/**The eds target_name should equal to CMake's target_name*/
Q_EXPORT_PLUGIN2( eds, EDS )

//  
// 
// EDS.cpp ends here
