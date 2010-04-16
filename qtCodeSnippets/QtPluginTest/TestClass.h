#ifndef _TESTCLASS_H_
#define _TESTCLASS_H_

#include <QObject>
#include <QtDebug>

class TestClass : public QObject
{
  Q_OBJECT
 public:
  TestClass() {
    
  }
  virtual ~TestClass() {
    
  }
 public slots:
  void test_slot( const QString& message ) {
    qDebug(  )<<"test_slot of TestClass:"<<message;
  }
};


#endif /* _TESTCLASS_H_ */
