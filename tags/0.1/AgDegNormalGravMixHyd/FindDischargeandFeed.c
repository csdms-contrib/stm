/*
 *  FindDischargeandFeed.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindDischargeandFeed.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

typedef struct {
    double qw;
    double qbTf;
    int nstep;
} triple;

int FindDischargeandFeed(triple hydro[], double *qw, double *qbTo, int beginstep[], int kflow, int ndisc) {
    //Initialize
    int k=0;
    
    //Run
    for (k=1; k <= ndisc; k++) {
        if ((kflow >= beginstep[k]) && (kflow < beginstep[k+1])) {
            *qw = hydro[k].qw;
            *qbTo = hydro[k].qbTf;
        }
    }
    
    //Finalize
    return 0;
}