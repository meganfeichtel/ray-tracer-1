//
//  Vector3D.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/11/14.
//
//

#ifndef __RayTracer__Vector3D__
#define __RayTracer__Vector3D__

#include "Matrix.h"
#include <stdio.h>


class Normal;
class Point3D;

class Vector3D {
    
public:
    double x, y, z;
    
    Vector3D(void);
    Vector3D(double c);
    Vector3D(double _x, double _y, double _z);
    Vector3D(const Point3D& p);
    Vector3D(const Vector3D& v);
    Vector3D(const Normal& n);
    ~Vector3D(void);
    
    Vector3D& operator= (const Vector3D& rhs);
    Vector3D& operator= (const Normal& rhs);
    Vector3D& operator= (const Point3D& rhs);
    Vector3D operator- (void) const;
    Vector3D operator* (const double c) const;
    Vector3D operator/ (const double c) const;
    Vector3D operator+ (const Vector3D& v) const;
    Vector3D& operator+= (const Vector3D& v);
    Vector3D operator- (const Vector3D& v) const;
    
    //dot product
    double operator* (const Vector3D& v) const;
    
    //cross product
    Vector3D operator^ (const Vector3D& v) const;
    
    Vector3D& hat(void);
    double length(void);
    double len_squared(void);
    void normalize(void);
    
    
};



#endif /* defined(__RayTracer__Vector3D__) */


