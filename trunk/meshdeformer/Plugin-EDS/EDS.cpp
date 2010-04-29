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

#include "EDS.h"

void EDS::construct_deformation_graph(  ) {
  if( mesh_ ) {
    int target_number = QInputDialog::getInt( NULL, QString( tr( "Please input the target_number of deformation nodes" ) ),QString( tr( "target number nodes:" ) ),50,1,mesh_->size_of_vertices(  ) );
    emit log( QString( tr( "Constructing DeformationGraph..." ) ) );
    deformation_graph_->construct( mesh_, target_number );
  } else {
    emit log( QString( tr( "You have not load a mesh for EDS plugin, please load it first" ) ) );
  }  
}

/**The eds target_name should equal to CMake's target_name*/
Q_EXPORT_PLUGIN2( eds, EDS )

//  
// 
// EDS.cpp ends here
