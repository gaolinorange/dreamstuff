#ifndef TESTINTERFACE_H
#define TESTINTERFACE_H

#include <QtPlugin>

class TestInterface{
 public:
  virtual ~TestInterface(){}

  virtual QString name() const = 0;
};

Q_DECLARE_INTERFACE(TestInterface,"meshdeformer.TestInterface")


#endif
