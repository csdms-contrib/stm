/*
 *  FindSlopeandLoad.c
 *  1DRiverWFRisingBaseLevelNormal
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindSlopeandLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindSlopeandLoad(double Sl[], double eta[], double Qt[], double Bbf[], double Hbf[],
    double dx, double loadcoef, double widthcoef, double depthcoef, double D, double Qf,
    int M) {

    //Declarations
    int i=0;
    
    Sl[1] = (eta[1] - eta[2])/dx;
    Sl[M+1] = (eta[M] - eta[M+1])/dx;
    for (i=2; i <= M; i++) {
        Sl[i] = (eta[i-1] - eta[i+1])/(2.0*dx);
    }
    for (i=1; i <= (M+1); i++) {
        Qt[i] = loadcoef*Qf*Sl[i];
        Bbf[i] = widthcoef*Qt[i]/(D*sqrt(D*g));
        Hbf[i] = depthcoef*D*Qf/Qt[i];
    }
    return 0;
}