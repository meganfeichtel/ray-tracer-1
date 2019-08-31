//
//  ViewPlane.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 12/5/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#include "ViewPlane.h"




ViewPlane::ViewPlane(void)
:   hres(400),
    vres(400),
    s(0.5),
    num_samples(1),
    sampler_ptr(),
    gamma(1.0),
    inv_gamma(1.0)
    //show_out_of_gamut(false),
    //max_depth(1)
{}


ViewPlane::ViewPlane(const ViewPlane& vp)
:   hres(vp.hres),
    vres(vp.vres),
    s(vp.s),
    num_samples(vp.num_samples),
    sampler_ptr(vp.sampler_ptr),
    gamma(vp.gamma),
    inv_gamma(vp.inv_gamma)
    //show_out_of_gamut(vp.show_out_of_gamut),
    //max_depth(vp.max_depth)
{}


ViewPlane& ViewPlane::operator=(const ViewPlane& rhs) {
    if (this == &rhs)
        return (*this);
    
    hres = rhs.hres;
    vres = rhs.vres;
    s = rhs.s;
    num_samples = rhs.num_samples;
    sampler_ptr = rhs.sampler_ptr;
    gamma = rhs.gamma;
    inv_gamma = rhs.inv_gamma;
    //show_out_of_gamut = rhs.show_out_of_gamut;
    //max_depth = rhs.max_depth;
    
    return (*this);
}


ViewPlane::~ViewPlane(void) {}


void ViewPlane::set_hres(const int& c){
    hres = c;
}


void ViewPlane::set_vres(const int& c){
    vres = c;
}


void ViewPlane::set_pixel_size(const float& c){
    s = c;
}

void ViewPlane::set_gamma(const float& c){
    gamma = c;
    inv_gamma = 1.0 / gamma;
}

void ViewPlane::set_samples(const int n) {
    num_samples = n;
    
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = NULL;
    }
    
    if (num_samples > 1)
        sampler_ptr = new Multijittered(num_samples);
    else
        sampler_ptr = new Regular(1);
}

void ViewPlane::set_sampler(Sampler* sp) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = NULL;
    }
    num_samples = sp->get_num_samples();
    sampler_ptr = sp;
}

//void ViewPlane::set_gamut_display(const bool show) {
//    show_out_of_gamut = show;
//}

