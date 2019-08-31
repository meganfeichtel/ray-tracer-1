//
//  Filter.h
//  Resolution
//
//  Created by Tabitha Peck on 8/7/13.
//  Copyright (c) 2013 Tabitha Peck. All rights reserved.
//

#ifndef __Resolution__Filter__
#define __Resolution__Filter__

#include <iostream>
#include <math.h>

enum{BOX, TENT, GAUSSIAN};
#define PI 3.14159265359
#define E  2.71828182845
class Filter{
    
public:
    Filter(int type, int height);
    ~Filter();
    int getSize();
    int getWidth();
    float getValue(int x);
    float getValueOneD(int x);
    void print1D(float* oneD_filter);
    
    
private:
    float* filter;
    int filter_width; // width in pixels
    int filter_size; // size of filter in pixels (2 * filter_width +1)
    
    
    void makeBoxFilter( void );
    void makeTentFilter( void );
    void makeGaussianFilter( void );
    void makeFilter( float* oneD_filter );
    void normalize(float* oneD_filter );
    
};


#endif /* defined(__Resolution__Filter__) */
