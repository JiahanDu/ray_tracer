#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>
bool hit_sphere(const point3& center, double radius, const ray& r){
    vec3 oc=center-r.origin();
    double a=dot(r.direction(),r.direction());
    double b=-2.0*dot(r.direction(),oc);
    double c=dot(oc,oc)-radius*radius;
    return b*b>=4*a*c;
}

color ray_color(const ray& r){
    if(hit_sphere(point3(0,0,1),0.5,r)){
        return color(1,0,0);
    }
    vec3 unit_direction=normalize(r.direction());
    double a=0.5*(unit_direction.y()+1.0);
    return (1.0-a)*color(1.0,1.0,1.0)+a*color(0.5,0.7,1.0);
}

int main(){
    double aspect_ratio=16.0/9.0;
    int image_width=400;

    int image_height=int(image_width/aspect_ratio);
    image_height=(image_height<1)? 1:image_height;

    double viewport_height=2.0;
    double viewport_width=viewport_height*(double(image_width)/image_height);
    double focal_length=1.0;

    vec3 camera_center=point3(0,0,0);
    vec3 viewport_x=vec3(viewport_width,0,0); //x axis vector
    vec3 viewport_y=vec3(0,viewport_height,0);//y axis vector

    vec3 pixel_x=viewport_x/image_width; //x axis vector per pixel
    vec3 pixel_y=viewport_y/image_height; //y axis vector per pixel

    vec3 pixel00_loc=camera_center+vec3(0,0,focal_length)-viewport_x/2-viewport_y/2+0.5*(pixel_x+pixel_y);

    std::cout<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";

    for(int i=0;i<image_height;i++){
        std::clog<<"\rScanlines remaining: "<<image_height-i<<' '<<std::flush;
        for(int j=0;j<image_width;j++){
            vec3 pixel_center=pixel00_loc+i*pixel_y+j*pixel_x;
            vec3 ray_direction=pixel_center-camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color=ray_color(r);
            write_color(std::cout,pixel_color);

        }
    }

    std::clog<<"\rDone.                       \n"<<std::flush;
}
