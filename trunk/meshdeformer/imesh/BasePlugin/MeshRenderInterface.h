/* MeshRenderInterface.h --- Some extra rendering for decorated mesh data
 * copyright (c) 2010 dreamway
 */

/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the Free Software Foundation;
 *  Feel free to contact dreamway(jingwenlai@163.com)
 * 
 * website: cg.xplore.cn
 */

/* Commentary: 
 * MeshRenderInterface will serve as an extra mesh data renderer,
 * every plugin who need to render the extra mesh data should derived
 * this Interface
 */
#ifndef _MESHRENDERINTERFACE_H_
#define _MESHRENDERINTERFACE_H_

/**
   @brief: use for render extra mesh data
*/
class MeshRenderInterface
{
 public:
  MeshRenderInterface();
  virtual ~MeshRenderInterface();
 public:
  virtual void render(  ) = 0;
};

Q_DECLARE_INTERFACE( MeshRenderInterface, "imesh.meshrenderinterface" );

#endif /* _MESHRENDERINTERFACE_H_ */
/* MeshRenderInterface.h ends here */
