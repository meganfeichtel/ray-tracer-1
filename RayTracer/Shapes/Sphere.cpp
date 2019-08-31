//
//  Sphere.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#include "Sphere.h"
#include "math.h"

const double Sphere::kEpsilon = 0.001;

Sphere::Sphere(void)
:   GeometricObject(),
    center(0.0),
    radius(1.0)
{}


Sphere::Sphere(Point3D c, double r)
:   GeometricObject(),
    center(c),
    radius(r)
{}


Sphere* Sphere::clone(void) const {
    return (new Sphere(*this));
    
}

Sphere::Sphere (const Sphere& sphere)
:   GeometricObject(sphere),
    center(sphere.center),
    radius(sphere.radius)
{}

Sphere& Sphere::operator= (const Sphere& rhs) {
    if (this == &rhs)
        return (*this);
    GeometricObject::operator=(rhs);
    center = rhs.center;
    radius = rhs.radius;
    
    return (*this);
}

Sphere::~Sphere(void) {}


void Sphere::set_center(const Point3D c){
    center = c;
}

void Sphere::set_center(const double x, const double y, const double z){
    center.x = x;
    center.y = y;
    center.z = z;
}

void Sphere::set_radius(const double r){
    radius = r;
}


bool Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const{
    double t;
    Vector3D temp = ray.o - center;
    //Point3D temp = ray.o - center;
    double a = ray.d * ray.d;
    double b = temp * 2.0 * ray.d;
    double c = (temp * temp) - (radius * radius);
    double disc = (b*b) - (4.0 * a * c);
    
    if (disc < 0.0)
        return(false);
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        
        t = ((-b) - e) / denom;
        if (t > kEpsilon){
            tmin = t;
            sr.normal = (temp + (ray.d * t)) / radius;
            sr.local_hit_point = ray.o + (ray.d * t);
            return (true);
        }
        
        t = ((-b) + e) / denom;
        if (t > kEpsilon) {
            tmin = t;
            sr.normal   = (temp + (ray.d * t)) / radius;
            sr.local_hit_point = ray.o + (ray.d * t);
            return (true);
        }
        
    }
    return (false);
}







