/**
   the main appdata class
*/
#ifndef APPDATA_H
#define APPDATA_H




class MeshCore;



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
