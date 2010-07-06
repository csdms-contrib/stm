/*
 *  Rf.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Rf.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

double Rf(double Rep) {

    double xx=0, yy=0, Rf=0;
    
    xx = log(Rep*Rep)/log(10);
    yy = -3.76715 + 1.92944*xx - 0.09815*(xx*xx) - 0.00575*pow(xx, 3) + 0.00056*pow(xx, 4);
    Rf = cbrt(pow(10, yy)/Rep);

    return Rf;
}