/*
 *  SetupInitialBedandTime.c
 *  1DDeltaNorm
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetupInitialBedandTime.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SetupInitialBedandTime(double xfbar[], double x[], double eta[], double *su,
    double *sss, double *sbb, double *etaup, double *etatop, double *etabot,
    double *abase, double *Volinit, double Sb, double lamdap, double Sfi, double ssfi,
    double etasl, double etabl, double Sa, double dxbar, int M) {

    double etabase=0, etad[102];
    int i=0;
    
    *su = 0;
    *sss = ssfi;
    *sbb = *sss + (etasl - etabl)/Sa;
    for (i=1; i <= (M+1); i++) {
        xfbar[i] = dxbar*(i-1);
        x[i] = *su + (*sss - *su)*xfbar[i];
        eta[i] = (*sss - *su)*Sfi - (*sss - *su)*Sfi*xfbar[i] + etasl;
    }
    *etaup = (*sss - *su)*Sfi + etasl;
    *etatop = etasl;
    *etabot = etabl;
    eta[M+2] = *etabot;
    x[M+2] = *sbb;
    *abase = etabl + Sb*(ssfi + (etasl - etabl)/Sa);
    for (i=1; i <= (M+2); i++) {
        etabase = *abase - Sb*x[i];
        etad[i] = eta[i] - etabase;
    }
    *Volinit = 0.5*etad[1]*(x[2] - x[1]);
    for (i=1; i <= (M+1); i++) {
        *Volinit += 0.5*(etad[i] + etad[i+1])*(x[i+1] - x[i]);
    }
    *Volinit = (*Volinit + 0.5*etad[M+2]*(x[M+2] - x[M+1]))*(1.0 - lamdap);
    
    return 0;
}