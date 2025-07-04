#include "Vector.h"

#ifndef RAY_H
#define RAY_H

class Ray{
  private:
    Point _origin;
    Point _direction;
  public:
    Ray() {}

    Ray(const Point& origin, const Point& direction): _origin(origin), _direction(direction){}

    const Point& origin() const{ return _origin;}

    const Point& direction() const{ return _direction;}

    Point operator()(double t) const {
        return _origin+t*_direction;
    }
};

#endif 