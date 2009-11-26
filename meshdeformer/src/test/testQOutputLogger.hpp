#include "QOutputLogger.hpp"
#include <gtest/gtest.h>

TEST(testQOutputLogger,testInit)
{
  QOutputLogger::getInstance()->append(QString(tr("Test logging")));
}
