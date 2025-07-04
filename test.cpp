#include "Vector.h"
int main(){
    Color x= Color(1,2,3);
    Color y= Color(1,3,5);

    Point z=Point(3,2,-0.1);
    Point w=Point(-1.4,2,9);

    std::cout<<cross(z,w)<<std::endl;
}