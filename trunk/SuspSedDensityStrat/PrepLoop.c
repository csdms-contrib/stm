/*
 *  PrepLoop.c
 *  SuspSedDensityStrat
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "PrepLoop.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int PrepLoop(double zeta[], double Ri[], double Fstrat[], double un[], double cn[],
    double intc[], double unr, int *n, double *dzeta) {

    //Initialize
    int nintervals=50, i=0;
    double zetar=0.05;
    
    //Run
    *dzeta = (1 - zetar)/nintervals;
    for (i=1; i<= (nintervals+1); i++) {
        zeta[i] = zetar + (*dzeta)*(i-1);
        Ri[i] = 0;
        Fstrat[i] = 1;
    }
    un[1] = unr;
    cn[1] = 1;
    intc[1] = 0;
    *n = 0;
    
    //Finalize
    return 0;
}