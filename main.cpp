#include "include/Camera.h"
#include "include/Object.h"
#include "include/ObjectList.h"
#include "include/Objects/Sphere.h"

int main(){
    ObjectList world;
    
    world.add(std::make_shared<Sphere>(Point(0,0,300),100));
    world.add(std::make_shared<Sphere>(Point(500,500,200),200));

    Camera cam(1000,1000,-500,-500,200,10);

    cam.render(world);
}