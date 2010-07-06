/*
 *  Run.c
 *  AgDegNormGravMixSubPW
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

int FindSlopesandShieldsStress(int, double [], double [], double [], double [], double [], double,
        double, double [], double [], double, double, double, double [], double, int);
int FindLoad(quad [], int, int, int, double [][21], double [][21], double [], double [],
        double [], double [], double [], double [], double [], double, double [], int,
        double [], double, double [][101], double);
int FindNewEta(quad [], int, int, int, double, double [], double [], double [], double [],
        double [], double [], double [][21], double [][21], double [], double, double,
        double, double, double, double, double, double, double [], double [], double [],
        double, double);

int Run(int M, double eta[], double Sl[], double tausg[], double taus50[], double H[],
    double dx, double nk, double Dx90s[], double Dx50s[], double qw, double alphar,
    double R, double dsgs[], quad GSD[], double np, double npp, double F[][21], double pl[][21],
    double qbT[], double ds[], double po[], double oo[], double so[], double Ft[], int bedloadrelation,
    double fracsand[], double qbTf, double qbTmatrix[][101], double time, double na, double Fs[],
    double plf[], double alphau, double atrans, double dt, double I, double lps, double Laold[],
    double subrate, double ExnerFactor, double Cf, int formulation) {

    FindSlopesandShieldsStress(M, eta, Sl, tausg, taus50, H, dx, nk, Dx90s,
               Dx50s, qw, alphar, R, dsgs, Cf, formulation);
    FindLoad(GSD, M, np, npp, F, pl, qbT, ds, tausg, dsgs, po, oo, so,
               R, Ft, bedloadrelation, fracsand, qbTf, qbTmatrix, time);
    FindNewEta(GSD, M, npp, np, na, Dx90s, Dx50s, qbT, Fs, Ft, plf,
               F, pl, eta, alphau, qbTf, dx, atrans, dt, I, lps, time,
               dsgs, fracsand, Laold, subrate, ExnerFactor);
    return 0;

}