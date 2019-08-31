//
//  Point3D.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/11/14.
//
//

#include <math.h>
#include "Point3D.h"


//constructors
Point3D::Point3D(void)
:   x(0.0), y(0.0), z(0.0)
{}

Point3D::Point3D(const double a)
:    x(a), y(a), z(a)
{}

Point3D::Point3D(const double a, const double b, const double c)
:    x(a), y(b), z(c)
{}


Point3D::Point3D(const float x1, const float y1)
:   x(x1),
    y(y1),
    z(0.0)
{}

//copy constructor
Point3D::Point3D( const Point3D& p)
    :    x(p.x), y(p.y), z(p.z)
{}

//destructor
Point3D::~Point3D(void){
    
}

//assignment operator
Point3D& Point3D::operator= (const Point3D& rhs) {
    if (this == &rhs)
        return (*this);
    
    x = rhs.x; y=rhs.y; z = rhs.z;
    
    return (*this);
}


Point3D Point3D::operator-(void) const {
    return (Point3D(-x, -y, -z));
    
}


Vector3D Point3D::operator-(const Point3D& p) const {
    return (Vector3D(x-p.x, y - p.y, z - p.z));
}


Point3D Point3D::operator+ (const Vector3D& c) const{
    return (Point3D(x+c.x, y+c.y, z+c.z));
}


Point3D Point3D::operator-(const Vector3D& v) const {
    return (Point3D(x - v.x, y - v.y, z - v.z));
}

Point3D Point3D::operator* (const double a) const {
    return (Point3D(x * a, y * a, z * a));
}

double Point3D::d_squared(const Point3D &p) const {
    return (((x-p.x)*(x-p.x)) + ((y-p.y)*(y-p.y)) +((z-p.z)*(z-p.z)));
}


//Point3D operator* (double a, const Point3D& p) {
//    return (Point3D(a * p.x, a * p.y, a * p.z));
//}


double Point3D::distance(const Point3D& p) const {
    return (sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z)));
}


//matrix multiplication?




