#ifndef MESHDEFORMER_TEST_TESTHELPER_H
#define MESHDEFORMER_TEST_TESTHELPER_H


#include "Helper/Helper.hpp"

#include <gtest/gtest.h>

TEST(testHelper,testTrace)
{
  TRACE("\n");
  TRACE("testHelperTrace");
  TRACE("\n");
  TRACE("%d,%.2f",3,2.5);
}
  
#endif
