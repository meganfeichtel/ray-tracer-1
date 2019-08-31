//
//  ShadeRec.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/11/14.
//
//

#ifndef __RayTracer__ShadeRec__
#define __RayTracer__ShadeRec__

class Material;
class World;

#include <stdio.h>

#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "RGB.h"



class ShadeRec {
public:
    bool hit_an_object; //true if hits obj
    Material* material_ptr; //point to nearest obj
    
    Point3D hit_point; //world coord of intersection
    Point3D local_hit_point;
    Normal normal;
    Ray ray;
    int depth;
    RGB color;
    double t; //ray param
    float u; //texture coord
    float v; //texture coord
    World& w;
    
    ShadeRec(World& wr);
    ShadeRec(const ShadeRec& sr);
    ~ShadeRec(void);
    
    ShadeRec& operator= (const ShadeRec& rhs);
};




#endif /* defined(__RayTracer__ShadeRec__) */
