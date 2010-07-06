/*
 *  CheckConvergence.c
 *  SuspSedDensityStrat
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "CheckConvergence.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int CheckConvergence(int n, double un[], double cn[], double unold[], double cnold[], int *converges) {

    //Initialize
    int i=0, nintervals=50, nmax=200, bombed=0;
    double Error=0, Ep=0.001, ern=0, erc=0;
    
    //Run
    if (n > 0) {
        Error = 0;
        for (i=1; i <= (nintervals+1); i++) {
            ern = fabs(2*(un[i]-unold[i])/(un[i]+unold[i]));
            erc = fabs(2*(cn[i]-cnold[i])/(cn[i]+cnold[i]));
            if (ern > Error)
                Error = ern;
            if (erc > Error)
                Error = erc;
        }
        if (Error < Ep) {
            *converges = 1;
        }
        else if (n >= nmax) {
            bombed = 1;
        }
    }
    
    //Finalize
    return bombed;
}