#include "Vector.h"
#include "Ray.h"

#ifndef OBJECTS_H
#define OBJECTS_H

class HitRecord{
  public:
    Point p; //p is the hit point
    Point normal;
    double t;
};

class Object{
  public:
    virtual ~Object()= default;

    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const=0;
};
#endif 