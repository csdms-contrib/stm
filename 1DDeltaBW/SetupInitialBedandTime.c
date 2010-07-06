/*
 *  SetupInitialBedandTime.c
 *  1DDeltaBW
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetupInitialBedandTime.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SetupInitialBedandTime(double xfbar[], double xfluv[], double etafluv[], double x[],
    double eta[], double *sss, double *sbb, double *etatop, double *etabot, double *etasdot,
    double *abase, double *Volinit, double dxbar, double ssfi, double Sa, double Sb,
    double lamdap, double etasl, double etabl, double Sfi, int M) {

    double etabase=0, etad[102], sbi=0;
    int i=0;
    
    for (i=1; i <= (M+1); i++) {
        xfbar[i] = dxbar*(i-1);
        xfluv[i] = ssfi*xfbar[i];
        etafluv[i] = etasl + ssfi*Sfi - ssfi*Sfi*xfbar[i];
        x[i] = xfluv[i];
        eta[i] = etafluv[i]; 
    }
    sbi = ssfi + (etasl - etabl)/Sa;
    x[M+2] = sbi;
    eta[M+2] = etabl;
    *sss = ssfi;
    *sbb = sbi;
    *etatop = etasl;
    *etabot = etabl;
    *etasdot = 0;
    *abase = etabl + Sb*(ssfi + (etasl - etabl)/Sa);
    for (i=1; i <= (M+2); i++) {
        etabase = *abase - Sb*x[i];
        etad[i] = eta[i] - etabase;
    }
    *Volinit = 0.5*etad[1]*(x[2] - x[1]);
    for (i=1; i <= (M+1); i++) {
        *Volinit += 0.5*(etad[i] + etad[i+1])*(x[i+1] - x[i]);
    }
    *Volinit = (1.0 - lamdap)*(*Volinit + 0.5*etad[M+2]*(x[M+2] - x[M+1]));

    return 0;
}