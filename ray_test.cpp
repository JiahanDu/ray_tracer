#include <iostream>

int main(){
    int image_width=256;
    int image_height=256;

    std::cout<<"P3\n"<<image_width<<' '<<image_height<<"\n 255\n";

    for(int i=0;i<image_height;i++){
        std::clog<<"\rScanlines remaining: "<<image_height-i<<' '<<std::flush;
        for(int j=0;j<image_width;j++){
            int r=i;
            int g=j;
            int b=0;

            std::cout<<r<<' '<<g<<' '<<b<<'\n';
        }
    }
    std::clog<<"\rDone.                        \n";
}