#ifndef MESHCORE_MESHLOADER_H
#define MESHCORE_MESHLOADER_H

#include "assimp.hpp"
#include "aiScene.h"
#include "aiMesh.h"
#include "aiTypes.h"

#include <iostream>

class MeshLoader
{
public:
	MeshLoader()
	{
		numVertices = 0;
		numFacets = 0;
		aimesh = 0;
	}
	~MeshLoader()
	{
		if(aimesh)
			delete aimesh;
	}

	bool load(const char* filename)
	{
		Assimp::Importer * aiImporter = new Assimp::Importer();
		const aiScene* scene = aiImporter->ReadFile(filename,0);
		if(NULL == scene)
		{
			//		QMessageBox::warning(this,QString(QObject::tr("warning")),QString(QObject::tr("could not load the mesh")));
			std::cerr<<"could not load the mesh in MeshLoader";
			return false;
		}
		std::cout<<"num of meshes: "<<scene->mNumMeshes<<std::endl;
		if(scene->HasMeshes() == false)
		{
			std::cout<<"the scene has no meshes";
			return false;
		}

		//currently, Only deal with one mesh
		aimesh = scene->mMeshes[0];
		numVertices = aimesh->mNumVertices;
		numFacets = aimesh->mNumFaces;

		std::cout<<"numVertices: "<<numVertices<<"   numFacets: "<<numFacets<<std::endl;

		return true;
	}
public:
	unsigned int numVertices;
	unsigned int numFacets;
	aiMesh * aimesh;
};

#endif