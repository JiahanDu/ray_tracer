#include "../Objects.h"
#include "../Ray.h"

class Sphere: public Objects{
  private:
    Point center;
    double radius; 
  public:
    bool hit(const Ray& r, double t_min, double t_max, Hit& rec) const override{

    }
};