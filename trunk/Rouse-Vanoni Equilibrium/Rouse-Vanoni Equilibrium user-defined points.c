/*
 *  Rouse-Vanoni Equilibrium user-defined points.c
 *  Rouse-Vanoni Equilibrium
 *
 *  Created by Andrew Leman on 5/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Rouse-Vanoni Equilibrium user-defined points.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int RouseVanoniuserdefined(double bH, double vs, double u, double zH[], double cb[]) {
    //Initialize
    float kappa = 0.4;
    double power=0, n=0;
    int i=1;
    
    //Run
    printf("How many iterations would you like to do? \n");
    scanf("%lf", &n);
    zH[0]=bH;
    cb[0]=1;
    for(i=1; i<= (n-2); i++) {
        zH[i] = zH[i-1]+((1-bH)/(n));
        power = ((1.0-zH[i])/(zH[i]))/((1.0-bH)/(bH));
        cb[i] = pow(power, (vs/(100*kappa*u)));
    }
    i = n-1;
    zH[i] = 1.0;
    cb[i] = 0.0;

    //Finalize
    return n;
}
