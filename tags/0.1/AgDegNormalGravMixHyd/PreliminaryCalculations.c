/*
 *  PreliminaryCalculations.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/26/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "PreliminaryCalculations.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81
#define timeyear 31557600.0
#define timeday 86400.0

typedef struct {
    double qw;
    double qbTf;
    int nstep;
} triple;

int PreliminaryCalculations(triple hydro[], int ndisc, int *totstep, double *qbToave,
        double *qwave, int beginstep[], double *durhyd, double *I, double *LoadAnn,
        double *dt, double dtflood, int ncyc, double R) {
    //Initialize
    int i=0;
    
    //Run
        //Calculation of beginstep and totstep
        beginstep[1] = 1;
        for (i=2; i <= ndisc; i++) {
            beginstep[i] = beginstep[i-1] + hydro[i-1].nstep;
        }
        beginstep[ndisc+1] = beginstep[ndisc] + hydro[ndisc].nstep;
        
        //Calculation of qbToave and qwave
        for (i=1; i <= ndisc; i++) {
            *qwave += (hydro[i].qw*hydro[i].nstep);
            *qbToave += (hydro[i].qbTf*hydro[i].nstep);
        }
        *qbToave = (*qbToave)/(*totstep);
        *qwave = (*qwave)/(*totstep);
        
        //Calculation of Intermittency and dt
        for (i=1; i <= ndisc; i++) {
            *durhyd += (hydro[i].nstep*dtflood);
        }
        *I = ncyc*(*durhyd)/365.25;
        *LoadAnn = (*qbToave)*(*I)*(R+1)*(timeyear)/1000000;
        *dt = dtflood/((*durhyd)*(ncyc*1.0)/365.25);
        *dt = (*dt)*timeday;
    
    //Finalize
    return 0;
}