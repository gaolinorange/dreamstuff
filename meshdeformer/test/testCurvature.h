/* testCurvature.h --- 
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
#ifndef _TESTCURVATURE_H_
#define _TESTCURVATURE_H_

#include <gtest/gtest.h>
#include "MeshCore/MeshCore.h"
#include "Plugin-Curvature/Curvature.h"

class CurvatureTest : public ::testing::Test
{
 protected:
  virtual void SetUp(  ) {
    pMesh = new MeshCore(  );
    Halfedge_handle h = pMesh->make_tetrahedron( Point_3( 0,0,0 ),
                                                 Point_3( 0,0,1 ),
                                                 Point_3( 0,1,0 ),
                                                 Point_3( 1,0,0 )
                                                 );
    pMesh->set_indices( );
    pMesh->init_index_to_vertex_map(  );

    curvature_ = new Curvature(  );
    curvature_->setMesh( pMesh );
  }
  virtual void TearDown(  ) {
    delete pMesh;
    delete curvature_;
  }

  MeshCore* pMesh;
  Curvature * curvature_;
};

TEST_F( CurvatureTest, testInit ) {
  //no need to do things
}

TEST_F( CurvatureTest, testEdgeCotValues ) {
  curvature_->calculateEdgeCotValues(  );
  //TODO: add some assertions
  
}

TEST_F( CurvatureTest, testVoronoiAreas ) {
  curvature_->calculateVoronoiAreas(  );
  //TODO: add some assertions
  
}

TEST_F( CurvatureTest, testMeanCurvature ) {
  curvature_->slotCalculateMeanCurvatures(  );
  //TODO: add some assertions
  
}

TEST_F( CurvatureTest, testGaussianCurvature ) {
  curvature_->slotCalculateGaussianCurvatures(  );
  //TODO: add some assertions
  
}


#endif /* _TESTCURVATURE_H_ */
/* testCurvature.h ends here */
