//
//  Constants.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/24/14.
//  Copyright (c) 2014 Megan Feichtel. All rights reserved.
//

#ifndef RayTracer_Constants_h
#define RayTracer_Constants_h


#include "RGB.h"

const double 	PI 			= 3.1415926535897932384;
const double 	TWO_PI 		= 6.2831853071795864769;
const double 	PI_ON_180 	= 0.0174532925199432957;
const double 	invPI 		= 0.3183098861837906715;
const double 	invTWO_PI 	= 0.1591549430918953358;

const double 	kEpsilon 	= 0.0001;
const double	kHugeValue	= 1.0E10;

const RGB black(0.0);
const RGB white(1.0);
const RGB red(1.0, 0.0, 0.0);


//need #include <stdlib.h>	for this
//const float 	invRAND_MAX = 1.0 / (float)RAND_MAX;

#endif
