/*
 *  Run.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ComputeBedloadTransportRate(double [], double [], double [], double, double, int);
int ComputeSuspendedSedimentTransportRate(double [], double [], double [], double [],
    double [], double [], double *, double *, double *, double, double, double,
    double, int);
int FindNewEta(double [], double [], double [], double *, double *, double *,
    double *, double, double, double, double, double, double, double, double, double,
    int);
int FluvialBackwater(double [], double [], double [], double [], double [], double,
    double, double, double, double, double, int);

int Run(double qb[], double Hs[], double Sf[], double qs[], double H[], double Ent[],
    double zeta[], double eta[], double ksi[], double *ustarr, double *Hr, double *qsint,
    double *MassIn, double *MassOut, double *MassStored, double *FracDisc, double D50,
    double R, double vs, double Rep, double qw, double dzeta, double qbf, double qsf,
    double au, double dt, double I, double lamdap, double dx, double B, double ksid,
    double D90, int M) {

    int check=0;

    ComputeBedloadTransportRate(qb, Hs, Sf, D50, R, M);
    ComputeSuspendedSedimentTransportRate(qs, Hs, Sf, H, Ent, zeta, &(*ustarr),
        &(*Hr), &(*qsint), vs, Rep, qw, dzeta, M);
    FindNewEta(eta, qb, qs, &(*MassIn), &(*MassOut), &(*MassStored), &(*FracDisc),
        qbf, qsf, au, dt, I, lamdap, dx, R, B, M);
    check = FluvialBackwater(H, Sf, Hs, eta, ksi, qw, D90, D50, R, dx, ksid, M);
    if (check == 1)
        return 1;

    return 0;
}