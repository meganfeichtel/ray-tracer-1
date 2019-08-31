//
//  World.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//


#include "World.h"

//Shapes
#include "Plane.h"
#include "Sphere.h"

//Tracers
#include "SingleSphere.h"
#include "MultipleObjects.h"

//Utilities
#include "Constants.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "ShadeRec.h"



//Build Functions
//#include "BuildSingleSphere.cpp"

World::World(void)
:   background_color(black),
    tracer_ptr(NULL)
{}


World::~World(void) {
    if(tracer_ptr) {
        delete tracer_ptr;
        tracer_ptr = NULL;
    }
}


void World::add_object(GeometricObject* object_ptr) {
    objects.push_back(object_ptr);
}


void World::build(void) {
    
    
    
   /*
    */
    //Multiple Objects
    int num_samples = 16;
    
    vp.set_hres(800);
    vp.set_vres(800);
    vp.set_pixel_size(0.5);
    vp.set_samples(16);
    vp.set_gamma(1.0);
    vp.set_sampler(new Jittered(num_samples));
    background_color = black;
    tracer_ptr = new MultipleObjects(this);
    image = new ImageIO(vp.hres, vp.vres, 255);
    
    // colours
    
    RGB yellow(1, 1, 0);
    RGB brown(0.71, 0.40, 0.16);
    RGB dark_green(0.0, 0.41, 0.41);
    RGB orange(1.0, 0.75, 0.0);
    RGB green(0.0, 0.6, 0.3);
    RGB light_green(0.65, 1.0, 0.30);
    RGB dark_yellow(0.61, 0.61, 0.0);
    RGB light_purple(0.65, 0.3, 1.0);
    RGB dark_purple(0.5, 0.0, 1.0);
    RGB light_blue(0.0, 1.0, 1.0);
    RGB blue(0.0, 0.0, 1.0);
    
    
    // spheres
				
    Sphere*	sphere_ptr1 = new Sphere(Point3D(5, 3, 0), 30);
    sphere_ptr1->set_color(yellow);
    add_object(sphere_ptr1);
    
    Sphere*	sphere_ptr2 = new Sphere(Point3D(45, -7, -60), 20);
    sphere_ptr2->set_color(dark_yellow);
    add_object(sphere_ptr2);
    
    Sphere*	sphere_ptr3 = new Sphere(Point3D(40, 43, -100), 17);
    sphere_ptr3->set_color(green);
    add_object(sphere_ptr3);
    
    Sphere*	sphere_ptr4 = new Sphere(Point3D(-20, 28, -15), 20);
    sphere_ptr4->set_color(dark_green);
    add_object(sphere_ptr4);
    
    Sphere*	sphere_ptr5 = new Sphere(Point3D(-25, -7, -35), 27);
    sphere_ptr5->set_color(red);
    add_object(sphere_ptr5);
    
    Sphere*	sphere_ptr6 = new Sphere(Point3D(20, -27, -35), 25);
    sphere_ptr6->set_color(brown);
    add_object(sphere_ptr6);
    
    Sphere*	sphere_ptr7 = new Sphere(Point3D(35, 18, -35), 22);
    sphere_ptr7->set_color(light_purple);
    add_object(sphere_ptr7);
    
    Sphere*	sphere_ptr8 = new Sphere(Point3D(-57, -17, -50), 15);
    sphere_ptr8->set_color(light_green);
    add_object(sphere_ptr8);
    
    Sphere*	sphere_ptr9 = new Sphere(Point3D(-47, 16, -80), 23);
    sphere_ptr9->set_color(dark_green);
    add_object(sphere_ptr9);
    
    Sphere*	sphere_ptr10 = new Sphere(Point3D(-15, -32, -60), 22);
    sphere_ptr10->set_color(dark_green);
    add_object(sphere_ptr10);
    
    Sphere*	sphere_ptr11 = new Sphere(Point3D(-35, -37, -80), 22);
    sphere_ptr11->set_color(dark_purple);
    add_object(sphere_ptr11);
    
    Sphere*	sphere_ptr12 = new Sphere(Point3D(10, 43, -80), 22);
    sphere_ptr12->set_color(dark_purple);
    add_object(sphere_ptr12);
    
    Sphere*	sphere_ptr13 = new Sphere(Point3D(30, -7, -80), 10);
    sphere_ptr13->set_color(blue);
    add_object(sphere_ptr13);
    
    Sphere*	sphere_ptr14 = new Sphere(Point3D(-40, 48, -110), 18);
    sphere_ptr14->set_color(light_green);
    add_object(sphere_ptr14);
    
    Sphere*	sphere_ptr15 = new Sphere(Point3D(-10, 53, -120), 18);
    sphere_ptr15->set_color(dark_green);
    add_object(sphere_ptr15);
    
    Sphere*	sphere_ptr16 = new Sphere(Point3D(-55, -52, -100), 10);
    sphere_ptr16->set_color(light_purple);
    add_object(sphere_ptr16);
    
    Sphere*	sphere_ptr17 = new Sphere(Point3D(5, -52, -100), 15);
    sphere_ptr17->set_color(light_blue);
    add_object(sphere_ptr17);
    
    Sphere*	sphere_ptr18 = new Sphere(Point3D(-20, -57, -120), 15);
    sphere_ptr18->set_color(dark_purple);
    add_object(sphere_ptr18);
    
    Sphere*	sphere_ptr19 = new Sphere(Point3D(55, -27, -100), 17);
    sphere_ptr19->set_color(light_green);
    add_object(sphere_ptr19);
    
    Sphere*	sphere_ptr20 = new Sphere(Point3D(50, -47, -120), 15);
    sphere_ptr20->set_color(dark_green);
    add_object(sphere_ptr20);
    
    Sphere*	sphere_ptr21 = new Sphere(Point3D(70, -42, -150), 10);
    sphere_ptr21->set_color(brown);
    add_object(sphere_ptr21);
    
    Sphere*	sphere_ptr22 = new Sphere(Point3D(5, 73, -130), 12);
    sphere_ptr22->set_color(light_purple);
    add_object(sphere_ptr22);
    
    Sphere*	sphere_ptr23 = new Sphere(Point3D(66, 21, -130), 13);
    sphere_ptr23->set_color(light_blue);
    add_object(sphere_ptr23);
    
    Sphere*	sphere_ptr24 = new Sphere(Point3D(72, -12, -140), 12);
    sphere_ptr24->set_color(light_purple);
    add_object(sphere_ptr24);
    
    Sphere*	sphere_ptr25 = new Sphere(Point3D(64, 5, -160), 11);
    sphere_ptr25->set_color(green);
    add_object(sphere_ptr25);
    
    Sphere*	sphere_ptr26 = new Sphere(Point3D(55, 38, -160), 12);
    sphere_ptr26->set_color(light_purple);
    add_object(sphere_ptr26);
    
    Sphere*	sphere_ptr27 = new Sphere(Point3D(-73, -2, -160), 12);
    sphere_ptr27->set_color(red);
    add_object(sphere_ptr27);
    
    Sphere*	sphere_ptr28 = new Sphere(Point3D(30, -62, -140), 15);
    sphere_ptr28->set_color(dark_purple);
    add_object(sphere_ptr28);
    
    Sphere*	sphere_ptr29 = new Sphere(Point3D(25, 63, -140), 15);
    sphere_ptr29->set_color(dark_purple);
    add_object(sphere_ptr29);
    
    Sphere*	sphere_ptr30 = new Sphere(Point3D(-60, 46, -140), 15);
    sphere_ptr30->set_color(dark_green);
    add_object(sphere_ptr30);
    
    Sphere*	sphere_ptr31 = new Sphere(Point3D(-30, 68, -130), 12);
    sphere_ptr31->set_color(green);
    add_object(sphere_ptr31);
    
    Sphere*	sphere_ptr32 = new Sphere(Point3D(58, 56, -180), 11);
    sphere_ptr32->set_color(blue);
    add_object(sphere_ptr32);
    
    Sphere*	sphere_ptr33 = new Sphere(Point3D(-63, -39, -180), 11);
    sphere_ptr33->set_color(yellow);
    add_object(sphere_ptr33);
    
    Sphere*	sphere_ptr34 = new Sphere(Point3D(46, 68, -200), 10); 	
    sphere_ptr34->set_color(light_purple);
    add_object(sphere_ptr34);
    
    Sphere*	sphere_ptr35 = new Sphere(Point3D(-3, -72, -130), 12); 
    sphere_ptr35->set_color(dark_purple);
    add_object(sphere_ptr35);
    
//    Sphere* sphere_ptr = new Sphere;
//    sphere_ptr->set_center(-50, -50, 0);
//    sphere_ptr->set_radius(80);
//    sphere_ptr->set_color(1, 0, 0);
//    add_object(sphere_ptr);
//    
//    sphere_ptr = new Sphere(Point3D(0, 50, 0), 20);
//    sphere_ptr->set_color(.8, 0, .8);
//    add_object(sphere_ptr);
//    
//    sphere_ptr = new Sphere(Point3D(50, 0, 0), 40);
//    sphere_ptr->set_color(0, .8, .8);
//    add_object(sphere_ptr);
//    
//    sphere_ptr = new Sphere(Point3D(50, 50, 0), 60);
//    sphere_ptr->set_color(.8, 0, 0);
//    add_object(sphere_ptr);
//    
//    sphere_ptr = new Sphere(Point3D(50, 50, 0), 35);
//    sphere_ptr->set_color(0, 1.0, 0);
//    add_object(sphere_ptr);
    
//    Plane* plane_ptr = new Plane(Point3D(0, -10, 0), Normal(0, .5, 1));
//    plane_ptr->set_color(0.0, 1.0, 1.0);
//    add_object(plane_ptr);
    //*/
    

    
    //SINGLE SPHERE
    /*
    int num_samples = 16;
    vp.set_hres(600);
    vp.set_vres(600);
    vp.set_samples(16);
    vp.set_pixel_size(1.0);
    vp.set_sampler(new Jittered(num_samples));
    vp.set_gamma(1.0);
    image = new ImageIO(vp.hres, vp.vres, 255);
    
    background_color = black;
    tracer_ptr = new SingleSphere(this);
    
    sphere.set_center(0.0);
    sphere.set_radius(85.0);
    */
}


ShadeRec World::hit_bare_bones_objects(const Ray &ray) {
    
    //World* w = *this;
    ShadeRec sr(*this);
    double t;
    double tmin = kHugeValue;
    int num_objects = (int)objects.size();
    
    for (int j = 0; j < num_objects; j++) {
        if (objects[j]->hit(ray, t, sr) && (t < tmin)){
            sr.hit_an_object = true;
            tmin = t;
            sr.color = objects[j]->get_color();
        }
    }
    
    return (sr);
        
}


void World::render_scene(void) const {
    RGB pixel_color;
    Ray ray;
    float zw = 100.0;
    //int n = (int)sqrt((float)vp.num_samples);
    Point3D pp;
    Point3D sp;
    
    
    ray.d = Vector3D(0,0,-1);
    
    for (int r = 0; r < vp.vres; r++){
        for (int c = 0; c < vp.hres; c++) {
        pixel_color = black;
            
            for(int j = 0; j < vp.num_samples; j++){
                sp = vp.sampler_ptr->sample_unit_square();
                pp.x = vp.s * (c - 0.5 * vp.hres + sp.x);
                pp.y = vp.s * (r - 0.5 * vp.vres + sp.y);
                ray.o = Point3D(pp.x, pp.y, zw);
                pixel_color += tracer_ptr->trace_ray(ray);
            }

            pixel_color /= vp.num_samples;
            display_pixel(r, c, pixel_color);
        }
    }
}



void
World::display_pixel(const int row, const int column, const RGB& pixel_color) const {
    RGB color = pixel_color;
    
//    if (vp.show_out_of_gamut)
//        mapped_color = clamp_to_color(raw_color);
//    else
//        mapped_color = max_to_one(raw_color);
//    
    if (vp.gamma != 1.0)
        color = color.powc(vp.inv_gamma);
    
    int y = column;
    int x = vp.vres - row - 1;
    
    
    
    image->set_pixel(x, y, color.r, color.g, color.b);
}



ImageIO* World::return_image(void) {
    
    return (image);
}


