/* -*-c++-mode-*- PluginDialog.h --- 
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
#ifndef _PLUGINDIALOG_H_
#define _PLUGINDIALOG_H_

#include "Ui_PluginDialog.h"

class PluginDialog : public QDialog,public Ui_pluginDialog
{
 public:
  PluginDialog() {
    setupUi( this );
  }
  virtual ~PluginDialog() {
    
  }
};


#endif /* _PLUGINDIALOG_H_ */
/* PluginDialog.h ends here */
