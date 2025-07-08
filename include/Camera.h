#include "Object.h"
#include <random>
#include <climits>
#include "rng.h"

#ifndef CAMERA_H
#define CAMERA_H

class Camera{
  public:
    int image_width; //Number of pixels per row
    int image_height; //Number of pixels per column
    double aspect_ratio; // The ratio of image_width to image_height 
    Point center;  //Location of the camera
    Point bottom_left; // The bottom left corner of the view_port
    int samples_per_pixel; 
    double inverse;

    Camera(int width, int height, int x, int y, int z, int s): image_width(width), image_height(height), aspect_ratio(double(width)/height), center(0,0,0), bottom_left(x,y,z), samples_per_pixel(s), inverse(1.0/samples_per_pixel){}
    
    //Following code can be changed to different logics
    Color ray_color(const Ray& r, const Object& world, int depth=0) const{
        if(depth>=50){
          return Color(1.0,0,0);
        }
        HitRecord rec;
    
        if(world.hit(r, 0, INT_MAX, rec)){
          Point random_on_sphere=Point::sphere();
          if(dot(random_on_sphere,rec.normal)<0){
            random_on_sphere=-random_on_sphere;
          }
          return ray_color(Ray(rec.p,random_on_sphere),world,depth+1)*0.5;
        }
        return Color(0.5,0.7,1.0);
    }  

    void write_color(std::ostream& out, const Color& pixel_color) const{
      int r=int(255.999*pixel_color.x());
      int g=int(255.999*pixel_color.y());
      int b=int(255.999*pixel_color.z());

      out<<r<<' '<<g<<' '<<b<<'\n';
    }

    void render(const Object& world) const{

      std::cout<<"P3\n"<<image_width<<' '<<image_height<<"\n255\n";

      for(int i=0;i<image_width;i++){
        std::clog<<"\rNumber of lines remaining: "<< (image_width-i);
        for(int j=0;j<image_height;j++){
          Color pixel_color(0,0,0);
          auto pixel_center=bottom_left+Point(i,0,0)+Point(0,j,0);
          for(int k=0;k<samples_per_pixel;k++){
            Ray r(center, pixel_center+Point(random_0_1(), random_0_1(),0));
            pixel_color+=ray_color(r,world);
          }
          pixel_color*=inverse;
          write_color(std::cout,pixel_color);
        }
      }
      
      std::clog<<"\rDone.                                    \n";
    }
};


#endif 