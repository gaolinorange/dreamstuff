#include "GLWidget.h"


std::string QGWindow::caption()
{
  //return glWindow->caption();
  return m_caption;
}

Rect2D QGWindow::dimensions() const
{
  int x = glWindow->x();
  int y = glWindow->y();
  int width = glWindow->width();
  int height = glWindow->height();
  return Rect2D::xywh((float)x,(float)y,(float)width,(float)height);  
}

std::string QGWindow::getAPIName() const
{
  return "qgwindow api name";
}
std::string QGWindow::getAPIVersion() const
{
  return "qgwindow api version";
}

void QGWindow::getDroppedFilenames(Array<std::string>& files)
{
  files.fastClear();
}


void QGWindow::getJoystickState(unsigned int stickNum,Array<float>& axis,Array<bool> & button)
{
  //no known implement yet
}

void QGWindow::getRelativeMouseState(double& x,double & y,uint8& mouseButtons) const
{
  //no known implement yet
}

void QGWindow::getRelativeMouseState(int & x,int &y, uint8& mouseButtons) const
{
  //no known implement yet
}

void QGWindow::getRelativeMouseState(Vector2& position,uint8& mouseButtons) const
{
  //no known implement yet
}

void QGWindow::getSettings(OSWindow::Settings& settings) const
{
 settings = m_settings;
}

bool QGWindow::hasFocus() const
{
  return true;
}

int QGWindow::height() const
{
  return glWindow->height();
}

std::string QGWindow::joystickName(unsigned int sticknum)
{
  return "noname";
}

void QGWindow::notifyResize(int w,int h)
{
  //todo: what is notify?
}

int QGWindow::numJoysticks() const
{
  return 0;
}

void QGWindow::setCaption(const std::string& caption)
{
  //  glWindow->setCaption(caption.c_str());
  m_caption = caption;
}

void QGWindow::setDimensions(const Rect2D & dims)
{
  glWindow->setGeometry(dims.x0(),dims.y0(),dims.width(),dims.height());
}
void QGWindow::setGammaRamp(const Array<uint16>& gammaRamp)
{
}

void QGWindow::setPosition(int x,int y)
{
  glWindow->move(x,y);
}

void QGWindow::setRelativeMousePosition(const Vector2& p)
{
  //no known implement yet
}

void QGWindow::setRelativeMousePosition(double x, double y)
{
  //no known implement yet
}

void QGWindow::swapGLBuffers()
{
  glWindow->swapBuffers();
}

int QGWindow::width() const
{
  return glWindow->width();
}

//protected member functions
void QGWindow::setInputCapture(bool c)
{
  if(c == true)
    m_inputCaptureCount++;
  else
    m_inputCaptureCount--;
}

void QGWindow::setMouseVisible(bool b)
{
  if(b)
    glWindow->show();
  else
    glWindow->hide();
  
  if(true == b)
    m_mouseHideCount++;
  else
    m_mouseHideCount--;
}


//public interface
QGWindow * QGWindow::create(const OSWindow::Settings & settings)
{
  return new QGWindow(settings);
}
