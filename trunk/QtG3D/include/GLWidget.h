#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H


#include <string>
#include <G3D/G3D.h>
#include <G3D/G3DAll.h>
//#include <OSWindow.h>

#include <QGLWidget>
#include <QGLFormat>
#include <QGLContext>
#include <QMessageBox>
using namespace G3D;


//TODO: sharedWidget
class QGWindow: public G3D::OSWindow
{
 public:
  static QGWindow * create(const OSWindow::Settings & settings = OSWindow::Settings() );
  
 public:
	QGWindow(const OSWindow::Settings & settings,QWidget* parent = 0)
    {
		QGLFormat format;
		m_settings = settings;

		format.setDoubleBuffer(true);
		format.setRgba(true);
		format.setDirectRendering(true);
		if(settings.depthBits > 0) format.setDepth(true);
		if(settings.alphaBits > 0) format.setAlpha(true);
		if(settings.stereo) format.setStereo(true);
		if(settings.stencilBits > 0) format.setStencil(true);
/*
		glContext = new QGLContext(format);
		glContext->makeCurrent();
*/
		m_caption = "QGWindow";
//		glWindow = new QGLWidget(glContext,parent);
		glWindow = new QGLWidget(format,parent);
		glWindow->resize(settings.width,settings.height);
		if(!glWindow->isValid())
		{
			QMessageBox::warning(NULL,QString(QObject::tr("Warning")),
				QString(QObject::tr("The context of the glwindow is null")));
		}
		glWindow->show();
	//  GLCaps::init();
    }
  
  ~QGWindow()
    {
      delete glWindow;
    }



  //pure virtual methods
 public:
  virtual std::string caption();
  virtual Rect2D dimensions() const;
  virtual std::string getAPIName() const;
  virtual std::string getAPIVersion() const;

  virtual void getDroppedFilenames(Array<std::string> & files);
  virtual void getJoystickState(unsigned int stickNum,Array<float>& axis,Array<bool> & button);
  virtual void getRelativeMouseState(double & x, double & y,uint8& mouseButtons) const;
  virtual void getRelativeMouseState(int & x,int &y, uint8& mouseButtons) const;
  virtual void getRelativeMouseState(Vector2& position,uint8& mouseButtons) const;
  void getSettings(OSWindow::Settings& settings) const;
  bool hasFocus() const;
  int height() const;

  virtual std::string joystickName(unsigned int sticknum);

  virtual void notifyResize(int w, int h);
  int numJoysticks() const;

  virtual void setCaption(const std::string & caption);
  void setDimensions(const Rect2D & dims);
  void setGammaRamp(const Array<uint16>& gammaRamp);

  void setPosition(int x,int y);
  void setRelativeMousePosition(const Vector2& p);
  void setRelativeMousePosition(double x,double y);
  void swapGLBuffers();
  int width() const;

 protected://protected member functions
  virtual void setInputCapture(bool c);
  virtual void setMouseVisible(bool b);
  
 private:
  QGLWidget * glWindow;
  //Settings for GLContext for G3D
  typedef QGLContext GLContext;
//  GLContext * glContext;
  inline GLContext* glGetCurrentContext(){
//	  debugAssert(glContext == glWindow->context());
//	  return glWindow->context();
//	  return glContext;
	  return ((GLContext*)(glWindow->context()));
  }

 private:
  OSWindow::Settings m_settings;
  std::string m_caption;
};

#endif
