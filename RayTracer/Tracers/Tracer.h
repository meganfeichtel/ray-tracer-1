//
//  Tracer.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__Tracer__
#define __RayTracer__Tracer__

#include <stdio.h>

#include "Constants.h"
#include "Ray.h"
#include "RGB.h"


class World;

class Tracer {
public:
    Tracer(void);
    
    Tracer(World* _world_ptr);
    virtual ~Tracer(void);
    virtual RGB trace_ray(const Ray& ray) const;
    virtual RGB trace_ray(const Ray ray, const int depth) const;
    
protected:
    World* world_ptr;
};




#endif /* defined(__RayTracer__Tracer__) */
