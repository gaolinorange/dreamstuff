#include "MeshCore/MeshCore.h"
#include <fstream>
#include <gtest/gtest.h>

class MeshCoreTest : public ::testing::Test
{
 protected:
  virtual void SetUp()
  {
    pMesh = new MeshCore();
    Halfedge_handle h = pMesh->make_tetrahedron(Point_3(0,0,0),Point_3(0,0,1),Point_3(0,1,0),Point_3(1,0,0));

    pMesh->set_indices();
  }
  virtual void TearDown()
  {
    delete pMesh;
  }

  MeshCore * pMesh;
};

TEST_F(MeshCoreTest,testInit)
{
  //do not need to add code here
}

TEST_F(MeshCoreTest,testMakeTetrahedron)
{
  Halfedge_handle h = pMesh->make_tetrahedron(Point_3(0,0,0),Point_3(0,0,1),Point_3(0,1,0),Point_3(1,0,0));
  EXPECT_EQ(true,pMesh->is_tetrahedron(h));
}

TEST_F(MeshCoreTest,testWriteTetrahedron)
{
  pMesh->make_tetrahedron();
  std::ofstream outFile("tetrahedron.off",std::ios::out);
  outFile<<(*pMesh);
}

TEST_F(MeshCoreTest,testBoundingBox)
{
  //  pMesh->make_tetrahedron();
  Halfedge_handle h = pMesh->make_tetrahedron(Point_3(0,0,0),Point_3(0,0,1),Point_3(0,1,0),Point_3(1,0,0));
  pMesh->compute_bounding_box();
  Iso_cuboid_3 box = pMesh->get_bounding_box();
  EXPECT_FLOAT_EQ(0,box.xmin());
  EXPECT_FLOAT_EQ(0,box.ymin());
  EXPECT_FLOAT_EQ(0,box.zmin());

  EXPECT_FLOAT_EQ(1,box.xmax());
  EXPECT_FLOAT_EQ(1,box.ymax());
  EXPECT_FLOAT_EQ(1,box.zmax());  
}

TEST_F(MeshCoreTest,testVertexHandlePrint)
{
  pMesh->test_print_vertex_handles(); 
}

TEST_F(MeshCoreTest,testHalfedgeHandlePrint)
{
  pMesh->test_print_halfedge_handles();
}

TEST_F(MeshCoreTest,testFacetHandlePrint)
{
  pMesh->test_print_facet_handles();
}

  
  

			   
