//
//  MultipleObjects.h
//  RayTracer
//
//  Created by Megan Feichtel on 12/9/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__MultipleObjects__
#define __RayTracer__MultipleObjects__

#include <stdio.h>
#include "Tracer.h"

class MultipleObjects: public Tracer {
public:
    MultipleObjects(void);
    MultipleObjects(World* _world_ptr);
    
    virtual ~MultipleObjects(void);
    
    virtual RGB trace_ray(const Ray& ray) const;
};


#endif /* defined(__RayTracer__MultipleObjects__) */
