#ifndef MATERIAL_H
#define MATERIAL_H
#include "Object.h"

class Material{
  public:
    virtual ~material()=default;

    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const {
        return false;
    }
};

class Lambertian: public Material{
  public:
    Color albedo;
    Lambertian(const Color& albedo): albedo(albedo){}

    bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override{
        auto scatter_direction=//to be implemented;
        scattered=Ray(rec.p, scatter_direction);
        attenuation=albedo;
        return true;
    }
};

class Metal: public Material{

};

#endif 