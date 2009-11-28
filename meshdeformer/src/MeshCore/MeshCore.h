#ifndef MESHCORE_H
#define MESHCORE_H

#include <CGAL/Cartesian.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>

#define KernelType float


typedef CGAL::Cartesian<KernelType> Kernel;
typedef Kernel::Vector_3 Vector_3;
typedef Kernel::Point_3 Point_3;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;

typedef Polyhedron::Vertex Vertex;
typedef Polyhedron::Vertex_iterator Vertex_iterator;
typedef Polyhedron::Vertex_handle Vertex_handle;
typedef Polyhedron::Halfedge_iterator Halfedge_iterator;
typedef Polyhedron::Halfedge_handle Halfedge_handle;
typedef Polyhedron::Edge_iterator Edge_iterator;

typedef Polyhedron::Facet_handle Facet_handle;
typedef Polyhedron::Facet_iterator Facet_iterator;
typedef Polyhedron::Halfedge_around_vertex_const_circulator Halfedge_around_vertex_const_circulator;
typedef Polyhedron::Halfedge_around_vertex_circulator Halfedge_around_vertex_circulator;
typedef Polyhedron::Halfedge_around_facet_circulator Halfedge_around_facet_circulator;

class MeshCore : public Polyhedron
{
 public:
  MeshCore();
  ~MeshCore();
 public:
  void render();
};
  
  
  
#endif
