/* testLoadingDifferentMesh.h ---
 * test loading different type of mesh using MeshLoader and MeshBuilder
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
 #ifndef _TESTLOADINGDIFFERENTMESH_H_
#define _TESTLOADINGDIFFERENTMESH_H_


#include <gtest/gtest.h>
#include "MeshCore/MeshLoader.h"
#include "MeshCore/MeshBuilder.h"
#include "MeshCore/MeshCore.h"
#include <QString>


class MeshFormatLoadingTest : public ::testing::Test
{
 public:
  MeshFormatLoadingTest() {
    mesh_loader_ = new MeshLoader(  );
    mesh_ = new MeshCore(  );
  }
  virtual ~MeshFormatLoadingTest() {
    delete mesh_loader_;
    delete mesh_;
  }

  bool load_mesh( const QString& filename ) {
    bool ret = mesh_loader_->load( filename.toAscii( ).data( ) );
    EXPECT_EQ( true, ret );
    if( ret == false )
    {
     printf( "Warning: mesh_loader_ load file failed.\n");
     printf( "Message: maybe the path of the data is wrong?\n" );
     return false;
    }
    else{
      MeshBuilder<Polyhedron::HalfedgeDS> builder( mesh_loader_ );
      mesh_->delegate( builder );
      mesh_->set_indices( );

      return true;
    }
  }

  MeshLoader* mesh_loader_;
  MeshCore* mesh_;
};

TEST_F( MeshFormatLoadingTest, testInit ) {
  //no need to do things
}

TEST_F( MeshFormatLoadingTest, testLoadAsciiPly ) {
  QString filename = QString( "../test/test_data/cube.ply" );
  bool ret = load_mesh( filename );
  EXPECT_EQ( true,ret );
  EXPECT_EQ( 8,mesh_->size_of_vertices(  ) );
}

/*
TEST_F( MeshFormatLoadingTest, testLoadBinaryPly ) {
  QString filename = QString( "../test/test_data/cow_binary_ply.ply" );
  bool ret = load_mesh( filename );
  EXPECT_EQ( true,ret );  
  }
*/

TEST_F( MeshFormatLoadingTest, testLoadOff ) {
  QString filename = QString( "../test/test_data/large_cube.off" );
  bool ret = load_mesh( filename );
  EXPECT_EQ( true,ret );  
}

TEST_F( MeshFormatLoadingTest,testLoad3ds ) {
  QString filename = QString( "../test/test_data/Pedestal.3ds" );
  bool ret = load_mesh( filename );
  EXPECT_EQ( true,ret );

  filename = QString( "../models/64david-sculpture.3DS" );
  ret = load_mesh( filename );
  EXPECT_EQ( true,ret );
}


TEST_F( MeshFormatLoadingTest,testLoadObj ) {
  QString filename;
  bool ret;

  filename = QString( "../models/cube.obj" );
  ret = load_mesh( filename );
  EXPECT_EQ( true,ret );
}




#endif /* _TESTLOADINGDIFFERENTMESH_H_ */
/* testLoadingDifferentMesh.h ends here */
