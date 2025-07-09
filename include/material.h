#ifndef MATERIAL_H
#define MATERIAL_H
#include "Object.h"

class Material{
  public:
    virtual ~material()=default;

    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const {
        return false;
    }
}

#endif 