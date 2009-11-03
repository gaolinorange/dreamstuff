#ifndef IO_INTERFACE_H
#define IO_INTERFACE_H

#include <string>
using namespace std;

class IOInterface
{
 public:
  IOInterface(){}
  ~IOInterface(){}
 protected:
  virtual void read(const string & filename) = 0;
  virtual void write(const string & filename) = 0;  
};


#endif
