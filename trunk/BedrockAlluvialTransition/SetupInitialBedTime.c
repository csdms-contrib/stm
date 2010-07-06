/*
 *  SetupInitialBedTime.c
 *  BedrockAlluvialTransition
 *
 *  Created by Andrew Leman on 7/14/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetupInitialBedTime.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SetupInitialBedTime(double xbar[], double x[], double eta[], double sd, double Sfinit,
    double dxbar, double *etaup, double *sba, int M) {

    //Initialize
    int i=0;
    
    //Run
    *sba = 0;
    for (i=1; i <= (M+1); i++) {
        xbar[i] = dxbar*(i-1);
        x[i] = *sba + (sd - *sba)*xbar[i];
        eta[i] = (sd - *sba)*Sfinit - (sd - *sba)*Sfinit*xbar[i];
    }
    *etaup = (sd - *sba)*Sfinit;

    //Finalize
    return 0;
}