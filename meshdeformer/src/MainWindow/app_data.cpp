#include "app_data.h"
#include "MeshCore/MeshCore.h"
#include <QtDebug>


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

void AppData::load(const QString& filename)
{

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

