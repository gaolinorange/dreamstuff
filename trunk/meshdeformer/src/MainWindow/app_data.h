/**
   the main appdata class
*/
#ifndef APPDATA_H
#define APPDATA_H

#include <QtGui>
/*
#include "assimp.hpp"

typedef class Assimp::Importer Importer;
typedef class Assimp::aiScene aiScene;
typedef class Assimp::aiMesh aiMesh;
*/

class MeshCore;



class AppData //: public QObject
{
 public:
  AppData();
  ~AppData();
 public:
  void initATetrahedron();
  bool load(const QString& filename);
  void update();
  void render();
 private:
  MeshCore * pMesh;

};

#endif
