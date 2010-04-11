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
    mesh_loader_ = new MeshLoader( );
    mesh_ = new MeshCore( );
    QString filename = QString( "../test_data/test_tetrahedron.off" );
    boot ret = mesh_loader_->load( filename.toAscii( ).data( ) );
    EXPECT_EQ( true, ret );
    if( ret == false )
      printf( "mesh_loader_ load file failed.\n");
    else{
      MeshBuilder<Polyhedron::HalfedgeDS> builder( mesh_loader_ );
      mesh_->delegate( builder );
      mesh_->set_indices( );
    }
  }
  virtual void TearDown(  ) {
    delete mesh_loader_;
    delete mesh_;
  }

  MeshLoader* mesh_loader_;
  MeshCore* mesh_;
};

TEST_F( MeshBuilderTest, testPrintVertex )
{
  for (Vertex_iterator pVertex = mesh_->verices_begin( );
       pVertex != mesh_->vertices_end( ); pVertex++)
  {
    printf( "%ld: ( %.2f,%.2f,%.2f ) \n", pVertex->id( ),
            pVertex->point( ).x( ),
            pVertex->point( ).y( ),
            pVertex->point( ).z( ));  
  }  
}

#endif
