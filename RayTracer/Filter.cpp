//
//  Filter.cpp
//  Resolution
//
//  Created by Tabitha Peck on 8/7/13.
//  Copyright (c) 2013 Tabitha Peck. All rights reserved.
//

#include "Filter.h"


Filter::Filter(int type, int width){
    filter_width = width;
    filter_size = 2 * filter_width + 1;
    
    switch(type){
        case(BOX):
            makeBoxFilter(); break;
        case(TENT):
            makeTentFilter(); break;
        case(GAUSSIAN):
            makeGaussianFilter(); break;
        default:
            printf("Incorrect filter type");
            exit(1);
            break;
    }
    
    
}

Filter::~Filter(){
    delete [] filter;
}

void Filter::makeBoxFilter(){
    
    float height = 1 / (1.0*(filter_size));
    
    filter = new float[filter_size];
    
    for(int i = 0; i < filter_size; i++){
        filter[i] = height;
    }
    print1D(filter);
}


void Filter::makeTentFilter(){
    
    filter = new float[filter_size];
    float foo = 1/(1.0 * filter_width);
    
    for(int i = filter_width; i > 0 ; i--){
        filter[filter_width - i] = 1 - (i*foo);
        filter[filter_size - (filter_width - i) - 1] = 1 - (i*foo);
    }
    filter[filter_width] = 1;
    
    normalize(filter);
    print1D(filter);
}

void Filter::makeGaussianFilter(){
    filter = new float[filter_size];
    
    //float step_size = 1/(float)filter_width;
    float sigma = (filter_width-1)/3.0; //filter_width * filter_width;
    float foo = 1/(sqrt(2*PI)*sigma);
    for(int i = filter_width; i >= 0 ; i--){
        //float x = (float)(filter_width - i) * step_size;
        float x = i;
        float bar = foo * pow(E, -(x * x) / (2*sigma*sigma));
        filter[filter_width - i] = bar;
        filter[filter_size - (filter_width - i) - 1] = bar;
    }
    
    
    normalize(filter);
    print1D(filter);
    
    
}

int Filter::getSize(){ // total width of filter
    return filter_size;
}

int Filter::getWidth(){ // half width of filter
    return filter_width;
}

float Filter::getValue(int x){
    return filter[x];
}

/*
 void Filter::makeFilter(float* oneD_filter){
 filter = new float*[filter_size];
 for(int i = 0; i < filter_size; i++){
 filter[i] = new float[filter_size];
 for(int j = 0; j < filter_size; j++){
 filter[i][j] = oneD_filter[i] * oneD_filter[j];
 }
 }
 }*/

void Filter::normalize(float* oneD_filter){
    float foo = 0.0;
    
    for(int i = 0; i < filter_size; i++){
        foo += oneD_filter[i];
    }
    foo = 1 / foo;
    
    for(int i = 0; i < filter_size; i++){
        oneD_filter[i] = oneD_filter[i] * foo;
    }
}

void Filter::print1D(float* oneD_filter){
    for(int i = 0; i < filter_size; i++){
        printf("%f ", oneD_filter[i]);
    }
    printf("\n\n");
    
}
/*
 void Filter::printFilter(){
 for(int i = 0; i < filter_size; i++){
 for (int j = 0; j < filter_size; j++){
 printf("%f ", filter[i][j]);
 }
 printf("\n");
 }
 
 printf("\n");
 }*/







