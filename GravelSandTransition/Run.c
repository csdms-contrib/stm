/*
 *  Run.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FluvialBackwater(double [], double [], double [], double, double, double,
    double, double, int, int);
int FindSlopes(double [], double [], double [], double [], double [], double *,
    double *, double *, double *, int, int);
int FindLoad(double [], double [], double [], double [], double [], double *,
    double *, double, double, double, double, double, double, double, double,
    double, double, int, int);
int FindMovingBoundSpeed(double [], double [], double *, double, double, double,
    double, double, double, double, double, double, double, double, int);
int FindNewEta(double [], double [], double [], double [], double [], double [],
    double *, double, double, double, double, double, double, double, double,
    double, double, double, double, double, double, double *, double, double, int,
    int);

int Run(double Slmatrix[][203], double Hmatrix[][202], double qbmatrix[][202], double taumatrix[][202],
    double H[], double eta[], double x[], double Sgrav[], double Ssand[], double Sl[],
    double qb[], double qgrav[], double qsand[], double tau[], double xbarg[], double xbars[],
    double *Sbgb, double *Sggs, double *Ssgs, double *Ssd, double *qgravghost, double *qsandghost,
    double *sgsdot, double *sgs, double *ksid, double Cfs, double Cfg, double qws, double qwg,
    double R, double Dg, double Ds, double qfs, double qfg, double lamdasg, double Ifseff,
    double Ifgeff, double L, double dxbarg, double dxbars, double lamps, double lampg,
    double Yearstart, double Yearstop, double subrate, double dt, double ksidot, double time,
    int Ms, int Mg) {
    
    //Declaration
    int i=0;

    //Functions
    FluvialBackwater(H, eta, x, *ksid, Cfs, Cfg, qws, qwg, Ms, Mg);
    FindSlopes(Sgrav, Ssand, eta, Sl, x, &(*Sbgb), &(*Sggs), &(*Ssgs), &(*Ssd), Mg, Ms);
    FindLoad(qb, qgrav, qsand, tau, H, &(*qgravghost), &(*qsandghost), Cfg, Cfs,
        qwg, qws, R, Dg, Ds, qfs, qfg, lamdasg, Mg, Ms);
    FindMovingBoundSpeed(qsand, qgrav, &(*sgsdot), Ifseff, Ifgeff, *Sggs, *Ssgs,
        *qsandghost, L, *sgs, dxbars, dxbarg, lamps, lampg, Mg);
    //Assigns values to initial Sl, qb, and H
    if (time == 0) {
        for (i=1; i <= (Ms+Mg+1); i++) {
            Slmatrix[0][i] = Sl[i];
            qbmatrix[0][i] = qb[i];
            Hmatrix[0][i] = H[i];
            taumatrix[0][i] = tau[i];
        }
        Slmatrix[0][Ms+Mg+2]=Sl[Ms+Mg+2];
        Slmatrix[0][0] = time;
        qbmatrix[0][0] = time;
        Hmatrix[0][0] = time;
        taumatrix[0][0] = time;
    }
    FindNewEta(qgrav, qsand, eta, x, xbarg, xbars, &(*sgs), Yearstart, Yearstop,
        dxbarg, dxbars, L, *qgravghost, *qsandghost, subrate, dt, *sgsdot, Ifgeff,
        Ifseff, lampg, lamps, &(*ksid), ksidot, time, Ms, Mg);

    return 0;
}