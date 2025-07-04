#include "Vector.h"
#include "Ray.h"

#ifndef OBJECTS_H
#define OBJECTS_H

class Hit{
  public:
    Point p;
    Point normal;
    double t;
};

class Objects{
  public:
    virtual ~Objects()= default;

    virtual bool intersect(const Ray& r, double t_min, double t_max, Hit& rec) const=0;
};
#endif 