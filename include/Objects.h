#include "Vector.h"
#include "Ray.h"

#ifndef OBJECTS_H
#define OBJECTS_H

class HitRecord{
  public:
    Point p;
    Point normal;
    double t;
    bool exiting;
};

class Objects{
  public:
    virtual ~Objects()= default;

    virtual bool intersect(const Ray& r, double t_min, double t_max, HitRecord& rec) const=0;
};
#endif 