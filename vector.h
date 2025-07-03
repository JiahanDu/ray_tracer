#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

template <typename Derived>
class vector{

  public:
    double v[3];

  public:
    vector():v{0,0,0}{}

    vector(double x, double y, double z): v{x,y,z}{}

    double x() const{
      return v[0];
    }
    
    double y() const{
      return v[1];
    }

    double z() const{
      return v[2];
    }

    vector operator-() const{
      return vector(-v[0],-v[1],-v[2]);
    }

    double operator[](int i) const{
      return v[i];
    }

    double& operator[] (int i){
      return e[i];
    }

    vector& operator+=(const vector& other){
      v[0]+=other.v[0];
      v[1]+=other.v[1];
      v[2]+=other.v[2];
      return *this;
    }

    vector& operator *=(double t){
      v[0]*=t;
      v[1]*=t;
      v[2]*=t;
      return *this;
    }

    vector& operator /=(double t){
      return *this*=1/t;
    }

    double length_squared() const{
      return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];
    }

    double length() const{
      return std::sqrt(length_squared());
    }
};

using point3=vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v){
  return out<<v.e[0]<<' '<<v.e[1]<<' '<<v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v){
  return vec3(u.e[0]+v.e[0], u.e[1]+v.e[1], u.e[2]+v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v){
  return vec3(u.e[0]-v.e[0],u.e[1]-v.e[1],u.e[2]-v.e[2]);
}

inline vec3 operator*(double t, const vec3& v){
  return vec3(t*v.e[0],t*v.e[1],t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t){
  return t*v;
}

inline vec3 operator/(const vec3& v, double t){
  return (1/t)*v;
}

inline double dot(const vec3& u, const vec3& v){
  return u.e[0]*v.e[0]+u.e[1]*v.e[1]+u.e[2]*v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v){
  return vec3(u.e[1]*v.e[2]-u.e[2]*v.e[1], -(u.e[0]*v.e[2]-u.e[2]*v.e[0]), u.e[0]*v.e[1]-u.e[1]*v.e[0]);
}

inline vec3 normalize(const vec3& v){
  return v/v.length();
}

#endif 