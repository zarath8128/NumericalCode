#ifndef LOOK_AT_DATA_ZARATH
#define LOOK_AT_DATA_ZARATH

#ifdef __cplusplus

#include <iostream>
#include <cmath>

namespace zarath
{
#endif

  struct LookAtData
  {
    double pR, pTheta, pPhi;
    double dTheta, dPhi;
    double rTheta;
    double radius, near, far;
  };

#ifdef __cplusplus
  
  void gluLookAt(LookAtData &data);

  std::ostream& operator<<(std::ostream &dist, const LookAtData &data)
  {
    dist << "pos-r      :" << data.pR << std::endl;
    dist << "pos-theta  :" << data.pTheta << std::endl;
    dist << "pos-phi    :" << data.pPhi << std::endl;
    dist << "pos-x      :" << data.pR*sin(data.pPhi)*cos(data.pTheta) << std::endl;
    dist << "pos-y      :" << data.pR*cos(data.pPhi)*cos(data.pTheta) << std::endl;
    dist << "pos-z      :" << data.pR*sin(data.pTheta) << std::endl << std::endl;

    dist << "dir-theta  :" << data.dTheta << std::endl;
    dist << "dir-phi    :" << data.dPhi << std::endl;
    dist << "dir-x      :" << sin(data.dPhi)*cos(data.dTheta) << std::endl;
    dist << "dir-y      :" << cos(data.dPhi)*cos(data.dTheta) << std::endl;
    dist << "dir-z      :" << sin(data.dTheta) << std::endl << std::endl;

    dist << "rot-theta  :" << data.rTheta << std::endl << std::endl;

    dist << "scr-near   :" << data.near << std::endl;
    dist << "scr-far    :" << data.far << std::endl << std::endl;
    return dist; 
  }
}
#endif

#endif
