#include "Camera.h"
#include "Object.h"
#include "ObjectList.h"
#include "../sphere.h"

int main(){
    ObjectList world;
    
    world.add(make_shared<Sphere>(Point(0,0,100),50));

    Camera cam;
    cam.image_width=100;
    cam.image_height=100;
    cam.x=-50;
    cam.y=-50;
    cam.z=50;

    cam.render(world);
}