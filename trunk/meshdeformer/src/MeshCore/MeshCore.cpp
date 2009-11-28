#include "glheaders.hpp"
#include "MeshCore.h"
#include <QtDebug>

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
	qDebug()<<"begin mesh";
	for(Facet_iterator pFacet = facets_begin();
		pFacet != facets_end(); pFacet++){
			glBegin(GL_POLYGON);
			pHalfedge = pFacet->facet_begin();
			qDebug()<<"begin facet";
			do{
	//			pVertex = pHalfedge->vertex();
	/*			glVertex3f(pVertex->point().x(),
					pVertex->point().y(),
					pVertex->point().z());
					*/
				Point_3 point = pHalfedge->vertex()->point();
				glVertex3f(point[0],point[1],point[2]);
				qDebug()<<point[0]<<","<<point[1]<<","<<point[2];
//				qDebug()<<pVertex->point().x()<<","<<pVertex->point().y()<<","<<pVertex->point().z();
			}while(++pHalfedge != pFacet->facet_begin());
			glEnd();
			qDebug()<<"end facet";
	}
	qDebug()<<"end mesh";
}
