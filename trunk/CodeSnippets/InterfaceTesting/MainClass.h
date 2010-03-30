#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QtDebug>

class MainClass : public QObject{
  Q_OBJECT
public:
  MainClass(){}
  ~MainClass(){}
public slots:
  void slotLog(const QString& message)
  {
    qDebug()<<"MainClass: slotLog: message : "<<message;
  }
};


#endif
