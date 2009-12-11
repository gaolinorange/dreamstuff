#ifndef MESHCORE_H
#define MESHCORE_H

#include <CGAL/basic.h>
//#include <CGAL/Cartesian.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>
#include <CGAL/Polyhedron_incremental_builder_3.h>

#define KernelType float


//typedef CGAL::Cartesian<KernelType> Kernel;
typedef CGAL::Simple_cartesian<KernelType> Kernel;
typedef Kernel::Vector_3 Vector_3;
typedef Kernel::Point_3 Point_3;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;


typedef Polyhedron::Vertex Vertex;
typedef Polyhedron::Vertex_iterator Vertex_iterator;
typedef Polyhedron::Vertex_handle Vertex_handle;
typedef Polyhedron::Halfedge_iterator Halfedge_iterator;
typedef Polyhedron::Halfedge_handle Halfedge_handle;
typedef Polyhedron::Edge_iterator Edge_iterator;
typedef Polyhedron::Point_iterator Point_iterator;

typedef Polyhedron::Facet_handle Facet_handle;
typedef Polyhedron::Facet_iterator Facet_iterator;
typedef Polyhedron::Halfedge_around_vertex_const_circulator Halfedge_around_vertex_const_circulator;
typedef Polyhedron::Halfedge_around_vertex_circulator Halfedge_around_vertex_circulator;
typedef Polyhedron::Halfedge_around_facet_circulator Halfedge_around_facet_circulator;

/**
@brief:
The BoundingBox for retrieving the mesh's info
*/
class BoundingBox
{
public:
	BoundingBox(){}
	~BoundingBox(){}
	BoundingBox(const BoundingBox& box)
	{
		d_min_x = box.d_min_x; d_min_y = box.d_min_y; d_min_z = box.d_min_z;
		d_max_x = box.d_max_x; d_max_y = box.d_max_y; d_max_z = box.d_max_z;
	}
public:
	KernelType d_min_x,d_min_y,d_min_z;
	KernelType d_max_x,d_max_y,d_max_z;
};
/**
@brief: MeshCore is the core object representing the mesh
*/
class MeshCore : public Polyhedron
{
 public:
  MeshCore();
  ~MeshCore();
 public:
  void render();
  BoundingBox& getBoundingBox();
};
  
  
  
#endif
