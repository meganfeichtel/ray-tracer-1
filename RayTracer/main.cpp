//
//  main.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/12/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//


//for each pixel
//    – Cast a ray from the eye of the camera through the pixel, and find the first surface hit by
//    the ray.
//    – Determine the surface radiance at the surface intersection with a combination of local
//    and global models.
//    – To estimate the global component, cast rays from the surface point to possible incident
//    directions to determine how much light comes from each direction. This leads to a
//    recursive form for tracing paths of light backwards from the surface to the light sources.

#include <iostream>
#include <math.h>
#include "ImageIO.h"
#include "World.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif


float win_width = 512;
float win_height = 512;

ImageIO* current_image;

void init( void ){
    
    glClearColor(1.0, 0.0, 0.0, 0.0);
    
}

void idle( void ){
    
    glutPostRedisplay();
}

void drawImage( void ){
    
    if(current_image != NULL){
        
        glClear(GL_COLOR_BUFFER_BIT);
        glRasterPos2i(0, 0);
        
        
        glDrawPixels(current_image->getWidth(), current_image->getHeight(), GL_RGB, GL_FLOAT, current_image->getImageDisplayArray());
    }
    
}

void display( void )
{
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0, win_width, 0, win_height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    drawImage();
    
    glFlush();
}

void reshape( int w, int h )
{
    win_width = w;
    win_height = h;
    glViewport( 0, 0, win_width, win_height );
    
    glutPostRedisplay();
}

void keyboard( unsigned char key, int x, int y ) {
    switch(key) {
        case 27: // Escape key
            exit(0);
            break;
    }
}

int main(int argc, char * argv[])
{
    ImageIO* the_image;
    
    
    World w;
    w.build();
    w.render_scene();
    the_image = w.return_image();
    
    current_image = the_image;

    
    win_height = current_image->getHeight();
    win_width = current_image->getWidth();
    
    glutInit( &argc, argv );
    
    glutInitDisplayMode( GLUT_RGB );
    glutInitWindowSize( win_width, win_height );
    
    glutCreateWindow( "Image" );
    
    init();
    
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    glutKeyboardFunc( keyboard );
    glutIdleFunc( idle );
    
    
    glutMainLoop();
    
    
    delete current_image;
    
    return 0;
}

    //fprintf(stderr, "red:%f, green:%f, blue:%f\n", r, g, b);





