// BaseInterface.h --- A class that driven the creation of plugin & using 2-step initialization
//                     to create the corrent connection of signals&slots

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
  virtual void initializePlugin(  ){
    
  }
  virtual void pluginInitialized(  ){
    
  }  
};

Q_DECLARE_INTERFACE( BaseInterface, "BaseInterface/1.0" );

#endif /* _BASEINTERFACE_H_ */

//  
// 
// BaseInterface.h ends here
