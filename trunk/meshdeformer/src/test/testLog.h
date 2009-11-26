#include "../Common/Log.hpp"

#include <gtest/gtest.h>

TEST(LogTest,testInit)
{
  Log * log = Log::getInstance();
}

TEST(LogTest,testLogString)
{
  Log::getInstance()->logString("testLogString");
}

TEST(LogTest,testPrintf)
{
}

