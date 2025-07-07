#include "../Object.h"
#include "../Ray.h"

class Sphere: public Object{
  private:
    Point center;
    double radius; 
  public:
    Sphere(Point center, double radius): center(center), radius(radius){}
  
    bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override{
      Point x=center-r.origin;
      double b=dot(x,r.direction);
      double a=dot(r.direction,r.direction);
      double discriminant=b*b-a*(dot(x,x)-radius*radius);
      if(discriminant<0){
        return false;
      }
      double sqrt_d=std::sqrt(discriminant);
      double root=(b-sqrt_d)/a;
      if(root<t_min || root>t_max){
        root=(b+sqrt_d)/a;
        if(root<t_min || root>t_max){
          return false;
        }
      }
      rec.t=root;
      rec.p=r(root);
      rec.normal=rec.p-center;
      rec.normal/=radius;
      return true;
    }
};