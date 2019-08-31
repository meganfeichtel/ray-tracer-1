//
//  Sampler.h
//  RayTracer
//
//  Created by Megan Feichtel on 12/10/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__Sampler__
#define __RayTracer__Sampler__

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "Point3D.h"



class Sampler {
public:
    
    Sampler(void);
    Sampler(const int num);
    Sampler(const int num, const int num_sets);
    Sampler(const Sampler& s);
    
    Sampler& operator= (const Sampler& rhs);
    
    virtual Sampler* clone(void) const = 0;
    
    virtual ~Sampler(void);
    virtual void generate_samples(void) = 0;
    int get_num_samples(void);
    void setup_shuffled_indices(void);
    Point3D sample_unit_square(void);
    
    void set_num_sets(const int np);
    void map_samples_to_unit_disk(void);
    void map_samples_to_hemisphere(const float e);
    

protected:
    int num_samples;
    int num_sets;
    std::vector<Point3D> samples;
    std::vector<int> shuffled_indices;
    
    unsigned long count;
    int jump;
    
    std::vector<Point3D> disk_samples;
    std::vector<Point3D> hemisphere_samples;
//    vector<Point3D*> sphere_samples;
};

#endif /* defined(__RayTracer__Sampler__) */
