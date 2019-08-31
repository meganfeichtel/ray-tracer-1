//
//  Regular.h
//  RayTracer
//
//  Created by Megan Feichtel on 12/10/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__Regular__
#define __RayTracer__Regular__

#include <stdio.h>
#include "Sampler.h"


class Regular: public Sampler {
public:
    Regular(void);
    Regular(const int num);
    Regular(const Regular& u);
    
    Regular& operator= (const Regular& rhs);
    
    virtual Regular* clone(void) const;
    virtual ~Regular(void);
    virtual void generate_samples(void);
    
};

#endif /* defined(__RayTracer__Regular__) */
