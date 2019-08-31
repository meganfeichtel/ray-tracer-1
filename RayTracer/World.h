//
//  World.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__World__
#define __RayTracer__World__

#include <stdio.h>
#include <vector>

#include "ViewPlane.h"
#include "RGB.h"
#include "GeometricObject.h"
#include "Sphere.h"
#include "SingleSphere.h"
#include "Tracer.h"
#include <math.h>
#include "Ray.h"
#include "ImageIO.h"


class World {
public:
    ViewPlane vp;
    RGB background_color;
    Sphere sphere;
    Tracer* tracer_ptr;
    ImageIO* image;
    vector<GeometricObject*> objects;
    
    
    World(void);
    ~World();
    
    void build(void);
    
    void add_object(GeometricObject* object_ptr);
    
    ShadeRec hit_bare_bones_objects(const Ray& ray);
    
    void render_scene(void) const;
    void display_pixel(const int row, const int column, const RGB& pixel_color) const;
    ImageIO* return_image(void);
};




#endif /* defined(__RayTracer__World__) */
