#ifndef MESHCORE_MESHBUILDER_H
#define MESHCORE_MESHBUILDER_H

#include <CGAL/basic.h>
#include <CGAL/Polyhedron_incremental_builder_3.h>
#include "MeshLoader.h"
#include <CGAL/Polyhedron_items_with_id_3.h>
#include "MeshCore.h"

template<class HDS>
class MeshBuilder : public CGAL::Modifier_base<HDS>
{
public:
	MeshBuilder(MeshLoader * loader){
		meshloader = loader;
	}
	void operator()(HDS& hds)
	{
		CGAL::Polyhedron_incremental_builder_3<HDS> builder(hds,true);

		typedef typename HDS::Vertex Vertex;
		typedef typename HDS::Vertex::Point Point;

		builder.begin_surface(meshloader->numVertices,meshloader->numFacets);
		//add the aiMesh's vertices to this surface
		for(unsigned int i = 0; i< meshloader->numVertices; i++){
			builder.add_vertex(
				Point(meshloader->aimesh->mVertices[i][0],
				meshloader->aimesh->mVertices[i][1],
				meshloader->aimesh->mVertices[i][2])
				);
		}
		//add the facets with indices
		for(unsigned int j = 0; j < meshloader->numFacets; j++){
			builder.begin_facet();
			aiFace face = meshloader->aimesh->mFaces[j];
			for(std::size_t k = 0; k < face.mNumIndices; k++){
				builder.add_vertex_to_facet(face.mIndices[k]);
			}
			builder.end_facet();
		}
		
		builder.end_surface();
	}
private:
	MeshLoader * meshloader;
};

#endif
