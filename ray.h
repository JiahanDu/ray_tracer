#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray{
  private:
    point3 ori;
    vec3 dir;
  public:
    ray(){}

    ray(const point3& origin_, const vec3& direction_): ori(origin_), dir(direction_){}

    const point3& origin() const {return ori;}

    const vec3& direction() const {return dir;}

    point3 at(double t) const{
        return ori+t*dir;
    }
};

#endif