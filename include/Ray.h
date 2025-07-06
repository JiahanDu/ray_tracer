#include "Vector.h"

#ifndef RAY_H
#define RAY_H

class Ray{
  public:
    Point origin;
    Point direction;

    Ray() {}

    Ray(const Point& _origin, const Point& _direction): origin(_origin), direction(_direction){}

    Point operator()(double t) const {
        return origin+t*direction;
    }
};

#endif 