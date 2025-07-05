#include "Object.h"

#ifndef CAMERA_H
#define CAMERA_H

class Camera{
  public:
    int image_width; //Number of pixels per row
    int image_height; //Number of pixels per column
    double aspect_ratio=(double)image_width/image_height; 
    Point center(0,0,0);  //Location of the camera
    Point top_left; // The bottom left corner of the view_port

    Color ray_color(const Ray& r, const Object& world) const{
        
    }  

    void render(const Object& world){
      std::cout<<"P3\n"<<image_width<<' '<<image_height<<"\n255\n";

      for(int i=0;i<height;i++){
        for(int j=0;j<height;j++){
          
        }
      }
    }
};


#endif 