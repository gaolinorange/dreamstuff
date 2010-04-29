// -*-c++-mode-*-
//testMeshBuilder.h --- Test MeshBuilder for mesh loading
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
#ifndef TEST_MESHBUILDER_H
#define TEST_MESHBUILDER_H

#include <gtest/gtest.h>
#include "MeshCore/MeshLoader.h"
#include "MeshCore/MeshBuilder.h"
#include "MeshCore/MeshCore.h"
#include <QString>

class MeshBuilderTest : public ::testing::Test
{
public:
  virtual void SetUp( ) {
    printf( "Setting Up MeshBuilderTest...\n" );
    
    mesh_loader_ = new MeshLoader( );
    mesh_ = new MeshCore( );
    QString filename = QString( "../test/test_data/test_tetrahedron.off" );
    bool ret = mesh_loader_->load( filename.toAscii( ).data( ) );
    EXPECT_EQ( true, ret );
    if( ret == false )
    {
     printf( "Warning: mesh_loader_ load file failed.\n");
     printf( "Message: maybe the path of the data is wrong?\n" );
    }
    else{
      MeshBuilder<Polyhedron::HalfedgeDS> builder( mesh_loader_ );
      mesh_->delegate( builder );
      mesh_->set_indices( );
    }
  }
  virtual void TearDown(  ) {
    printf( "Tearing Down MeshBuilderTest...\n" );
    delete mesh_loader_;
    delete mesh_;
  }

  MeshLoader* mesh_loader_;
  MeshCore* mesh_;
};

TEST_F( MeshBuilderTest, testInit ) {
  /*do nothing*/  
}

TEST_F( MeshBuilderTest, testPrintVertex )
{
  for (Vertex_iterator pVertex = mesh_->vertices_begin( );
       pVertex != mesh_->vertices_end( ); pVertex++)
  {
    printf( "%ld: ( %.2f,%.2f,%.2f ) \n", pVertex->id( ),
            pVertex->point( ).x( ),
            pVertex->point( ).y( ),
            pVertex->point( ).z( ));  
  }  
}

#endif

// 
// testMeshBuilder.h ends here
