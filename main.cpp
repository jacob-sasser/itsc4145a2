
#include <vector>
#include <stdio>
#include <cmath>
const double soft= 1e-10;
const double G=6.67 * pow(10,-11)
class Body{
 public:
  double x;
  double y;
  double z;
  double fx;
  double fy;
  double fz;
  double vx;
  double vy;
  double vz;
  double mass;
  void update(std::vector<Body> bodies,double dt);
  Body(double x,double y,double z,double mass)
    :x(x),y(y),z(z),mass(mass),vx(0),vy(0),vz(0),fx(0),fy(0),fz(0){} 
};
void Body::update(std::vector<Body> bodies, double dt){
  for(const auto& other : bodies){
    if(&other==this) continue;

this->fx=0;
  this->fy=0;
  this->fz=0;

  double dx=other.x-x;
  double dy=other.y-y;
  double dz=other.z-z;

  double r= pow((dx*dx)) + (dy*dy) +(dz*dz)+soft,0.5);
  double r2=r*r;
  
  double f= G*((mass*other.mass)/r2);
  this->fx= f(dx/r);
  this->fy= f(dy/r);
  this->fz= f(dz/r);

  double ax= fx/this->mass;
  double ay=fy/this->mass;
  double az=fz/this->mass;

  this->vx= this->vx+(ax*dt);
   this->vy= this->vy+(ay*dt);
  this->vz= this.vz + (az*dt);


  this->x+=this->vx*dt;
  this->y+=this->vy*dt;
  this->z+=this->vz*dt;
    }


