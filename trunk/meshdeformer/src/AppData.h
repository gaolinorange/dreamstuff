/**
   the main appdata class
*/
#ifndef APPDATA_H
#define APPDATA_H

#include <QtGui>


#include "MeshCore.h"


class AppData //: public QObject
{
 public:
  AppData();
  ~AppData();
 public:
  void initATetrahedron();
  bool loadMesh(const QString& filename);
  void update();
  void render();
  void printBoundingBox();
  BoundingBox& getBoundingBox();
 private:
  MeshCore * pMesh;

};

#endif
