/*
 *  GGwc.c
 *  AgDegNormGravMixPW
 *
 *  Created by Andrew Leman on 6/25/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "GGwc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

double GGwc(double phi) {
    //Initialize
    double G=0;
    
    //Run
    if (phi < 1.35) {
        G = 0.002*pow(phi, 7.5);
    }
    else {
        G = 14*pow((1-(0.894/sqrt(phi))), 4.5);
    }
    
    //Finalize
    return G;
}