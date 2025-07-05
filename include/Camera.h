#include "Object.h"

#ifndef CAMERA_H
#define CAMERA_H

class Camera{
  public:
    int image_width; //Number of pixels per row
    int image_height; //Number of pixels per column
    double aspect_ratio=(double)image_width/image_height; 
    Point center(0,0,0);  //Location of the camera
    Point top_left; // The top left corner of the view_port

    void initialize(){
      
    }
    
    Color ray_color(const Ray& r, const Object& world) const{
        
    }  

    void render(const Object& world){

    }
};


#endif 