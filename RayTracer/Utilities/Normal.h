//
//  Normal.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__Normal__
#define __RayTracer__Normal__

#include <stdio.h>

#include "Point3D.h"
#include "Matrix.h"
#include "Vector3D.h"


class Normal {
public:
    
    double x, y, z;
    
    Normal( void);
    Normal(double c);
    Normal( double cx, double cy, double cz);
    Normal(const Normal& n);
    Normal(const Vector3D& v);
    ~Normal(void);
    
    Normal& operator= (const Normal& rhs);
    Normal& operator=(const Point3D& rhs);
    Normal& operator=(const Vector3D& rhs);
    Normal operator- (void);
    Normal operator+ (const Normal& n);
    Normal& operator+= (const Normal& n);
    
    double operator*(const Vector3D& v); //vector on right
    double multiply(const Vector3D& v, const Normal& n); //vector on right
    
    Vector3D add(const Vector3D& v, const Normal& n);
    
    Vector3D subtract(const Vector3D v, const Normal& n);

    void normalize(void);

};


#endif /* defined(__RayTracer__Normal__) */


