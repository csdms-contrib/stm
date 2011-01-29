/*
 *  DischargesforPrint.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/26/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "DischargesforPrint.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double qw;
    double qbTf;
    int nstep;
} triple;

int DischargesforPrint(triple hydro[], int ndisc, double dtflood, int beginstep[],
        double qwforprint[], double qbToforprint[], double dayforprint[]) {
    //Initialize
    int i=0, j=0;
    
    //Run
    for (i=1; i <= ndisc; i++) {
        for (j=beginstep[i]; j <= (beginstep[i+1]-1); j++) {
            qwforprint[j] = hydro[i].qw;
            qbToforprint[j] = hydro[i].qbTf;
            dayforprint[j] = (j - 1)*dtflood;
        }
    }
    
    //Finalize
    return 0;
}