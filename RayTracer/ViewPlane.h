//
//  ViewPlane.h
//  RayTracer
//
//  Created by Megan Feichtel on 12/5/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__ViewPlane__
#define __RayTracer__ViewPlane__

#include <stdio.h>
#include "Sampler.h"
#include "Jittered.h"
#include "Regular.h"
#include "Multijittered.h"


class ViewPlane{
public:
    int hres;
    int vres;
    float s;
    int num_samples;
    float gamma;
    float inv_gamma;
    Sampler* sampler_ptr;
    //bool show_out_of_gamut;
    //int max_depth;
    
    ViewPlane();
    ViewPlane(const ViewPlane& vp);
    ViewPlane& operator=(const ViewPlane& rhs);
    ~ViewPlane();
    
    void set_hres(const int& c);
    void set_vres(const int& c);
    void set_pixel_size(const float& c);
    void set_gamma(const float& c);
    void set_samples(const int n);
    void set_sampler(Sampler* sp);
    //void set_gamut_display(const bool show);
};


#endif /* defined(__RayTracer__ViewPlane__) */
