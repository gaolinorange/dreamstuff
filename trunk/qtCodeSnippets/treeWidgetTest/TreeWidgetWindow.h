/* TreeWidgetWindow.h --- 
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
#ifndef _TREEWIDGETWINDOW_H_
#define _TREEWIDGETWINDOW_H_

#include "Ui_tree_widget_window.h"

class TreeWidgetWindow :public QDialog,
                        public Ui_Dialog
{
 public:
  TreeWidgetWindow() {
    setupUi( this );
    setLayout( verticalLayout );
    
    treeWidget->setColumnCount( 2 );
    
    QStringList labels;
    labels<<"Name"<<"Description";
    treeWidget->setHeaderLabels( labels );

    QTreeWidgetItem* first_item = new QTreeWidgetItem( treeWidget );
    first_item->setText( 0, "itemName" );
    first_item->setText( 1, "itemDescription" );
    QTreeWidgetItem* child_item1 = new QTreeWidgetItem( first_item );
    child_item1->setText( 1, QString( "interface_1" ) );
    QTreeWidgetItem* child_item2 = new QTreeWidgetItem( first_item );
    child_item2->setText( 1, QString( "interface_2" ) );
    
    treeWidget->setCurrentItem( first_item );    
  }

  virtual ~TreeWidgetWindow() {
    
  }
};

#endif /* _TREEWIDGETWINDOW_H_ */
/* TreeWidgetWindow.h ends here */
