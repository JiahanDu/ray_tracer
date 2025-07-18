#include <cmath>
#include <iostream>
#include "rng.h"

#ifndef VECTOR_H
#define VECTOR_H

constexpr double pi=3.141592653589793238;

template <typename T>
class Vector{

  public:
    double v[3];

  public:
    
    Vector():v{0,0,0}{}

    Vector(double x, double y, double z): v{x,y,z}{}

    double x() const{ return v[0];}
    
    double y() const{ return v[1];}

    double z() const{ return v[2];}

    T operator-() const{
      return T(-v[0],-v[1],-v[2]);
    }

    double operator[](int i) const{ return v[i];}

    double& operator[](int i){ return v[i];}

    T& operator+=(const T& other){
      v[0]+=other.v[0];
      v[1]+=other.v[1];
      v[2]+=other.v[2];
      return *static_cast<T*>(this);
    }

    T& operator *=(double t){
      v[0]*=t;
      v[1]*=t;
      v[2]*=t;
      return *static_cast<T*>(this);
    }

    T& operator /=(double t){
      t=1/t;
      v[0]*=t;
      v[1]*=t;
      v[2]*=t;
      return *static_cast<T*>(this);
    }

    double length_squared() const{ return v[0]*v[0]+v[1]*v[1]+v[2]*v[2]; }

    double length() const{ return std::sqrt(length_squared());}

    T normalized() const{
      return *this/length();
    }

    T operator+(const T& other) const{ return T(v[0]+other.v[0], v[1]+other.v[1], v[2]+other.v[2]);}

    T operator-(const T& other) const{ return T(v[0]-other.v[0], v[1]-other.v[1], v[2]-other.v[2]);}

    T operator*(double t) const{ return T(v[0]*t, v[1]*t, v[2]*t);}

    T operator/(double t) const{
      double u=1/t;
      return T(v[0]*u, v[1]*u, v[2]*u);
    }
};

template<typename T>
double dot(const T& vec1, const T& vec2){return vec1.v[0]*vec2.v[0]+vec1.v[1]*vec2.v[1]+vec1.v[2]*vec2.v[2];}

template<typename T>
T cross(const T& vec1, const T& vec2){return T(vec1.v[1]*vec2.v[2]-vec1.v[2]*vec2.v[1], -vec1.v[0]*vec2.v[2]+vec1.v[2]*vec2.v[0], vec1.v[0]*vec2.v[1]-vec1.v[1]*vec2.v[0]);} 

template<typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& vec){return out<<vec.v[0]<<' '<<vec.v[1]<<' '<<vec.v[2];}

template<typename T>
T operator*(double t, const Vector<T>& vec){ return T(vec.v[0]*t,vec.v[1]*t,vec.v[2]*t);}

class Point: public Vector<Point>{ 

  public:
  Point(): Vector<Point>{0,0,0}{}
  Point(double x, double y, double z): Vector<Point>{x,y,z}{}
  static Point sphere(){
    double u,v,s;
    do{
      u=random_min_max(-1,1);
      v=random_min_max(-1,1);
      s=u*u+v*v;
    }while(s>=1.0||s==0);
    double f=std::sqrt(1.0-s);
    return Point(2.0*u*f, 2.0*v*f, 1.0-2.0*s);
  } // Generate a random vector uniformly distributed on the sphere
};

class Color: public Vector<Color>{
  public:
    Color(): Vector<Color>{0,0,0}{}
    Color(double x, double y, double z): Vector<Color>{x,y,z}{}
};
#endif