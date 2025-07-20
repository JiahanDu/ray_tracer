#ifndef MATERIAL_H
#define MATERIAL_H
#include "Object.h"

#define refraction_index_medium 1.0

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

class Dielectric: public Material{
  public:
    double refraction_index;

    Dielectric(double refraction_index): refraction_index(refraction_index){}

    bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const{
      attenuation=Color(1,1,1);
      double cos_theta= dot(-r_in.direction, rec.normal)/dot(r_in.direction,r_in.direction);
      double sin_theta=std::sqrt(1-cos_theta*cos_theta);
      if(sin_theta*refraction_index/refraction_index_medium>1){
        Point refracted=r_in.direction.refract(rec.normal, refraction_index_medium/refraction_index);
        scattered=Ray(rec.p,refracted);
        return true;
      }else{
        Point reflected=r_in.direction.reflect(rec.normal);
        scattered=Ray(rec.p,reflected);
        return true;
      }
    }
};

#endif 