
#include "glheaders.hpp"
#include "MeshCore.h"
//#include <QtDebug>
//#include <QtGlobal>

MeshCore::MeshCore()
{
}

MeshCore::~MeshCore()
{
}

void MeshCore::render()
{
	/*
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
    }*/
	Halfedge_around_facet_circulator pHalfedge;
	//Vertex_handle pVertex;
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


BoundingBox& MeshCore::getBoundingBox()
{
	BoundingBox box;
	box.d_min_x = box.d_min_y = box.d_min_z = FLT_MAX;
	box.d_max_x = box.d_max_y = box.d_max_z = -FLT_MAX;

	//loop throught the vertices and foind the minimal & maximal
	Point_iterator pPoint;
	for(pPoint = points_begin(); pPoint != points_end(); pPoint++){
		if((*pPoint)[0] < box.d_min_x)  box.d_min_x = (*pPoint)[0];
		if((*pPoint)[0] > box.d_max_x) box.d_max_x = (*pPoint)[0];
		if((*pPoint)[1] < box.d_min_y) box.d_min_y = (*pPoint)[1];
		if((*pPoint)[1] > box.d_max_y) box.d_max_y = (*pPoint)[1];
		if((*pPoint)[2] < box.d_min_z) box.d_min_z = (*pPoint)[2];
		if((*pPoint)[2] > box.d_max_z) box.d_max_z = (*pPoint)[2];
	}


	return box;
}