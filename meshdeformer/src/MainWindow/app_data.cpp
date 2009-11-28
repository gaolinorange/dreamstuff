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

bool AppData::load(const QString& filename)
{
  /*
  QString filename = QFileDialog::getOpenFileName(this,
						  QString(tr("Open file")),
						  QString(tr("../")),
						  QString(tr("*.obj,*.off,*.ply")));
  Importer * aiImporter = new Importer;
  aiScene* scene = aiImporter->ReadFile(filename,0);
  if(NULL == scene)
    {
      QMessageBox::warning(this,QString(tr("warning")),QString(tr("could not load the mesh")));
      return;
    }
  qDebug()<<"num of meshes: "<<scene->mNumMeshes;
  if(scene->HasMeshes() == false)
    {
      qDebug()<<"the scene has no meshes";
      return false;
    }
  Q_ASSERT(scene->mNumMeshes == 1);
  aiMesh* mesh = scene->mMeshes[0];
  // converte aiMesh to MeshCore format
  if(pMesh)
    {
      delete pMesh; pMesh = 0;
    }
  if(pMesh == 0)
    pMesh = new MeshCore();

  */
  
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

