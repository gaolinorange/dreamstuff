/**
   the main appdata class
*/
#ifndef APPDATA_H
#define APPDATA_H

#include <QtGui>


class MeshCore;


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
 private:
  MeshCore * pMesh;

};

#endif
