//
//  RGB.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/11/14.
//
//

#include <math.h>
#include "RGB.h"


RGB::RGB(void)
    :    r(0.0), g(0.0), b(0.0)
{}

RGB::RGB(float c)
:    r(c), g(c), b(c)
{}

RGB::RGB(float _r, float _g, float _b)
    :    r(_r), g(_g), b(_b)
{}


RGB::RGB(const RGB& c)
    :    r(c.r), g(c.g), b(c.b)
{}

RGB::~RGB(void){
    
}

bool RGB::equals(const RGB& c){
    return (r == c.r && g == c.g && b == c.b);
}


RGB& RGB::operator= (const RGB& rhs) {
    if (this == &rhs)
        return (*this);
    
    r = rhs.r; g = rhs.g; b = rhs.b;
    
    return (*this);
}

RGB RGB::operator+ (const RGB& c){
    return (RGB(r+c.r, g + c.g, b + c.b));
}

RGB& RGB::operator+= (const RGB& c){
    r+=c.r, g += c.g, b += c.b;
    return (*this);
}

RGB RGB::operator- (const RGB& c){
    return (RGB(r - c.r, g - c.g, b - c.b));
}


RGB RGB::operator* (const float c){
    return (RGB(r*c, g*c, b*c));
}

RGB RGB::operator* (const RGB& c){
    return (RGB(r*c.r, g*c.g, b*c.b));
}


RGB& RGB::operator*= (const float c) {
    r *=c; g *= c; b *= c;
    return (*this);
}

RGB RGB::operator/ (const float c) {
    return (RGB(r/c, g/c, b/c));
}

RGB& RGB::operator/= (const float c) {
    r /=c; g /= c; b /= c;
    return (*this);
}

//RGB RGB::operator* (const float c, const RGB& temp){
//    return (RGB(c* temp.r, c* temp.g, c* temp.b));
//}

//avg of three comps?


RGB RGB::powc(float p) const {
    return (RGB(pow(r, p), pow(g, p), pow(b, p)));
}



