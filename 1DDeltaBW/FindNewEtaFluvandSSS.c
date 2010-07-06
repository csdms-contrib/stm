/*
 *  FindNewEtaFluvandSSS.c
 *  1DDeltaBW
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewEtaFluvandSSS.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindNewEtaFluvandSSS(double qb[], double etafluv[], double x[], double eta[],
    double xfluv[], double xfbar[], double *sss, double *etasdot, double *ssdot,
    double *etatop, double Sa, double dt, double I, double lamdap, double qtf,
    double dxbar, int M) {

    int i=0;
    double qtdev=0, etadev=0, etatopold=0;
    
    etatopold = *etatop;
    for (i=1; i <= (M+1); i++) {
        if (i == 1) {
            qtdev = (qb[i] - qtf)/dxbar;
            etadev = (etafluv[i+1] - etafluv[i])/dxbar;
        }
        else if (i == (M+1)) {
            qtdev = (qb[i] - qb[i-1])/dxbar;
            etadev = (etafluv[i] - etafluv[i-1])/dxbar;
        }
        else {
            qtdev = (qb[i] - qb[i-1])/dxbar;
            etadev = (etafluv[i+1] - etafluv[i-1])/(2*dxbar);
        }
        etafluv[i] += dt*(-I*qtdev/(*sss*(1.0-lamdap)) + xfbar[i]*(*ssdot)*etadev/(*sss));
        eta[i] = etafluv[i];
    }
    *etatop = etafluv[M+1];
    *etasdot = (*etatop - etatopold)/dt;
    *ssdot += -(*etasdot)/Sa;
    *sss += *ssdot*dt;
    for (i=1; i <= (M+1); i++) {
        xfluv[i] = xfbar[i]*(*sss);
        x[i] = xfluv[i];
    }

    return 0;
}