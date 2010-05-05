/* RenderInterface.h --- Some extra rendering for decorated mesh data
 * copyright (c) 2010 dreamway
 */

/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the Free Software Foundation;
 *  Feel free to contact dreamway(jingwenlai@163.com)
 * 
 * website: cg.xplore.cn
 */

/* Commentary: 
 * RenderInterface will serve as an extra mesh data renderer,
 * every plugin who need to render the extra mesh data should derived
 * this Interface
 */
#ifndef _RENDERINTERFACE_H_
#define _RENDERINTERFACE_H_

/**
   @brief: use for render extra mesh data
*/
class RenderInterface
{
 public:
  virtual ~RenderInterface() {
  }
 public:
  virtual void render(  ) = 0;
};

Q_DECLARE_INTERFACE( RenderInterface, "imesh.renderinterface" );

#endif /* _RENDERINTERFACE_H_ */
/* RenderInterface.h ends here */
