// MeshModel.h --- MeshModel calss for core data
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

#ifndef _MESHMODEL_H_
#define _MESHMODEL_H_


#include <QObject>

#include "MeshCore/MeshCore.h"
#include "BasePlugin/LoggingInterface.h"

class MeshModel : public QObject,public LoggingInterface
{
  Q_OBJECT
    Q_INTERFACES(LoggingInterface);
  
 public:
  MeshModel();
  ~MeshModel();
 public:
  bool loadMesh(const QString& filename);

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


#endif /* _MESHMODEL_H_ */



// 
// MeshModel.h ends here
