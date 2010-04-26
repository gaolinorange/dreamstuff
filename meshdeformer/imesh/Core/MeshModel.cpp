#include "MeshModel.h"
#include "MeshCore/MeshCore.h"
#include "MeshCore/MeshBuilder.h"
#include "MeshCore/MeshLoader.h"

#include "widgets/consoleWidgets/ConsoleWidgetManager.h"
#include <QtDebug>

#include <QtGui>
#include <QtCore>


MeshModel::MeshModel()
{
  pMesh = 0;
}

MeshModel::~MeshModel()
{
  if(pMesh)
    {
      delete pMesh; pMesh =0;
    }
}

bool MeshModel::loadMesh(const QString& filename)
{
  // converte aiMesh to MeshCore format
  if(pMesh)
    {
      delete pMesh; pMesh = 0;
    }
  if(pMesh == 0)
    pMesh = new MeshCore();
//TODO: copy the data in aiMesh to MeshCore style pMesh
  MeshLoader * loader = new MeshLoader();
  bool ret = loader->load(filename.toAscii().data());
  if(ret == false)
  {
	 emit log(QString("MeshLoader failed to load the mesh"));
  }
  else{
    emit log(QString(QObject::tr("MeshLoader load the mesh ok")));
  }
  
  MeshBuilder<Polyhedron::HalfedgeDS> builder(loader);
  pMesh->delegate(builder);
  pMesh->set_indices();

  QString message;
  QTextStream(&message)<<"Mesh info: vertices num: "<<pMesh->size_of_vertices()<<" facet num: "<<pMesh->size_of_facets();
  emit log(message);

  delete loader;//delete local meshloader to save memory

  return true;						  
}

void MeshModel::render()
{
  if(pMesh)
    {
      pMesh->render();
    }
}

