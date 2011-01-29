/*
 *  Run.c
 *  BedrockAlluvialTransition
 *
 *  Created by Andrew Leman on 7/15/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindLoad(double [], double [], double [], double [], double, double, double,
    double, double, double, double, double, double, int);
int FindNewEta(double [], double [], double [], double [], double [], double, double,
    double, double, double, double *, double *, double, int);

int Run(double eta[], double S[], double qb[], double H[], double xbar[], double x[], double dxbar,
    double sd, double *etaup, double *sba, double Cz, double I, double lamdap,
    double Sbase, double dt, double alphas, double qw, double R, double D, double qtf, int M) {

    FindLoad(eta, S, qb, H, qtf, dxbar, sd, *sba, Cz, alphas, qw, R, D, M);
    FindNewEta(eta, S, qb, xbar, x, I, lamdap, Sbase, dt, sd, &(*sba), &(*etaup), dxbar, M);
    
    return 0;
}