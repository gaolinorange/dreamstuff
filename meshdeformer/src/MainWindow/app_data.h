/**
   the main appdata class
*/
#ifndef APPDATA_H
#define APPDATA_H



//#include "MeshCore.h"
#include "MeshCore/MeshCore.h"



class AppData //: public QObject
{
 public:
  AppData();
  ~AppData();
 public:
  void init();
  void update();
  void render();
 private:
  MeshCore * pMesh;

};

#endif
