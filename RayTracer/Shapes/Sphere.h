//
//  Sphere.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__Sphere__
#define __RayTracer__Sphere__

#include <stdio.h>

#include "GeometricObject.h"

class Sphere: public GeometricObject {
public:
    Sphere(void);
    Sphere(Point3D center, double r);
    Sphere(const Sphere& sphere);
    virtual Sphere* clone(void) const;
    virtual ~Sphere(void);
    
    Sphere& operator=(const Sphere& sphere);
    void set_center(const Point3D c);
    void set_center(const double x, const double y, const double z);
    
    void set_radius(const double r);
    
    virtual bool hit (const Ray& ray, double& t, ShadeRec& s) const;

private:
    Point3D center;
    double radius;
    
    static const double kEpsilon;
};


#endif /* defined(__RayTracer__Sphere__) */
