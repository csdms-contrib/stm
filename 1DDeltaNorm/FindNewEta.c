/*
 *  FindNewEta.c
 *  1DDeltaNorm
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewEta.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindNewEta(double qb[], double eta[], double xfbar[], double x[], double *sss,
    double *sbb, double *etaup, double *etatop, double *etabot, double su, double ssdot,
    double sbdot, double Sa, double qtf, double dxbar, double dt, double I,
    double lamdap, int M) {

    //Declarations
    int i=0;
    double qtdev[102], etadev[102];

    for (i=1; i <= M; i++) {
        if (i == 1) {
            qtdev[i] = (qb[i+1] - qtf)/(2*dxbar);
            etadev[i] = (eta[i+1] - eta[i])/(dxbar);
        }
        else {
            qtdev[i] = (qb[i+1] - qb[i-1])/(2*dxbar);
            etadev[i] = (eta[i+1] - eta[i-1])/(2*dxbar);
        }
    }
    for (i=1; i <= M; i++) {
        eta[i] += dt*(-I*qtdev[i]/(*sss*(1.0-lamdap)));
        eta[i] += xfbar[i]*ssdot*etadev[i]*dt/(*sss);
    }
    *sss += ssdot*dt;
    *sbb += sbdot*dt;
    *etaup = eta[1];
    *etatop = eta[M+1];
    *etabot = *etatop - Sa*(*sbb - *sss);
    eta[M+2] = *etabot;
    x[M+2] = *sbb;
    for (i=1; i <= (M+1); i++) {
        x[i] = su + (*sss-su)*xfbar[i];
    }
    
    return 0;
}