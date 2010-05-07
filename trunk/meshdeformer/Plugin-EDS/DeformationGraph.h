/*-*-c++-*-
 * DeformationGraph.h --- 
 * copyright (c) 2010 dreamway
 */

/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the Free Software Foundation;
 *  Feel free to contact dreamway(jingwenlai@163.com)
 * 
 * website: cg.xplore.cn
 */

/* Commentary: 
 * 
 */
#ifndef _DEFORMATIONGRAPH_H_
#define _DEFORMATIONGRAPH_H_

#include <vector>
#include <set>
using namespace std;

#include "MeshCore/MeshCore.h"

class DeformationGraph;

class DeformationGraphNode
{
 public:
  DeformationGraphNode(  );
  DeformationGraphNode(int id);
  virtual ~DeformationGraphNode();
  
  void renderNode(  );
  void renderConnection(  );
  
  float R[ 9 ];
  float t[ 3 ];

  float position_[ 3 ];

  friend ostream& operator<<( ostream& out, const DeformationGraphNode& node );
  set<int> neighbor_nodes_;
 public:
  void set_parent_deformation_graph( DeformationGraph* _graph );
 private:
  DeformationGraph* parent_graph_;
 public:
  void insert_neighbor_node( const int _neighbor_id );
  void set_id( int _id );
  int get_id(  );
  //debug helper
  void print(  );
 public:
  void set_node_size( float _size );
  float node_size(  );
  void set_node_color( float _color[ 3 ] );
  void set_connection_color( float _color[ 3 ] );
 private:
  int id_;
 private://for rendering
  float node_size_;
  float node_color_[ 3 ];
  float connection_color_[ 3 ];
};



class DeformationGraph
{
 public:
  DeformationGraph();
  virtual ~DeformationGraph();
 public:
  void construct( MeshCore* _mesh, int _target_number );
  void render(  );

  void print(  );//debug helper

  void set_connection_color( float _color[ 3 ] );
  void set_node_size( float _size );
  void set_node_color( float _color[ 3 ] );
  
  //Shared internal data
  std::vector<DeformationGraphNode> nodes_;
  int num_nodes;
 private:
  MeshCore* mesh_;
};


  


#endif /* _DEFORMATIONGRAPH_H_ */
/* DeformationGraph.h ends here */
