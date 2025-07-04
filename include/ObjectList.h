#include "Object.h"
#include <memory>
#include <vector>

#ifndef ObjectList
#define ObjectList

class ObjectList: public Object{
  public:
    std::vector<<std::shapred_ptr<Object>> objects;

    ObjectList() {}
    ObjectList(std::shared_ptr<Object> object) { objects.push_back(object); }

    void clear() {objects.clear();}

    void add(shared_ptr<Object> object){ objects.push_back(object);}
    
    bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override{
        HitRecord temp;
        bool hit_anything = false;
        auto closest_so_far=t_max;

        for(const auto & object:objects){
          if(object->hit(r, t_min, closest_so_far, temp)){
            hit_anything=true;
            closest_so_far=temp.t;
            rec=temp;
          }
        }
        return hit_anything;
    }
};

#endif