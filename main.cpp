#include "include/Camera.h"
#include "include/Object.h"
#include "include/ObjectList.h"
#include "include/Objects/Sphere.h"

int main(){
    ObjectList world;
    
    world.add(std::make_shared<Sphere>(Point(0,0,100),1));

    Camera cam(100,100,-50,-50,50);

    cam.render(world);
}