/* testDeformationGraphCube.h --- test DeformationGraph by loading test Cube
 * copyright (c) 2010 dreamway
 */

/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the Free Software Foundation;
 *  Feel free to contact dreamway(jingwenlai@163.com)
 * 
 * website: cg.xplore.cn
 */

/* Commentary: 
 * Test DeformationGraph by loading a Cube, This test case
 * is derived by MeshBuilder Test case, simply the loading processing
 * of test mesh( cube.off )
 */
#ifndef _TESTDEFORMATIONGRAPHCUBE_H_
#define _TESTDEFORMATIONGRAPHCUBE_H_


#include <QtDebug>

#include "MeshCore/MeshCore.h"
#include "MeshCore/MeshLoader.h"
#include "MeshCore/MeshBuilder.h"
#include <QString>
#include <gtest/gtest.h>
#include "../Plugin-EDS/DeformationGraph.h"

/**
   Test wheather I can use the MeshBuilder loading method to
   investigate further functions
 */
class DeformationGraphCubeTest : public ::testing::Test {
protected:
  virtual void SetUp( ){
    mesh_loader_ = new MeshLoader( );
    mesh_ = new MeshCore( );
    QString filename = QString( "../test/test_data/test_cube.off" );
    bool ret = mesh_loader_->load( filename.toAscii( ).data( ) );
    EXPECT_EQ( true, ret );
    if( ret == false )
    {
      printf( "Warning: mesh_loader_ load file failed.\n");
      qDebug(  )<<"filename: "<<filename;
      printf( "Message: maybe the path of the data is wrong?\n" );
    }
    else{
      MeshBuilder<Polyhedron::HalfedgeDS> builder( mesh_loader_ );
      mesh_->delegate( builder );
      mesh_->set_indices( );
    }

    deformation_graph_ = new DeformationGraph(  );
  }

  virtual void TearDown(  ) {
    delete deformation_graph_;
    delete mesh_loader_;
    delete mesh_;
  }

  
  MeshLoader* mesh_loader_;
  MeshCore* mesh_;

  DeformationGraph* deformation_graph_;
};

TEST_F( DeformationGraphCubeTest, testInit ) {
  /* no need to do things*/
}

TEST_F( DeformationGraphCubeTest, testPrintVertex )
{
  for (Vertex_iterator pVertex = mesh_->vertices_begin( );
       pVertex != mesh_->vertices_end( ); pVertex++)
  {
    printf( "%ld: ( %.2f,%.2f,%.2f ) \n", pVertex->id( ),
            pVertex->point( ).x( ),
            pVertex->point( ).y( ),
            pVertex->point( ).z( ));  
  }
  EXPECT_EQ( 8,mesh_->size_of_vertices(  ) );  
}

TEST_F( DeformationGraphCubeTest,testConstruct ) {
  assert( deformation_graph_ != NULL );
  deformation_graph_->construct( mesh_,4 );
  //TODO: the above should 
  EXPECT_EQ( 8,deformation_graph_->num_nodes(  ) );
}

#endif /* _TESTDEFORMATIONGRAPHCUBE_H_ */

/* testDeformationGraphCube.h ends here */
