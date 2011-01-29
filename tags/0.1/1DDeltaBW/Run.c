/*
 *  Run.c
 *  1DDeltaBW
 *
 *  Created by Andrew Leman on 7/17/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FluvialBackwater(double [], double [], double, double, double, double, double,
    double, double, double, int, int);
int FindLoadssdot(double [], double [], double [], double *, double, double, double,
    double, double, double, double, double, double, double, double, double, double,
    double, int, int);
int FindNewEtaFluvandSSS(double [], double [], double [], double [], double [],
    double [], double *, double *, double *, double *, double, double, double,
    double, double, double, int);
int FindNewSbb(double [], double [], double *, double *, double *, double, double,
    double, double, double, double, double, int *, int);

int Run(double Hfluv[], double etafluv[], double tau[], double qb[], double x[],
    double eta[], double xfluv[], double xfbar[], double Cz, double dxbar, double Hn,
    double qw, double R, double D, double tsc, double alphat, double nt, double dt,
    double qtf, double I, double Sa, double Sb, double lamdap, double ksid, double sfmax,
    double time, double ks, double alphar, double *etasdot, double *etatop, double *ssdot,
    double *sbb, double *sss, double *sbdot, double *etabot, int *bombed, int M,
    int formulation) {

    FluvialBackwater(Hfluv, etafluv, Cz, *sss, dxbar, Hn, qw, ksid, ks, alphar,
        M, formulation);
    FindLoadssdot(tau, qb, Hfluv, &(*ssdot), R, D, tsc, alphat, nt, I, Sa, lamdap,
        *sbb, *sss, Cz, qw, alphar, ks, M, formulation);
    FindNewEtaFluvandSSS(qb, etafluv, x, eta, xfluv, xfbar, &(*sss), &(*etasdot),
        &(*ssdot), &(*etatop), Sa, dt, I, lamdap, qtf, dxbar, M);
    FindNewSbb(x, eta, &(*sbdot), &(*sbb), &(*etabot), sfmax, time, *ssdot,
        *etasdot, Sa, Sb, dt, &(*bombed), M);

    return 0;
}