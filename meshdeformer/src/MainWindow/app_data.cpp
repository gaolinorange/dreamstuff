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

void AppData::init()
{
  if(pMesh == 0)
    pMesh = new MeshCore();

  pMesh->make_tetrahedron();

  qDebug()<<pMesh->is_pure_triangle()<<" pMesh is pure_triangle?";
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

