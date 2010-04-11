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
    pMesh->init_index_to_vertex_map();
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
//  pMesh->make_tetrahedron();
  std::ofstream outFile("test_tetrahedron.off",std::ios::out);
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

TEST_F(MeshCoreTest,testInitIndexToVertexMap)
{
  pMesh->init_index_to_vertex_map();

  //Verify it by comparing the position of index_to_vertex_map
  //print by using builder
  for(Vertex_iterator pVertex = pMesh->vertices_begin();
      pVertex != pMesh->vertices_end(); pVertex++)
  {
    printf("id: %ld, pos: (%.2f,%.2f,%.2f)\n",pVertex->id(),
           pVertex->point().x(),
           pVertex->point().y(),
           pVertex->point().z());
  }
  //print by using index_to_vertex_map
  std::size_t num_vertices = pMesh->size_of_vertices();
  for (std::size_t i = 0; i < num_vertices; ++i)
  {
    printf("id : %ld, pos: (%.2f,%.2f,%.2f)\n",i,
           pMesh->get_vertex_handle(i)->point().x(),
           pMesh->get_vertex_handle(i)->point().y(),
           pMesh->get_vertex_handle(i)->point().z()
           );    
  }

  //Verify for furthing testing
  std::size_t i = 0;
  for (Vertex_iterator pVertex = pMesh->vertices_begin(); pVertex != pMesh->vertices_end(); pVertex++)
  {
    EXPECT_EQ(i,pVertex->id());
    Point_3 vertex_pos = pVertex->point();
    Point_3 vertex_pos_by_idx = pMesh->get_vertex_handle(i)->point();
    EXPECT_FLOAT_EQ(vertex_pos.x(),vertex_pos_by_idx.x());
    EXPECT_FLOAT_EQ(vertex_pos.y(),vertex_pos_by_idx.y());
    EXPECT_FLOAT_EQ(vertex_pos.z(),vertex_pos_by_idx.z());

    i++;
  }  
}
      
      
  

			   
