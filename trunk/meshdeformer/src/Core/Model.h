/**
   the main appdata class
*/
#ifndef APPDATA_H
#define APPDATA_H

#include <QtGui>


#include "MeshCore/MeshCore.h"
#include "BasePlugins/LoggingInterface.h"

class Model : public QObject,public LoggingInterface
{
  Q_OBJECT
    Q_INTERFACES(LoggingInterface);
  
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
 signals:
  void log(const QString& message);
 public:
  QString description() const
  {
    return QString("Model");
  }
  
 private:
  MeshCore * pMesh;
};

#endif
