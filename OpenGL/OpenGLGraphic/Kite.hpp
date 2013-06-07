#ifndef KITE_ZARATH
#define KITE_ZARATH

#ifdef __cplusplus

#include <iostream>
#include <cmath>

namespace zarath
{
#endif

  struct Kite
  {
    double pX, pY, pZ;//position
    double rTheta, rPhi, rR;//relative position from anchor
    double dTheta, dPhi;//direction on global
    double rTheta;//rotation of screen
    double radius, near, far;//screen radious, distance
    double aX, aY, aZ;//anchor position on global

#ifdef __cpluplus
  public:
Kite
  protected:
  private:
#endif
  };

#ifdef __cplusplus
  
  void gluLookAt(LookAtData &data);

  std::ostream& operator<<(std::ostream &dist, const LookAtData &data)
  {
    dist << "\x1b[0;0H\x1b[0J" << std::flush;
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
