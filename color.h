#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

using color=vec3;

void write_color(std::ostream& out, const color& pixel_color){
    auto r=pixel_color.x();
    auto g=pixel_color.y();
    auto b=pixel_color.z();
    
    int rint=int(255.999*r);
    int gint=int(255.999*g);
    int bint=int(255.999*b);
    
    out<<rint<<' '<<gint<<' '<<bint<<'\n'; 
}

#endif 