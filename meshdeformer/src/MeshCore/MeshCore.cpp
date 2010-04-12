// MeshCore.cpp --- The fundamental class for establish the Polyhedron
// copyright (c) 2010 dreamway
// 
//  This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free Software Foundation;
//  Free free to contact dreamway(jingwenlai@163.com)
// 
// website: cg.xplore.cn
// 
// 

// Commentary: 
// 
// 


#include "glheaders.hpp"
#include "MeshCore.h"


MeshCore::MeshCore()
{
}

MeshCore::~MeshCore()
{
}

void MeshCore::render()
{
  //Render the outline
  Vertex_handle v0,v1;
  for(Halfedge_iterator pHalfedge = halfedges_begin();
      pHalfedge != halfedges_end(); pHalfedge++)
    {
      v0 = pHalfedge->vertex();
      v1 = pHalfedge->opposite()->vertex();
      glBegin(GL_LINES);
      glVertex3f(v0->point().x(),v0->point().y(),v0->point().z());
      glVertex3f(v1->point().x(),v1->point().y(),v1->point().z());
      glEnd();
    }

  //Render facets
	Halfedge_around_facet_circulator pHalfedge;
	for(Facet_iterator pFacet = facets_begin();
		pFacet != facets_end(); pFacet++){
			glBegin(GL_POLYGON);
			pHalfedge = pFacet->facet_begin();
			do{
				Point_3 point = pHalfedge->vertex()->point();
				glVertex3f(point[0],point[1],point[2]);
			}while(++pHalfedge != pFacet->facet_begin());
			glEnd();
	}
}


void MeshCore::set_vertex_indices()
{
  std::size_t vertex_id = 0;
    
  for(Vertex_iterator vit = vertices_begin();
      vit != vertices_end(); vit++){
    vit->id() = vertex_id++;    
  }
}

void MeshCore::set_facet_indices()
{
  std::size_t facet_id = 0;
  
  for(Facet_iterator fit = facets_begin();
      fit != facets_end(); fit++){
    fit->id() = facet_id++;
  }
}

void MeshCore::set_halfedge_indices()
{
  std::size_t halfedge_id = 0;

  for(Halfedge_iterator hit = halfedges_begin();
      hit != halfedges_end(); hit++){
    hit->id() = halfedge_id++;
  }
}

void MeshCore::set_indices()
{
  set_vertex_indices();
  set_facet_indices();
  set_halfedge_indices();
}



void MeshCore::compute_bounding_box()
{
  if(size_of_vertices() == 0)
    return;

  FT xmin,xmax,ymin,ymax,zmin,zmax;
  Vertex_iterator pVertex = vertices_begin();
  xmin = xmax = pVertex->point().x();
  ymin = ymax = pVertex->point().y();
  zmin = zmax = pVertex->point().z();

  for( ; pVertex != vertices_end(); pVertex++){
    const Point_3& p = pVertex->point();

    xmin = std::min(xmin,p.x());
    ymin = std::min(ymin,p.y());
    zmin = std::min(zmin,p.z());

    xmax = std::max(xmax,p.x());
    ymax = std::max(ymax,p.y());
    zmax = std::max(zmax,p.z());
  }

  bounding_box_ = Iso_cuboid_3(xmin,ymin,zmin,
			       xmax,ymax,zmax);
}


unsigned int MeshCore::degree(Facet_handle pFacet)
{
  return pFacet->facet_degree( );
}

unsigned int MeshCore::valence(Vertex_handle pVertex)
{
  int valence = 0 ;
  return pVertex->vertex_degree( );  
}

void MeshCore::compute_normals_per_facet()
{
  
}

void MeshCore::compute_normals_per_vertex()
{

  
}


void MeshCore::test_print_vertex_handles()
{
  Vertex_handle pVertex;
  for (pVertex = vertices_begin(); pVertex != vertices_end(); pVertex++)
  {
    //    std::cerr<<"id: "<<pVertex->id()<<"handle: "<<pVertex<<std::endl;
    std::cerr<<"id: "<<pVertex->id()<<std::endl;
  }
}

void MeshCore::test_print_halfedge_handles()
{
  Halfedge_handle pHalfedge;
  for (pHalfedge = halfedges_begin(); pHalfedge != halfedges_end(); pHalfedge++)
  {
    std::cerr<<"id: "<<pHalfedge->id()<<std::endl;    
  }
}

void MeshCore::test_print_facet_handles()
{
  Facet_handle pFacet;
  for (pFacet = facets_begin() ; pFacet != facets_end(); pFacet++)
  {
    std::cerr<<"id: "<<pFacet->id()<<std::endl;    
  }  
}

Vertex_handle MeshCore::get_vertex_handle(std::size_t idx)
{
  if(idx < size_of_vertices())
    return index_to_vertex_map[idx];
  return Vertex_handle();
}

void MeshCore::init_index_to_vertex_map()
{
  for(Vertex_iterator pVertex = vertices_begin();
      pVertex != vertices_end(); pVertex++){
    index_to_vertex_map.push_back(pVertex);
  }
}







// 
// MeshCore.cpp ends here
