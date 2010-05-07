#ifndef MESHCORE_MESHLOADER_H
#define MESHCORE_MESHLOADER_H

#include "assimp.hpp" //C++ importer interface
#include "aiScene.h"
#include "aiMesh.h"
#include "aiTypes.h"
#include "aiPostProcess.h" //Post processing flag

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
    //Important: see assimp source code for references
    //note: the flags are ( part, see assimp.sourceforge.net for more details )
    // aiProcess_JoinIdenticalVertices
		const aiScene* scene = aiImporter->ReadFile(filename,aiProcess_JoinIdenticalVertices);
		if(NULL == scene)
		{
			//		QMessageBox::warning(this,QString(QObject::tr("warning")),QString(QObject::tr("could not load the mesh")));
			std::cerr<<"could not load the mesh in MeshLoader";
      std::cerr<<aiImporter->GetErrorString(  );
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
