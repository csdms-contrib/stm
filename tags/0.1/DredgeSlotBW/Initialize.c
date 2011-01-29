/*
 *  Initialize.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int ReadIn(double [], double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, int *, int *, int *);
int ComputeNormalFlow(double [], double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double, double,
    double, double, double, double, double, double, double, double);
int SetInitialBed(double [], double [], double [], double *, double *, double *,
    double *, double, double, double, double, double, double, double, int);
int FluvialBackwater(double [], double [], double [], double [], double [], double,
    double, double, double, double, double, int);

int Initialize(double zeta[], double x[], double eta[], double ksi[], double H[],
    double Sf[], double Hs[], double *Qww, double *I, double *B, double *D50, double *D90,
    double *R, double *S, double *lamdap, double *L, double *Hslot, double *ru,
    double *rd, double *au, double *dt, double *qw, double *dx, double *Rep, double *vs,
    double *dzeta, double *Hnorm, double *Hsnorm, double *Gbnorm, double *Gsnorm,
    double *ustarr, double *Hr, double *qsint, double *ksid, double *qbf, double *qsf,
    double *Cnorm, double *MassIn, double *MassStored, double *MassOut, double *FracDisc,
    int *M, int *iterates, int *prints) {

    int check=0;
    
    check = ReadIn(zeta, &(*Qww), &(*I), &(*B), &(*D50), &(*D90), &(*R), &(*S),
                &(*lamdap), &(*L), &(*Hslot), &(*ru), &(*rd), &(*au), &(*dt),
                &(*qw), &(*dx), &(*Rep), &(*vs), &(*dzeta), &(*M), &(*iterates),
                &(*prints));
    if (check == 1)
        return 1;
    check = ComputeNormalFlow(zeta, &(*Hnorm), &(*Hsnorm), &(*Gbnorm), &(*Gsnorm), &(*ustarr),
        &(*Hr), &(*qsint), &(*ksid), &(*qbf), &(*qsf), &(*Cnorm), *dzeta, *D90, *D50,
        *qw, *R, *S, *I, *B, *Rep, *vs);
    if (check == 1)
        return 1;
    SetInitialBed(x, eta, ksi, &(*MassIn), &(*MassStored), &(*MassOut), &(*FracDisc),
        *dx, *S, *L, *ksid, *ru, *rd, *Hslot, *M);
    check = FluvialBackwater(H, Sf, Hs, eta, ksi, *qw, *D90, *D50, *R, *dx, *ksid, *M);
    if (check == 1)
        return 1;

    return 0;
}