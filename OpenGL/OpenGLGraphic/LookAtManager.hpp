#ifndef LOOK_AT_MANAGER_ZARATH
#define LOOK_AT_MANAGER_ZARATH

#include <GL/gl.h>
//#include "LookAtData.h"

#ifdef __cplusplus

#include <iostream>
#include <cmath>

namespace zarath
{
#endif

#ifdef __cplusplus
  
  void gluLookAt(LookAtData &data)
  {
    double px = data.pR*sin(data.pPhi)*sin(data.pTheta),
           py = data.pR*cos(data.pPhi)*sin(data.pTheta),
           pz = data.pR*cos(data.pTheta);
    std::cout << data << std::endl;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
 glOrtho(-1200/600, 1200/600, -900/600., 900/600., 1, 10);
    ::gluLookAt(px, py, pz,
	      px - sin(data.dPhi)*sin(data.dTheta),
	      py - cos(data.dPhi)*sin(data.dTheta),
	      pz - cos(data.dTheta),
	      cos(data.dPhi)*sin(data.rTheta)+sin(data.dPhi)*cos(data.dTheta)*cos(data.rTheta),
	      -sin(data.dPhi)*sin(data.rTheta)+cos(data.dPhi)*cos(data.dTheta)*cos(data.rTheta),
	      -cos(data.rTheta)*sin(data.dTheta));
	      
  }

}
#endif

#endif
