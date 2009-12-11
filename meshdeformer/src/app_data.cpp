#include "app_data.h"
#include "MeshCore/MeshCore.h"
#include "MeshCore/MeshBuilder.h"
#include "MeshCore/MeshLoader.h"
#include "QOutputLogger.hpp"
#include <QtDebug>

#include <QtGui>
#include <QtCore>


AppData::AppData()
{
  pMesh = 0;
}

AppData::~AppData()
{
  if(pMesh)
    {
      delete pMesh; pMesh =0;
    }
}

void AppData::initATetrahedron()
{
  if(pMesh == 0)
    pMesh = new MeshCore();

  pMesh->make_tetrahedron(Point_3(0,0,0),Point_3(1,0,0),Point_3(0,1,0),Point_3(0,0,1));

  qDebug()<<pMesh->is_pure_triangle()<<" pMesh is pure_triangle?";
}

bool AppData::loadMesh(const QString& filename)
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
	  QOutputLogger::getInstance()->appendMessage(QString(QObject::tr("MeshLoader failed to load the mesh")));
  }
  else
	  QOutputLogger::getInstance()->appendMessage(QString(QObject::tr("MeshLoader load the mesh ok")));

  MeshBuilder<Polyhedron::HalfedgeDS> builder(loader);
  pMesh->delegate(builder);

  QString message;
  QTextStream(&message)<<"Mesh info: vertices num: "<<pMesh->size_of_vertices()<<" facet num: "<<pMesh->size_of_facets();
  QOutputLogger::getInstance()->appendMessage(message);

  delete loader;//delete local meshloader to save memory

  return true;						  
}

void AppData::update()
{
}

void AppData::render()
{
  if(pMesh)
    {
      pMesh->render();
    }
}

