/* testTestWidget.h --- 
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
#ifndef _TESTTESTWIDGET_H_
#define _TESTTESTWIDGET_H_

#include "TestWidget.h"
#include <gtest/gtest.h>

class TestWidgetTest : public ::testing::Test {
 protected:
  virtual void SetUp(  ) {
    widget_ = new TestWidget(  );
  }

  virtual void TearDown(  ) {
    delete widget_;
  }

  TestWidget* widget_;
};

TEST_F( TestWidgetTest, testInit ) {
  //no need to do things
}


#endif /* _TESTTESTWIDGET_H_ */
/* testTestWidget.h ends here */
