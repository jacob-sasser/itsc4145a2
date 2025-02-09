#ifndef BODY_H
#define BODY_H
#include <vector>
#include <cmath>

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
  const double mass;
 
    Body(double x, double y, double z, double mass);
      void update(std::vector<Body>& bodies, double dt);
};
#endif
