//
//  Material.h
//  RayTracer
//
//  Created by Megan Feichtel on 12/5/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__Material__
#define __RayTracer__Material__

#include <stdio.h>

#include "World.h"
#include "RGB.h"
#include "ShadeRec.h"

class Material {
public:
    Material( void);
    
    Material(const Material& material);
    
    virtual Material* clone( void) const = 0;
    
    virtual ~Material( void);
    
 //   virtual RGB shade(ShadeRec& sr);
    
    Material& operator= (const Material& rhs);
};




#endif /* defined(__RayTracer__Material__) */



