/*
 *  RouseVanoni.c
 *  Rouse-Vanoni Equilibrium
 *
 *  Created by Andrew Leman on 5/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "RouseVanoni.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int RouseVanoni(double bH, double vs, double u, double zH[], double cb[]) {
    //Initialize
    float kappa = 0.4;
    double power=0.0;
    int i=1;
    
    //Run
    zH[0]=bH;
    cb[0]=1;
    while(zH[i] < .95) {
        zH[i] = zH[i-1]+((1-bH)/19.0);
        if (zH[i] >= .98) {
            break; }
        power = ((1-zH[i])/(zH[i]))/((1-bH)/(bH));
        cb[i] = pow(power, vs/(100*kappa*u));
        i++;
    }
    zH[i] = 0.98;
    power = ((1-zH[i])/(zH[i]))/((1-bH)/(bH));
    cb[i] = pow(power, vs/(100*kappa*u));
    zH[i+1] = 0.995;
    power = ((1-zH[i+1])/(zH[i+1]))/((1-bH)/(bH));
    cb[i+1] = pow(power, vs/(100*kappa*u));
    zH[i+2] = 1.0;
    power = ((1-zH[i+2])/(zH[i+2]))/((1-bH)/(bH));
    cb[i+2] = pow(power, vs/(100*kappa*u));
    
    //Finalize
    return i+3;
}