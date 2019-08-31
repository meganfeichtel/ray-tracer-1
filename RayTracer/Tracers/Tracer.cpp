//
//  Tracer.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#include "Tracer.h"


Tracer::Tracer(void)
:   world_ptr(NULL)
{}


Tracer::Tracer(World* _worldPtr)
:   world_ptr(_worldPtr)
{}


Tracer::~Tracer(void) {
    if (world_ptr)
        world_ptr = NULL;
}


RGB Tracer::trace_ray(const Ray &ray) const {
    return (black);
}


RGB Tracer::trace_ray(const Ray ray, const int depth) const {
    return (black);
}