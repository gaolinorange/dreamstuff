/**
   the main appdata class
*/
#ifndef _MODEL_H_
#define _MODEL_H_


#include <QtGui>


#include "MeshCore/MeshCore.h"
#include "BasePlugin/LoggingInterface.h"

class Model : public QObject,public LoggingInterface
{
  Q_OBJECT
    Q_INTERFACES(LoggingInterface);
  
 public:
  Model();
  ~Model();
 public:
  bool loadMesh(const QString& filename);
  void update();
  void render();
  Iso_cuboid_3& get_bounding_box(){
    if(pMesh){
      return pMesh->get_bounding_box();
    }
  }
    
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

#endif /* _MODEL_H_ */

