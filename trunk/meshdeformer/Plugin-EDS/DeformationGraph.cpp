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
#include "DeformationGraph.h"

/////////////DeformationGraphNode///////////////
DeformationGraphNode::DeformationGraphNode(  ) {
  
}

DeformationGraphNode::~DeformationGraphNode(  ) {
  
}

void DeformationGraphNode::renderNode(  ) {
  printf( "todo: glrendering,currnet, just print it: node position: ( %.2f,%.2f,%.2f )\n",
          position_[ 0 ],position_[ 1 ],position_[ 2 ]);
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
