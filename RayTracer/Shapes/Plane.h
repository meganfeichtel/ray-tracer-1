//
//  Plane.h
//  RayTracer
//
//  Created by Megan Feichtel on 12/5/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__Plane__
#define __RayTracer__Plane__

#include <stdio.h>

#include "GeometricObject.h"


class Plane: public GeometricObject {
    
public:
    Plane(void);
    Plane(const Point3D& point, const Normal& normal);
    Plane( const Plane& plane);
 //   virtual Plane* clone(void) const;
    Plane& operator=(const Plane& rhs);
    
    virtual ~Plane(void);
    
    virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;
    
private:
    Point3D a;
    Normal n;

    static const double kEpsilon;   // for shadows and secondary rays
};

#endif /* defined(__RayTracer__Plane__) */
