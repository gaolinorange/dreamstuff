/* -*-c++-mode-*- MeshCoreInterface.h ---  for updating Mesh between MainWindow and Plugins
 * copyright (c) 2010 dreamway
 */

/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the Free Software Foundation;
 *  Feel free to contact dreamway(jingwenlai@163.com)
 * 
 * website: cg.xplore.cn
 */

/* Commentary: 
 * 
 */
#ifndef _MESHCOREINTERFACE_H_
#define _MESHCOREINTERFACE_H_


#include <QtPlugin>

class MeshCore;

class MeshCoreInterface {
 public:
  virtual ~MeshCoreInterface() {
    
  }
 public slots:
  virtual void setMesh( MeshCore* ) = 0;
};

Q_DECLARE_INTERFACE( MeshCoreInterface, "imesh.baseplugin.meshcoreinterface" );

#endif /* _MESHCOREINTERFACE_H_ */
/* MeshCoreInterface.h ends here */
