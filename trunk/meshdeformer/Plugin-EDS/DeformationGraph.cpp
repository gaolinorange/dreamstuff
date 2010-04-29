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

/////////////DeformationGraph////////////////
DeformationGraph::DeformationGraph(  ) {
  nodes_.clear(  );
}

DeformationGraph::~DeformationGraph(  ) {
  nodes_.clear(  );
}


void DeformationGraph::construct( MeshCore* _mesh  ) {
  mesh_ = _mesh;
  
}
/**
   \brief: render the deformation graph
*/
void DeformationGraph::render(  ) {
  
}

//  
// 
// DeformationGraph.cpp ends here
