#ifndef TESTINTERFACE_H
#define TESTINTERFACE_H


class TestInterface{
 public:
  virtual ~TestInterface(){}
 signals:
  virtual void log(const QString& ) = 0;  
};

#endif
