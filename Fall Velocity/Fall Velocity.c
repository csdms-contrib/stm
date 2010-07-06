/*
 *  Fall Velocity.c
 *  Fall Velocity
 *
 *  Created by Andrew Leman on 5/26/09.
 *  Copyright 2009 University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Fall Velocity.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fall_velocity(double nu, double R, double D, double grav, double *Rep, double *Rf) {

//Initialize
double x=0, y=0;
double velocity;

//Run
*Rep = sqrt(grav*R*(D/1000))*(D/1000)/nu;
x = log10(pow(*Rep, 2));
y = (-3.76715) + (1.92944*x) - (0.09815*x*x) - (0.00575*x*x*x) + (0.00056*x*x*x*x);
*Rf = cbrt((pow(10, y))/(*Rep));
velocity = *Rf*100*sqrt(R*grav*D/1000);

//Finalize
return velocity;
}