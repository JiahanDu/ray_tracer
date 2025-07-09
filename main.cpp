#include "include/Camera.h"
#include "include/Object.h"
#include "include/ObjectList.h"
#include "include/Objects/Sphere.h"

int main(){
    ObjectList world;
    
    world.add(std::make_shared<Sphere>(Point(0,0,300),100));

    Camera cam(1000,800,-500,-400,200,10);

    cam.render(world);
}