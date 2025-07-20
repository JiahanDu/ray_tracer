#include "include/Camera.h"
#include "include/Object.h"
#include "include/ObjectList.h"
#include "include/Objects/Sphere.h"

int main(){
    ObjectList world;

    world.add(std::make_shared<Sphere>(Point(900,0,500),800, std::make_shared<Lambertian>(Color(0.8,0.5,0.5))));

    world.add(std::make_shared<Sphere>(Point(0,0,280),100, std::make_shared<Dielectric>(2)));

    world.add(std::make_shared<Sphere>(Point(0,-150,300),100, std::make_shared<Metal>(Color(0.1,0.9,0.5),0.2)));

    Camera cam(1000,800,-500,-400,200,500);

    cam.render(world);
}