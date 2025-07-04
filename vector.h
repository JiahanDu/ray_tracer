#include <cmath>
#include <iostream>

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

    Vector operator-() const{
      return Vector(-v[0],-v[1],-v[2]);
    }

    double operator[](int i) const{ return v[i];}

    double& operator[](int i){ return v[i];}

    T& operator+=(const Vector<T>& other){
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

    T operator+(const Vector<T>& other) const{ return Vector<T>(v[0]+other.v[0], v[1]+other.v[1], v[2]+other.v[2]);}

    Vector operator-(const Vector<T>& other) const{ return Vector<T>(v[0]-other.v[0], v[1]-other.v[1], v[2]-other.v[2]);}

    Vector operator*(double t) const{ return Vector<T>(v[0]*t, v[1]*t, v[2]*t);}

    double dot(const Vector<T>& other) const{ return v[0]*other.v[0]+v[1]*other.v[1]+v[2]*other.v[2];}

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Vector<U>& vec);

    template <typename U>
    friend Vector<U> operator*(double t, const Vector<U>& vec);

    template <typename U>
    friend Vector<U> cross(const Vector<U>& vec1, const Vector<U>& vec2);

};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& vec){
  return out<<vec.v[0]<<' '<<vec.v[1]<<' '<<vec.v[2];
}

template<typename T>
Vector<T> operator*(double t, const Vector<T>& vec){
  return Vector(vec.v[0]*t,vec.v[1]*t,vec.v[2]*t);
}

template<typename T>
Vector<T> cross(const Vector<T>& vec1, const Vector<T>& vec2){
  return Vector<T>(vec1.v[1]*vec2.v[2]-vec1.v[2]*vec2.v[1], -(vec1.v[0]*vec2.v[2]-vec1.v[2]*vec2.v[0]), vec1.v[0]*vec2.v[1]-vec1.v[1]*vec2.v[0]);
} 

#ifndef VECTOR_H
#define VECTOR_H
class Point: public Vector<Point>{ using Vector::Vector;};

class Color: public Vector<Color>{ using Vector::Vector;};
#endif