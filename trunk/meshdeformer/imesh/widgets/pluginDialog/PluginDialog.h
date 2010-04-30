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
#include "../../Common/common.h"

class PluginDialog : public QDialog,public Ui_pluginDialog
{
 public:
  PluginDialog() {
    setupUi( this );
    setLayout( verticalLayout );

    treeWidget->setColumnCount( 2 );
    QStringList header_info;
    header_info<<QString( tr( "Name" ) )<<QString( tr( "Description" ) );
    treeWidget->setHeaderLabels( header_info );    
  }
  virtual ~PluginDialog() {
    
  }
 public:
  void setPluginsInfo( QVector<PluginInfo>& _plugins_info ) {
    PluginInfo plugin_info;
    foreach( plugin_info, _plugins_info ) {
      QTreeWidgetItem* plugin_item = new QTreeWidgetItem( treeWidget );
      plugin_item->setText( 0, plugin_info.name );
      plugin_item->setText( 1, plugin_info.description );
      foreach( QString interface_name, plugin_info.interfaces_name ) {
        QTreeWidgetItem* child_item = new QTreeWidgetItem( plugin_item );
        child_item->setText( 1, interface_name );
        plugin_item->addChild( child_item );
      }
      treeWidget->setCurrentItem( plugin_item );
    }
  }

};


#endif /* _PLUGINDIALOG_H_ */
/* PluginDialog.h ends here */
