// DeformationGraph.cpp --- 
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
#include "Common/glheaders.hpp"
#include "DeformationGraph.h"

/////////////DeformationGraphNode///////////////
DeformationGraphNode::DeformationGraphNode(  ) {
  
}

DeformationGraphNode::~DeformationGraphNode(  ) {
  
}

float DeformationGraphNode::node_size(  ) {
  return node_size_;
}
void DeformationGraphNode::set_node_size( float _size ) {
  node_size_ = _size;
}
void DeformationGraphNode::set_node_color( float _color[ 3 ] ) {
  node_color_[ 0 ] = _color[ 0 ];
  node_color_[ 1 ] = _color[ 1 ];
  node_color_[ 2 ] = _color[ 2 ];
}


void DeformationGraphNode::renderNode(  ) {  
  glTranslatef( position_[ 0 ],position_[ 1 ],position_[ 2 ] );
  glColor3f( node_color_[ 0 ],node_color_[ 1 ],node_color_[ 2 ] );
  glutSolidSphere( node_size_, 10, 10 );
}

void DeformationGraphNode::renderConnection(  ) {
  printf("todo: glrendering\n"  );
  //Print neighbor nodes
  for (vector<DeformationGraphNode>::iterator pNode = kNearestNodes_.begin(  );
       pNode != kNearestNodes_.end(); ++pNode) {
    printf( "connection: ( %.2f,%.2f,%.2f ) <=> ( %.2f,%.2f,%.2f )\n",
            position_[ 0 ],position_[ 1 ],position_[ 2 ],
            pNode->position_[ 0 ],pNode->position_[ 1 ],pNode->position_[ 2 ]);
  }
}

/////////////DeformationGraph////////////////
DeformationGraph::DeformationGraph(  ) {
  nodes_.clear(  );
}

DeformationGraph::~DeformationGraph(  ) {
  nodes_.clear(  );
}


void DeformationGraph::construct( MeshCore* _mesh, int _target_number  ) {
  mesh_ = _mesh;
  num_nodes = _target_number;//note:it's just a temp number, actually, the algorithm could not just generate exteractly the number of nodes

  int num_vertices = mesh_->size_of_vertices(  );
  float ratio = (float)num_vertices/_target_number;

  float average_edge_length = mesh_->get_average_edge_length(  );
  float expected_tuncate_squared_length = average_edge_length*average_edge_length * ratio; //for efficiency: use the squared_length
    
  std::list<Point_3> searching_lists;
  searching_lists.clear(  );
  //init with all vertices
  for (Vertex_iterator pVertex = mesh_->vertices_begin(  );
       pVertex != mesh_->vertices_end(); pVertex++) {
    searching_lists.push_back( pVertex->point(  ) );
  }


  //loop this list and delete the points distance less than *expected_tuncate_length*
  std::list<Point_3>::iterator pBeginIterator = searching_lists.begin(  ),pSearchIterator;
  float distance;
  for(   ; pBeginIterator != searching_lists.end(); pBeginIterator++ ) {    
    pSearchIterator = pBeginIterator;
    pSearchIterator++;
    for(  ; pSearchIterator != searching_lists.end(  );  ) {
      distance = Vector_3( (*pSearchIterator)-(*pBeginIterator) ).squared_length(  );
      
      if( distance < expected_tuncate_squared_length ) {
         pSearchIterator = searching_lists.erase( pSearchIterator );
      }
      else
         pSearchIterator++;
    }
  }

  //now, all points stored in this list have ideal distances
  //TODO: store it
  nodes_.clear(  );
  DeformationGraphNode node;
  for (std::list<Point_3>::iterator pPoint = searching_lists.begin(  );
       pPoint != searching_lists.end(); ++pPoint) {
    node.position_[ 0 ] = pPoint->x(  );
    node.position_[ 1 ] = pPoint->y(  );
    node.position_[ 2 ] = pPoint->z(  );
    nodes_.push_back( node );
  }

  num_nodes = nodes_.size(  ); //this is the final number of deformation graph nodes
}

/**
   \brief: render the deformation graph
*/
void DeformationGraph::render(  ) {
  for (vector<DeformationGraphNode>::iterator pNode = nodes_.begin(  );
       pNode != nodes_.end(  ); ++pNode) {
    pNode->renderNode(  );
    pNode->renderConnection(  );
  }
}

//  
// 
// DeformationGraph.cpp ends here
