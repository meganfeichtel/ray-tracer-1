//
//  Ray.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#include "Ray.h"

//constructors
Ray::Ray (void){
    o = Point3D();
    d = Vector3D();
}

Ray::Ray(const Point3D& origin, const Vector3D& dir){
    o = origin;
    d = dir;
}

//copy constructor
Ray::Ray(const Ray& ray){
    o = ray.o;
    d = ray.d;
}

//assignment operator
Ray& Ray::operator= (const Ray& rhs){
    if (this == &rhs)
        return (*this);
    o = rhs.o;
    d = rhs.d;
    return (*this);
}


//deconstructor
Ray::~Ray(void){
    
}