//
//  MultipleObjects.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 12/9/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#include "MultipleObjects.h"
#include "World.h"


MultipleObjects::MultipleObjects(void)
:   Tracer()
{}


MultipleObjects::MultipleObjects(World* _worldPtr)
:   Tracer(_worldPtr)
{}


MultipleObjects::~MultipleObjects(void) {}


RGB MultipleObjects::trace_ray(const Ray &ray) const {
    ShadeRec sr(world_ptr->hit_bare_bones_objects(ray));
    
    if (sr.hit_an_object)
        return (sr.color);
    else
        return(world_ptr->background_color);
}