//
//  Vector3D.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/11/14.
//
//

#include "Vector3D.h"
#include "Normal.h"
#include "Point3D.h"
#include <math.h>

//constructors
Vector3D::Vector3D(void)
    :    x(0.0), y(0.0), z(0.0)
{}

Vector3D::Vector3D(double c)
:    x(c), y(c), z(c)
{}

Vector3D::Vector3D(double _x, double _y, double _z)
:    x(_x), y(_y), z(_z)
{}

//from a point
Vector3D::Vector3D(const Point3D& p)
:    x(p.x), y(p.y), z(p.z)
{}


Vector3D::Vector3D(const Normal& n)
:   x(n.x), y(n.y), z(n.z)
{}

//copy constructor
Vector3D::Vector3D(const Vector3D& v)
:    x(v.x), y(v.y), z(v.z)
{}

//destructor
Vector3D::~Vector3D(void){
    
}

//assignment operator
Vector3D& Vector3D::operator= (const Vector3D& rhs){
    if (this == &rhs)
        return (*this);
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return (*this);
}

Vector3D& Vector3D::operator= (const Point3D& rhs){
    x = rhs.x, y = rhs.y, z = rhs.z;
    return (*this);
}

Vector3D& Vector3D::operator= (const Normal& rhs) {
    x = rhs.x; y = rhs.y; z = rhs.z;
    return (*this);
}

Vector3D Vector3D::operator- (void) const{
    return (Vector3D(-x, -y, -z));
}

Vector3D Vector3D::operator* (const double c) const {
    return (Vector3D(x * c, y * c, z * c));
}

Vector3D Vector3D::operator/ (const double c) const {
    return (Vector3D(x / c, y / c, z / c));
}

Vector3D Vector3D::operator+ (const Vector3D& v) const {
    return (Vector3D(x + v.x, y + v.y, z + v.z));
}

Vector3D& Vector3D::operator+= (const Vector3D& v) {
    x += v.x; y += v.y; z += v.z;
    return (*this);
}

Vector3D Vector3D::operator- (const Vector3D& v) const {
    return (Vector3D(x - v.x, y - v.y, z - v.z));
}


//dot product
double Vector3D::operator* (const Vector3D& v) const {
    return (x * v.x + y * v.y + z * v.z);
}

//cross product
Vector3D Vector3D::operator^ (const Vector3D& v) const{
    return (Vector3D(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x));
}


//length
double Vector3D::length(void){
    return (sqrt(x*x + y*y + z*z));
}

double Vector3D::len_squared(void) {
    return (x*x + y*y + z*z);
}


//normalize to unit vector
void Vector3D::normalize(void){
    double length = sqrt(x*x + y*y + z*z);
    x /= length; y /= length; z /= length;
}


Vector3D& Vector3D::hat(void) {
    double length = sqrt(x * x + y * y + z * z);
    x /= length; y /= length; z /= length;
    return (*this);
}
//matrix multiplication?



