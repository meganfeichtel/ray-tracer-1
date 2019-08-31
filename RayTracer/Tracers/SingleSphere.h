//
//  SingleSphere.h
//  RayTracer
//
//  Created by Megan Feichtel on 12/8/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__SingleSphere__
#define __RayTracer__SingleSphere__

#include <stdio.h>

#include "Tracer.h"

class SingleSphere: public Tracer {
public:
    
    SingleSphere(void);
    SingleSphere(World* _worldPtr);
    
    virtual ~SingleSphere(void);
    virtual RGB trace_ray(const Ray& ray) const;
    
};



#endif /* defined(__RayTracer__SingleSphere__) */
