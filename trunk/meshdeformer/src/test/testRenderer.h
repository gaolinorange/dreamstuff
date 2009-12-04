/**
   testRenderer:
   use the pre-saved file for comparison.
   in RUNNING_AT_TEST_MODE, store the image and compare it with pre-saved image file.
*/
#ifndef TEST_RENDERER_H
#define TEST_RENDERER_H

#include <gtest/gtest.h>
#include <QtTest>
#include <QtGui>

class RendererTest: public ::testing::Test
{
protected:
  virtual void SetUp(){
    
  }
  virtual void TearDown(){
    
  }

public:
	void readTestImage()
	{
		expectedImage.load("testData/render_test_picture.png");
	}
private:
  QImage expectedImage;
  QImage renderedImage;
};

TEST_F(RendererTest,testInit)
{
}


TEST_F(RenderTest,testEqual)
{
  

}

#endif
