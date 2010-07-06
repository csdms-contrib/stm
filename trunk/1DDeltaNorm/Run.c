/*
 *  Run.c
 *  1DDeltaNorm
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindSlopeDepthLoad(double [], double [], double [], double [], double [], double *,
    double *, double, double, double, double, double, double, double, double, double,
    double, double, double, double, double, double, double, double, int, int);
int FindNewEta(double [], double [], double [], double [], double *, double *, double *,
    double *, double *, double, double, double, double, double, double, double, double,
    double, int);

int Run(double Sl[], double eta[], double H[], double tau[], double qb[], double xfbar[],
    double x[], double etasl, double I, double lamdap, double *sbb, double *sss,
    double *etaup, double *etatop, double *etabot, double Sa, double Sb, double dxbar,
    double qw, double Cz, double ks, double alphar, double alphat, double tsc, double nt,
    double R, double D, double dt, double qtf, double su, int formulation, int M) {

    //Declarations
    double ssdot=0, sbdot=0;

    FindSlopeDepthLoad(Sl, eta, H, tau, qb, &ssdot, &sbdot, etasl, I, lamdap, *sbb,
        Sa, Sb, dxbar, *sss, qw, Cz, ks, alphar, alphat, tsc, nt, R, D, formulation, M);
    FindNewEta(qb, eta, xfbar, x, &(*sss), &(*sbb), &(*etaup), &(*etatop), &(*etabot),
        su, ssdot, sbdot, Sa, qtf, dxbar, dt, I, lamdap, M);

    return 0;
}