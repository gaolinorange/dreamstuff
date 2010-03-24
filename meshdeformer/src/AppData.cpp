#include "AppData.h"
#include "MeshCore/MeshCore.h"
#include "MeshCore/MeshBuilder.h"
#include "MeshCore/MeshLoader.h"

#include "ConsoleWidget.h"
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
  pMesh->set_indices();
  
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
	 ConsoleWidget::getInstance()->logMessage(QString(QObject::tr("MeshLoader failed to load the mesh")));
  }
  else
	 ConsoleWidget::getInstance()->logMessage(QString(QObject::tr("MeshLoader load the mesh ok")));

  MeshBuilder<Polyhedron::HalfedgeDS> builder(loader);
  pMesh->delegate(builder);
  pMesh->set_indices();

  QString message;
  QTextStream(&message)<<"Mesh info: vertices num: "<<pMesh->size_of_vertices()<<" facet num: "<<pMesh->size_of_facets();
  ConsoleWidget::getInstance()->logMessage(message);

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

void AppData::printBoundingBox()
{
	if(pMesh){
		BoundingBox box = pMesh->getBoundingBox();
		QString message;
		QTextStream(&message)<<"min(x,y,z): "<<box.d_min_x<<","<<box.d_min_y<<","<<box.d_min_z
			<<" max(x,y,z): "<<box.d_max_x<<","<<box.d_max_y<<","<<box.d_max_z;
		ConsoleWidget::getInstance()->logMessage(message);
	}
}

BoundingBox& AppData::getBoundingBox()
{
	if(pMesh){
		return pMesh->getBoundingBox();
	}
}
