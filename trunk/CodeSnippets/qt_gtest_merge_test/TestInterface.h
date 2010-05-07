/* TestInterface.h --- 
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

#ifndef _TESTINTERFACE_H_
#define _TESTINTERFACE_H_

#include <QtPlugin>

class TestInterface
{
 public:
  virtual ~TestInterface() {
    
  }

  virtual void test(  ) = 0;
};

Q_DECLARE_INTERFACE( TestInterface, "test.TestInterface" );

#endif /* _TESTINTERFACE_H_ */

/* TestInterface.h ends here */
