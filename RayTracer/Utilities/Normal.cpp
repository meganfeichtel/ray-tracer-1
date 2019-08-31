//
//  Normal.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#include "Normal.h"
#include <math.h>

//constructors
Normal::Normal( void){
    x=0.0, y=0.0, z=0.0;
    
}

Normal::Normal(double c){
    x = c, y = c, z = c;
}

Normal::Normal( double cx, double cy, double cz){
    x = cx, y = cy, z = cz;
}

//copy constructor
Normal::Normal(const Normal& n){
    x = n.x, y = n.y, z = n.z;
}

//from a vector
Normal::Normal(const Vector3D& v){
    x = v.x, y = v.y, z = v.z;
}

Normal::~Normal(void){
    
}

//assignment operator
Normal& Normal::operator= (const Normal& rhs){
    if (this == &rhs)
        return (*this);
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return (*this);
}


Normal& Normal::operator= (const Vector3D& rhs) {
    x = rhs.x; y = rhs.y; z = rhs.z;
    return (*this);
}

Normal& Normal::operator=(const Point3D& rhs){
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return (*this);
}

Normal Normal::operator- (void) {
    return (Normal(-x, -y, -z));
}

Normal Normal::operator+ (const Normal& n){
    return (Normal(x + n.x, y + n.y, z+ n.z));
}

Normal& Normal::operator+= (const Normal& n){
    x += n.x; y += n.y; z += n.z;
    return (*this);
}

//normalize a normal
void Normal::normalize(void){
    double length = sqrt(x * x + y * y + z * z);
    
    x = x/length, y =y/length, z = z/length;
}

//dot product with vector on right
double Normal::operator*(const Vector3D& v){
    return ((x * v.x) + (y * v.y) + (z * v.z));
}

//vector on left
double multiply(const Vector3D& v, const Normal& n){
    return ((v.x * n.x) + (v.y * n.y) + (v.z *n.z));
}


Vector3D add(const Vector3D v, const Normal& n){
    return (Vector3D(v.x + n.x, v.y + n.y, v.z + n.z));
}

Vector3D subtract(const Vector3D v, const Normal& n){
    return (Vector3D(v.x-n.x, v.y - n.y, v.z - n.z));
}



