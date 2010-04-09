//-*-c++-mode-*-
/* StatusBarInterface.h --- 
 * copyright (c) 2010 dreamway

 *  This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the Free Software Foundation;
 *  Free free to contact dreamway(jingwenlai@163.com)
 * 
 * website: cg.xplore.cn
 */
#ifndef BASEPLUGIN_STATUSBARINTERFACE_H
#define BASEPLUGIN_STATUSBARINTERFACE_H

/* Commentary: 
 * 
 */
class StatusBarInterface {
 public:
  virtual ~StatusBarInterface( ){    
  }
  virtual QString description( ) const = 0;
 signals:
  virtual void updateStatusBarMessage( const QString& message ) = 0;
};

Q_DECLARE_INTERFACE( StatusBarInterface,"imesh.baseplugin.statusbarinterface" );

#endif
/* StatusBarInterface.h ends here */
