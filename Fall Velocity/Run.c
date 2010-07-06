/*
 *  Run.c
 *  Fall Velocity
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

double fall_velocity(double, double, double, double, double *, double *);

int Run(double *velocity, double *Rep, double *Rf, double viscosity, double spec_grav,
    double grain_size, double grav) {


    *velocity = fall_velocity(viscosity, spec_grav, grain_size, grav, &(*Rep), &(*Rf));

    return 0;
}