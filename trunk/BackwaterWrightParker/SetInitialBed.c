/*
 *  SetInitialBed.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetInitialBed.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SetInitialBed(double x[], double eta[], double ksi[], double dx, double S, double L, double ksid, int M) {

    //Declarations
    int i=0;

    //Run
    for (i=1; i <= (M+1); i++) {
        x[i] = dx*(i-1);
        eta[i] = S*L - S*x[i];
    }
    ksi[M+1] = ksid;

    //Finalize
    return 0;
}