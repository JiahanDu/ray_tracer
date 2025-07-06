#include "Object.h"

#ifndef CAMERA_H
#define CAMERA_H

class Camera{
  public:
    int image_width; //Number of pixels per row
    int image_height; //Number of pixels per column
    double aspect_ratio; // The ratio of image_width to image_height 
    Point center;  //Location of the camera
    Point bottom_left; // The bottom left corner of the view_port

    Camera(int width, int height, int x, int y, int z): image_width(width), image_height(height), aspect_ratio(double(width)/height), center(0,0,0), bottom_left(x,y,z){}

    Color ray_color(const Ray& r, const Object& world) const{
        //To be implemented
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
          auto pixel_center=bottom_left+Point(i,0,0)+Point(0,j,0);
          Ray r(center, pixel_center);
          Color pixel_color=ray_color(r, world);
          write_color(std::cout,pixel_color);
        }
      }
      
      std::clog<<"\rDone.                 \n";
    }
};


#endif 