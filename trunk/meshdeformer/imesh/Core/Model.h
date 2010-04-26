// Model.h --- Model calss for core data
// copyright (c) 2010 dreamway
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free Software Foundation;
//  Free free to contact dreamway(jingwenlai@163.com)
// 
// website: cg.xplore.cn
// 
// 

// Commentary: 
// 
// 

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
 private:
  MeshCore * pMesh;
};

#endif /* _MODEL_H_ */


// 
// Model.h ends here
