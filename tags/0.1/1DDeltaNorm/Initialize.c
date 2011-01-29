/*
 *  Initialize.c
 *  1DDeltaNorm
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, int *, int *, int *, int *);
int SetupInitialBedandTime(double [], double [], double [], double *, double *,
    double *, double *, double *, double *, double *, double *, double,
    double, double, double, double, double, double, double, int);

int Initialize(double xfbar[], double x[], double eta[], double Sl[], double *qw, double *I,
    double *qtf, double *D, double *Cz, double *nt, double *tsc, double *etasl,
    double *etabl, double *Sfi, double *Sb, double *ssfi, double *Sa, double *R,
    double *lamdap, double *ks, double *alphat, double *alphar, double *dt, double *dxbar,
    double *su, double *sss, double *sbb, double *etaup, double *etatop, double *etabot,
    double *abase, double *Volinit, int *M, int *prints, int *iterates, int *formulation) {

    int check=0, i=0;
    
    check = ReadIn(&(*qw), &(*I), &(*qtf), &(*D), &(*Cz), &(*nt), &(*tsc), &(*etasl),
                &(*etabl), &(*Sfi), &(*Sb), &(*ssfi), &(*Sa), &(*R), &(*lamdap),
                &(*ks), &(*alphat), &(*alphar), &(*dt), &(*dxbar), &(*M), &(*prints),
                &(*iterates), &(*formulation));
    if (check == 1)
        return 1;
    
    SetupInitialBedandTime(xfbar, x, eta, &(*su), &(*sss), &(*sbb), &(*etaup),
        &(*etatop), &(*etabot), &(*abase), &(*Volinit), *Sb, *lamdap, *Sfi, *ssfi,
        *etasl, *etabl, *Sa, *dxbar, *M);
        
    for (i=1; i <= (*M+1); i++) {
        Sl[i] = *Sfi;
    }
    
    return 0;
}