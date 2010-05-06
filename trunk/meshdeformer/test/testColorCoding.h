/* testColorCoding.h --- Test Common/ColorCoding.h
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
#ifndef _TESTCOLORCODING_H_
#define _TESTCOLORCODING_H_

#include <gtest/gtest.h>
#include "../imesh/Common/ColorCoding.h"

class ColorCodingTest : public ::testing::Test {
 protected:
  virtual void SetUp(  ) {
    color_coding_ = new ColorCoding<float>( -10.0,10.0 );
  }
  virtual void TearDown(  ) {
    delete color_coding_;
  }

  ColorCoding<float>* color_coding_;
};

TEST_F( ColorCodingTest, testInit ) {
  
}

TEST_F( ColorCodingTest, testColorCodingRed ) {
  Color color = color_coding_->colorCoding( 10.0 );
  EXPECT_EQ( RED.r,color.r );
  EXPECT_EQ( RED.g,color.g );
  EXPECT_EQ( RED.b,color.b );
}

TEST_F( ColorCodingTest, testColorCodingBlue ) {
  Color color = color_coding_->colorCoding( -10.0 );
  EXPECT_EQ( BLUE.r,color.r );
  EXPECT_EQ( BLUE.g,color.g );
  EXPECT_EQ( BLUE.b,color.b );
}

TEST_F( ColorCodingTest, testColorCodingGreen ) {
  Color color = color_coding_->colorCoding( 0.0 );
  EXPECT_EQ( GREEN.r,color.r );
  EXPECT_EQ( GREEN.g,color.g );
  EXPECT_EQ( GREEN.b,color.b );
}

TEST_F( ColorCodingTest, testGetMax ) {
  EXPECT_FLOAT_EQ( 10.0,color_coding_->getMaxValue(  ) );
}

TEST_F( ColorCodingTest, testGetMin ) {
  EXPECT_FLOAT_EQ( -10.0,color_coding_->getMinValue(  ) );
}

TEST_F( ColorCodingTest, testPrintMedians ) {
  color_coding_->printMedians(  );
}

#endif /* _TESTCOLORCODING_H_ */
/* testColorCoding.h ends here */
