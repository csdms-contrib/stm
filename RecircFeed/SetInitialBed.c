/*
 *  SetInitialBed.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetInitialBed.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SetInitialBed(double xhat[], double etadhat[], double *etatila, double *SNup,
    double *SNdown, double etatilainit, double dxhat, double SNl, int Nreach) {

    //Initialize
    int i=0;
    
    //Run
    *etatila = etatilainit;
    for (i=1; i <= Nreach; i++) {
        xhat[i] = dxhat*(i-1);
        etadhat[i] = SNl*(0.5 - xhat[i]);
    }
    *SNup = (etadhat[1] - etadhat[2])/dxhat;
    *SNdown = (etadhat[Nreach - 1] - etadhat[Nreach])/dxhat;

    //Finalize
    return 0;
}