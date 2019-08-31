//
//  ShadeRec.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/11/14.
//
//

#include "Constants.h"
#include "ShadeRec.h"


ShadeRec::ShadeRec(World& wr)
    :  hit_an_object(false),
        material_ptr(NULL),
        hit_point(),
        local_hit_point(),
        normal(),
        ray(),
        depth(0),
        color(black),
        t(0.0),
        u(0.0),
        v(0.0),
        w(wr)
{}


ShadeRec::ShadeRec(const ShadeRec& sr)
: 	hit_an_object(sr.hit_an_object),
    material_ptr(sr.material_ptr),
    hit_point(sr.hit_point),
    local_hit_point(sr.local_hit_point),
    normal(sr.normal),
    ray(sr.ray),
    depth(sr.depth),
    color(sr.color),
    t(sr.t),
    u(sr.u),
    v(sr.v),
    w(sr.w)
{}


ShadeRec::~ShadeRec(void) {
//    if (material_ptr) {
//        delete material_ptr;
//        material_ptr = NULL;
//    }
}


