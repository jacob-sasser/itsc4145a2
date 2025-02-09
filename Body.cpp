#include <vector>

#include "Body.h"
#include <iostream>
const double soft=10e-11;
const double G=6.67430e-11;
Body::Body(double x, double y, double z, double mass)
    : x(x), y(y), z(z), mass(mass), vx(0), vy(0), vz(0), fx(0), fy(0), fz(0) {}

void Body::update(std::vector<Body>& bodies, double dt){
  fx=fy=fz=0;
  for(const auto& other : bodies){
    if(&other==this) continue;





  double dx=other.x-x;
  double dy=other.y-y;
  double dz=other.z-z;

  double r= std::sqrt((dx*dx) + (dy*dy) +(dz*dz)+soft);
  double r2=r*r;
  
  double f= G*((mass*other.mass)/r2);
   fx= f*(dx/r);
   fy= f*(dy/r);
   fz= f*(dz/r);

  double ax=  fx/ mass;
  double ay= fy/ mass;
  double az= fz/ mass;

   vx=  vx+(ax*dt);
   vy=  vy+(ay*dt);
   vz=  vz + (az*dt);


   x= x+( vx*dt);
   y= y +( vy*dt);
   z= z +( vz*dt);
      std::cout << "x, y, z: " <<  x << ", " <<  y << ", " <<  z << std::endl;
    }//for loop
}
