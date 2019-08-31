//
//  GeometricObject.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef __RayTracer__GeometricObject__
#define __RayTracer__GeometricObject__

#include <stdio.h>

#include "Constants.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"
#include "RGB.h"
#include "Normal.h"
#include "ShadeRec.h"



class GeometricObject {
public:
    
    GeometricObject(void);
    virtual Normal get_normal(void);
    //void set_material(Material* mPtr);
    //Material* get_material(void);
    virtual Normal get_normal(const Point3D& p);
    
    virtual bool hit(const Ray& ray, double& min, ShadeRec& sr) const = 0;
    
    void
    set_color(const RGB& c);
				
    void
    set_color(const float r, const float g, const float b);
    
    RGB
    get_color(void);
    
    
//    virtual void
//    set_bounding_box(void);
//    
//    virtual BBox
//    get_bounding_box(void);
protected:
    RGB color;
    mutable Material*   material_ptr;
    
};



#endif /* defined(__RayTracer__GeometricObject__) */
