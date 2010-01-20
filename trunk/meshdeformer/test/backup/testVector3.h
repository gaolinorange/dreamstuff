#include "Vector3.h"
#include <gtest/gtest.h>


TEST(Vector3Test,testZero)
{
  Vector3 zero(0.0,0.0,0.0);
  Vector3 anotherZero = Vector3(0.0,0,0);
  EXPECT_EQ(zero,anotherZero);
}

TEST(Vector3Test,testAdd)
{
  Vector3 lhs(1,2,3);
  Vector3 rhs(3,2,1);
  Vector3 expectedResult(4,4,4);
  EXPECT_EQ(expectedResult,lhs+rhs);
}

TEST(Vector3Test,testDel)
{
  Vector3 lhs(3,2,1);
  Vector3 rhs(3,2,1);
  Vector3 expectedResult(0,0,0);
  EXPECT_EQ(expectedResult,lhs-rhs);
}

TEST(Vector3Test,testMul)
{
  Vector3 lhs(1,1,1);
  float s = 2.0;
  Vector3 expectedResult(2,2,2);
  EXPECT_EQ(expectedResult,lhs*s);
}

TEST(Vector3Test,testDiv)
{
  Vector3 lhs(2,2,2);
  float s = 2.0;
  Vector3 expectedResult(1,1,1);
  EXPECT_EQ(expectedResult,lhs/s);
}

TEST(Vector3Test,testUniaryOperator)
{
  Vector3 lhs(1,1,1);
  Vector3 expectedResult(-1,-1,-1);
  EXPECT_EQ(expectedResult,-lhs);
}

TEST(Vector3Test,testLength)
{
  Vector3 vec(1,1,2);
  float expectedLength = 6;
  EXPECT_EQ(expectedLength,vec.length());
}

TEST(Vector3Test,testSmaller)
{
  Vector3 lhs(1,1,1);
  Vector3 rhs(1,1,2);
  EXPECT_EQ(true,lhs<rhs);
}

TEST(Vector3Test,testGreator)
{
  Vector3 lhs(2,2,2);
  Vector3 rhs(1,1,1);
  EXPECT_EQ(true,lhs>rhs);
}

TESt(Vector3Test,testEqual)
{
  Vector3 lhs(2,2,2);
  Vector3 rhs(2,2,2);
  Vector3 rhs2(2,2,3);
  EXPECT_EQ(true,rhs==lhs);
  EXPECT_EQ(false,lhs != rhs2);
}

TEST(Vector3Test,testEqualOperator)
{
  Vector3 lhs(2,2,2);
  Vector3 result  = lhs;
  Vector3 expectedResult(2,2,2);
  EXPECTED_EQ(expectedResult,result);
}

TEST(Vector3Test,testMinusEqualOperator)
{
  Vector3 lhs(2,2,2);
  Vector3 rhs(1,1,1);
  lhs -= rhs;
  Vector3 expectedResult(1,1,1);
  EXPECT_EQ(expectedResult,lhs);
}

TEST(Vector3Test,testAddEqualOperator)
{
  Vector3 lhs(1,1,1);
  lhs += Vector3(1,1,1);
  Vector3 expectedResult(2,2,2);
  EXPECT_EQ(expectedResult,lhs);
}


  
  
