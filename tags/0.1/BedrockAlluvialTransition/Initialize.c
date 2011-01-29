/*
 *  Initialize.c
 *  BedrockAlluvialTransition
 *
 *  Created by Andrew Leman on 7/15/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *, double *, double *, double *, double *, double *, double *,
    double *, int *, double *, int *, int *, double *, double *, double *, double *);
int SetupInitialBedTime(double [], double [], double [], double, double, double,
    double *, double *, int);

int Initialize(double xbar[], double x[], double eta[], double Sl[], double *qw, double *I, double *qtf,
    double *D, double *Cz, double *Sbase, double *Sfinit, double *sd, int *M, double *dt,
    int *prints, int *iterates, double *dxbar, double *alphas, double *etaup, double *sba,
    double *R, double *lamdap) {

    int i=0;
    
    ReadIn(&(*qw), &(*I), &(*qtf), &(*D), &(*Cz), &(*Sbase), &(*Sfinit), &(*sd),
        &(*M), &(*dt), &(*prints), &(*iterates), &(*dxbar), &(*alphas), &(*R), &(*lamdap));
        
    SetupInitialBedTime(xbar, x, eta, *sd, *Sfinit, *dxbar, &(*etaup), &(*sba), *M);
    
    for (i=1; i <= (*M+1); i++) {
        Sl[i] = *Sfinit;
    }
    
    return 0;
}