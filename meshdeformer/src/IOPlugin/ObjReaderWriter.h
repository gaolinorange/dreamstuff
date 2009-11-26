#ifndef OBJ_READER_WRITER_H
#define OBJ_READER_WRITER_H

#include "IOInterface.h"

class ObjReaderWriter : public IOInterface
{
 public:
  ObjReaderWriter()
    {
    }
  ~ObjReaderWriter()
    {
    }
 protected:
  void read(const string & filename);
  void write(const string & filename);

};


#endif
