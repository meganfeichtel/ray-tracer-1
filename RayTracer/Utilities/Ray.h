//
//  Ray.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__Ray__
#define __RayTracer__Ray__

#include <stdio.h>

#include "Point3D.h"
#include "Vector3D.h"


class Ray {
public:
    
    Point3D o;
    Vector3D d;
    
    Ray(void);
    Ray(const Point3D& origin, const Vector3D& dir);
    
    Ray(const Ray& ray);
    
    Ray& operator= (const Ray& rhs);
    
    ~Ray(void);
};


#endif /* defined(__RayTracer__Ray__) */
