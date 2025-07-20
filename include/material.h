#ifndef MATERIAL_H
#define MATERIAL_H
#include "Object.h"

class Material{
  public:
    virtual ~Material()=default;

    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const {
        return false;
    }
};

class Lambertian: public Material{
  public:
    Color albedo;
    Lambertian(const Color& albedo): albedo(albedo){}

    bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override{
        auto scatter_direction=Point::Lambertian_sample(rec.normal);
        scattered=Ray(rec.p, scatter_direction);
        attenuation=albedo;
        return true;
    }
};

class Metal: public Material{
  public:
    Color albedo;
    double fuzz; //fuzz should be a double between 0 and 1.
    Metal(const Color& albedo, double fuzz): albedo(albedo), fuzz(fuzz){}

    bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override{
        auto reflected=(r_in.direction.reflect(rec.normal)).normalized()+fuzz*Point::sphere();
        scattered=Ray(rec.p, reflected);
        attenuation=albedo;
        return true;
    }
};

#endif 