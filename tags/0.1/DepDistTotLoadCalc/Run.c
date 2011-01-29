/*
 *  Run.c
 *  DepDistTotLoadCalc
 *
 *  Created by Andrew Leman on 7/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindValues(int, double [], double [], double [], double [], double [], double [],
    double [], double [], double [], double [], double [], double, double, double,
    double, double, double, double, double, double []);
int ValuesandIntegration(int, double [], double [], double [], double [], double [],
    double [], double [], double [], double [], double [], double [], double [],
    double [], double [], double, double, double, double);

int Run(int N, double Hs[], double U[], double Gamma[], double H[], double tausg[],
    double qw[], double ratio[], double Fr[], double u[], double us[], double qb[],
    double Hso, double Hstep, double Sl, double R, double D50s, double D90s, double astrat,
    double nk, double nu, double tau[], double Cz[], double kc[], double Zu[], double E[],
    double I[], double qs[], double qt[], double qbqt[], double vsku[]) {

    FindValues(N, Hs, U, Gamma, H, tausg, qw, ratio, Fr, u, us, qb, Hso, Hstep, Sl,
        R, D50s, D90s, astrat, nk, tau);
    ValuesandIntegration(N, Cz, U, u, kc, H, Zu, us, E, I, qs, qt, qbqt, vsku, qb,
        D50s, R, nu, Sl);
    return 0;
}