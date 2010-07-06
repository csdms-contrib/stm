/*
 *  Fall Velocity.c
 *  SuspSedDensityStrat
 *
 *  Created by Andrew Leman on 7/6/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Fall Velocity.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double FallVelocity(double Rep, double R, double D) {

    //Initialize
    double x=0, y=0, z=0, vs=0;
    
    //Run
    x = log10(pow(Rep, 2));
    y = -3.76715+1.92944*x-0.09815*pow(x, 2)-0.00575*pow(x, 3)+0.00056*pow(x, 4);
    z = cbrt(pow(10, y)/(Rep));
    vs = z*sqrt((R-1)*981*(D/10.0));

    //Finalize
    return vs;
}