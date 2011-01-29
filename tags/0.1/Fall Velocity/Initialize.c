/*
 *  Initialize.c
 *  Fall Velocity
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int ReadIn(double []);

int Initialize(double data[], double *viscosity, double *spec_grav, double *grain_size, double *grav) {
    
    //Reads in data
    ReadIn(data);
            
    //Renames variables
    *viscosity = data[0];
    *spec_grav = data[1];
    *grain_size = data[2];
    *grav = data[3];
    
    return 0;
}