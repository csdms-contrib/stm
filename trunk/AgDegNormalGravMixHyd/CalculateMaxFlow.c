/*
 *  CalculateMaxFlow.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/26/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "CalculateMaxFlow.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double qw;
    double qbTf;
    int nstep;
} triple;

int CalculateMaxFlow(triple hydro[], int ndisc, int *maxflow, int beginstep[]) {
    //Initialize
    int i=0, maxi=0;
    double qwmax=0;
    
    //Run
    for(i=1; i <= ndisc; i++) {
        if (hydro[i].qw >= (qwmax)) {
            qwmax = hydro[i].qw;
            maxi = i;
        }
    }
    *maxflow = beginstep[maxi] + hydro[maxi].nstep - 1;
    
    //Finalize
    return 0;
}