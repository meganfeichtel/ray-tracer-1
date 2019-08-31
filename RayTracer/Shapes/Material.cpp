//
//  Material.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 12/5/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#include "Material.h"


Material::Material( void) {}


Material::Material(const Material& m) {}

Material& Material::operator=(const Material& rhs) {
    if (this == &rhs)
        return (*this);
    return (*this);
}


Material::~Material(void)
{}

//RGB
//Material::shade(ShadeRec& sr) {
//    return (black);
//}