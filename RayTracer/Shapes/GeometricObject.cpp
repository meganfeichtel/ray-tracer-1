//
//  GeometricObject.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#include "GeometricObject.h"
#include "Constants.h"
#include "Material.h"



GeometricObject::GeometricObject(void)
    :   color(black),
        material_ptr(NULL)
        //shadows(true)
{}

//void GeometricObject::add_object(GeometricObject* object_ptr) {}

Normal GeometricObject::get_normal(void){
    return (Normal());
}

Normal GeometricObject::get_normal(const Point3D& p){
    return (Normal());
}



// set color
void GeometricObject::set_color(const RGB& c) {
    color = c;
}


void GeometricObject::set_color(const float r, const float g, const float b) {
    color.r = r;
    color.b = b;
    color.g = g;
}

//get color

RGB GeometricObject::get_color(void) {
    return (color);
}



//void
//GeometricObject::set_material(Material* mPtr) {
//    material_ptr = mPtr;
//}

//Material*
//GeometricObject::get_material(void) const {
//    return (material_ptr);
//}
