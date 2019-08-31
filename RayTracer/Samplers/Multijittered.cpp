//
//  Multijittered.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 12/10/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#include "Multijittered.h"

Multijittered::Multijittered(void)
:   Sampler()
{}


Multijittered::Multijittered(const int num_samples)
:   Sampler(num_samples){
    generate_samples();
    
}


Multijittered::Multijittered(const int num_samples, const int m)
:   Sampler(num_samples, m) {
    generate_samples();
}


Multijittered::Multijittered(const Multijittered& u)
:   Sampler(u) {
    generate_samples();
}


Multijittered& Multijittered::operator=(const Multijittered& rhs) {
    if (this == &rhs)
        return (*this);
    
    Sampler::operator=(rhs);
    return (*this);
}


Multijittered* Multijittered::clone(void) const {
    return (new Multijittered(*this));
}


Multijittered::~Multijittered(void) {}


void Multijittered::generate_samples(void) {
    int n = (int)sqrt((float)num_samples);
    float width = 1.0 / ((float) num_samples);
    

    Point3D fill_point;
    for (int j = 0; j < num_samples * num_sets; j++)
        samples.push_back(fill_point);
    
    // distribute points in the initial patterns
    
    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                samples[i * n + j + p * num_samples].x = (i * n + j) * width + ((float)rand()/(float)(RAND_MAX));
                samples[i * n + j + p * num_samples].y = (j * n + i) * width + ((float)rand()/(float)(RAND_MAX));
            }
    //x
    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int k = j + (rand() % (int)(n - j));
                float t = samples[i * n + j + p * num_samples].x;
                samples[i * n + j + p * num_samples].x = samples[i * n + k + p * num_samples].x;
                samples[i * n + k + p * num_samples].x = t;
            }
    //y
    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int k = j + (rand() % (int)(n - j));
                float t = samples[j * n + i + p * num_samples].y;
                samples[j * n + i + p * num_samples].y = samples[k * n + i + p * num_samples].y;
                samples[k * n + i + p * num_samples].y = t;
            }
}




