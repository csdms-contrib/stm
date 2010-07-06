/*
 *  FindSlopeLoad.c
 *  SubsidingFan
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindSlopeLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindSlopeLoad(double Sl[], double qb[], double eta[], double dx, double loadcoef, double Qbf, int M) {

    int i=0;
    
    Sl[2] = (eta[2] - eta[3])/dx;
    for (i=3; i <= M; i++) {
        Sl[i] = (eta[i-1] - eta[i+1])/(2*dx);
    }
    for (i=2; i <= (M+1); i++) {
        qb[i] = loadcoef*Qbf*Sl[i];
    }
    
    return 0;
}