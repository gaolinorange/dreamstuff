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
  void load(const QString& filename);
  void update();
  void render();
 private:
  MeshCore * pMesh;

};

#endif
