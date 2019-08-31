//
//  RGB.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/11/14.
//
//

#ifndef __RayTracer__RGB__
#define __RayTracer__RGB__

#include <stdio.h>



class RGB {
public:
    float r, g, b;
    
    RGB(void);
    RGB(float c);
    RGB(float _r, float _g, float _b);
    RGB(const RGB& c);
    ~RGB(void);
    
    bool equals(const RGB& c);
    RGB& operator= (const RGB& rhs);
    
    RGB operator+ (const RGB& c);
    RGB& operator+= (const RGB& c);
    RGB operator- (const RGB& c);
    RGB operator* (const float c);
    RGB operator* (const RGB& c);
    RGB& operator*= (const float c);
    RGB operator/ (const float c);
    RGB& operator/= (const float c);
    
    RGB powc(float p) const;
    //RGB operator* (const float c, const RGB& temp);
  
};



#endif /* defined(__RayTracer__RGB__) */
