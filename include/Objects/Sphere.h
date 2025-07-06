#include "../Objects.h"
#include "../Ray.h"

class Sphere: public Object{
  private:
    Point center;
    double radius; 
  public:
    Sphere(Point center, double radius): center(center), radius(radius){}
  
    bool hit(const Ray& r, double t_min, double t_max, Hit& rec) const override{
      Point x=center-r.origin;
      double discriminant=dot(x,x)-dot(r.direction,r.direction)-radius*radius;
      if(discriminant<0){
        return false;
      }
      double b=dot(r.direction,x);
      double root=(b-std::sqrt(discriminant))/dot(r.direction, r.direction);
      if(root<t_min || root>t_max){
        root=(b+std::sqrt(discriminant))/dot(r.direction, r.direction);
        if(root<t_min || root>t_max){
          return false;
        }
      }
      rec.t=root;
      rec.p=r(root);
      rec.normal=rec.p-center;
      rec.normal/=radius;
      rec.exiting=dot(r.direction, rec.normal)>0;
    }
};