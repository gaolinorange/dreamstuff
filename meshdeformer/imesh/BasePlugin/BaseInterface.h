// BaseInterface.h --- The Basic interface for Plugin development, all plugins should derived this interface
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
#ifndef _BASEINTERFACE_H_
#define _BASEINTERFACE_H_

#include <QtPlugin>

class BaseInterface {
 public:
  virtual ~BaseInterface(  ) {
    
  }

public slots:
  virtual void pluginInitialized(  ) = 0;

 public:
  /** plugin descripton */
  virtual QString descripton(  ) const = 0;
  /** plugin name*/
  virtual QString name(  ) const = 0;  
};

Q_DECLARE_INTERFACE( BaseInterface, "imesh.baseplugin.baseinterface" );

#endif /* _BASEINTERFACE_H_ */
//  
// 
// BaseInterface.h ends here
