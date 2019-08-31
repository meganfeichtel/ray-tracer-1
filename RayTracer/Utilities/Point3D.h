//
//  Point3D.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/11/14.
//
//

#ifndef __RayTracer__Point3D__
#define __RayTracer__Point3D__

#include "Matrix.h"
#include "Vector3D.h"
#include <stdio.h>


class Point3D {
    
public:
    
    double x, y, z;
    
    Point3D();
    Point3D(const double a);
    Point3D(const double a, const double b, const double c);
    Point3D(const float x1, const float y1);
    Point3D( const Point3D& p);
    ~Point3D(void);
    
    //double distance(const Point3D& c) const;
    
    Point3D& operator= (const Point3D& rhs);
    Point3D operator- (void) const;
    Vector3D operator- (const Point3D& p) const;
    Point3D operator+ (const Vector3D& v) const;
    Point3D operator- (const Vector3D& v) const;
    Point3D operator* (const double a) const;
    double d_squared(const Point3D& p) const;
    double distance(const Point3D& p) const;
    
   // Point3D operator* (double a, const Point3D& p);
    
};


#endif /* defined(__RayTracer__Point3D__) */

