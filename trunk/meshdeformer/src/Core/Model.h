/**
   the main appdata class
*/
#ifndef APPDATA_H
#define APPDATA_H

#include <QtGui>


#include "MeshCore/MeshCore.h"


class Model : public QObject
{
  Q_OBJECT
 public:
  Model();
  ~Model();
 public:
  void initATetrahedron();
  bool loadMesh(const QString& filename);
  void update();
  void render();
  //  void printBoundingBox();
  //  BoundingBox& getBoundingBox();
 private:
  MeshCore * pMesh;
};

#endif
