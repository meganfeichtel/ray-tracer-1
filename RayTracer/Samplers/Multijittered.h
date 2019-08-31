//
//  Multijittered.h
//  RayTracer
//
//  Created by Megan Feichtel on 12/10/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__Multijittered__
#define __RayTracer__Multijittered__

#include <stdio.h>
#include "Sampler.h"

class Multijittered: public Sampler {
public:
    
    Multijittered(void);
    Multijittered(const int num_samples);
    Multijittered(const int num_samples, const int m);
    Multijittered(const Multijittered& u);
    
    Multijittered& operator= (const Multijittered& rhs);
    virtual Multijittered* clone(void) const;
    
    virtual ~Multijittered(void);
    
private:
    virtual void generate_samples(void);

};


#endif /* defined(__RayTracer__Multijittered__) */
