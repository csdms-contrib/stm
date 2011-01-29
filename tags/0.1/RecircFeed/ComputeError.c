/*
 *  ComputeError.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ComputeError.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ComputeError(double Sl[], double etadhat[], double dxhat, int *equilibriates, int Nreach) {

    //Initialize
    double err=0, err2=0, epslope=0.01;
    int i=0;
    
    //Run
    for (i=2; i <= Nreach; i++) {
        Sl[i] = (etadhat[i-1] - etadhat[i])/dxhat;
    }
    for (i=2; i <= Nreach; i++) {
        err = 2*fabs((Sl[i]-1)/(Sl[i]+1));
        if (err > err2)
            err2 = err;
    }
    if (err2 <= epslope) {
        *equilibriates = 1;
    }

    //Finalize
    return 0;
}