/* common.h --- Common data struct for data sharing
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

#ifndef _COMMON_H_
#define _COMMON_H_

#include <QString>
#include <QVector>

typedef struct PluginInfo {
  QString name;
  QString description;
  QVector<QString> interfaces_name;
}PluginInfo;


#endif /* _COMMON_H_ */

/* common.h ends here */
