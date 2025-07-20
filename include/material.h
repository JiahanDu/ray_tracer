#ifndef MATERIAL_H
#define MATERIAL_H
#include "Object.h"

#define refraction_index_medium 1.0003

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
    double reflection_coefficient;

    Dielectric(double refraction_index): refraction_index(refraction_index){}


    bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const{
      attenuation=Color(1,1,1);
      Point unit_direction=r_in.direction.normalized();
      double cos_theta= dot(-unit_direction, rec.normal);
      double sin_theta=std::sqrt(1-cos_theta*cos_theta);
      double r0=(refraction_index_medium-refraction_index)/(refraction_index_medium+refraction_index);
      r0=r0*r0;
      if(sin_theta*refraction_index_medium/refraction_index<=1 || r0+(1-r0)*std::pow((1-cos_theta),5)>random_0_1()){ 
        Point refracted=r_in.direction.refract(rec.normal, refraction_index_medium/refraction_index);
        scattered=Ray(rec.p,refracted);
        return true;
      }else{ //Refraction is not possible in this case
        Point reflected=r_in.direction.reflect(rec.normal);
        scattered=Ray(rec.p,reflected);
        return true;
      }
    }
};

#endif 