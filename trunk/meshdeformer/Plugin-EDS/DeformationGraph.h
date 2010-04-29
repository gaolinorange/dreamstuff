/* -*- c++-mode -*- DeformationGraph.h --- 
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
using namespace std;

#include "MeshCore/MeshCore.h"

class DeformationGraphNode
{
 public:
  DeformationGraphNode();
  virtual ~DeformationGraphNode();

  void renderNode(  );
  void renderConnection(  );
  
  float R[ 9 ];
  float t[ 3 ];

  float position_[ 3 ];

  vector<DeformationGraphNode> kNearestNodes_;
};

class DeformationGraph
{
 public:
  DeformationGraph();
  virtual ~DeformationGraph();
 public:
  void construct( MeshCore* _mesh, int _target_number );
  void render(  );
 private:
  vector<DeformationGraphNode> nodes_;
  int num_nodes;
  MeshCore* mesh_;
};


#endif /* _DEFORMATIONGRAPH_H_ */
/* DeformationGraph.h ends here */
