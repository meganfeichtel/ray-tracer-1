//
//  Jittered.h
//  RayTracer
//
//  Created by Megan Feichtel on 12/10/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__Jittered__
#define __RayTracer__Jittered__

#include <stdio.h>
#include "Sampler.h"



class Jittered: public Sampler {

public:
    Jittered(void);
    Jittered(const int num_samples);
    Jittered(const int num_samples, const int m);
    Jittered(const Jittered& js);
    
    Jittered& operator= (const Jittered& rhs);
    virtual Jittered* clone(void) const;
    
    virtual ~Jittered(void);
    
private:
    virtual void generate_samples(void);
};





#endif /* defined(__RayTracer__Jittered__) */
