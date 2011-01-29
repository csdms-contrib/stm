/*
 *  Initialize.c
 *  SubsidingFan
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double [], double [], double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, int *, int *, int *);
int SetInitialBed(double [], double [], double, int);

int Initialize(double x[], double eta[], double qb[], double Sl[], double *Qtfeed,
    double *Lb, double *Qbf, double *D, double *Lamda, double *theta, double *lamdap,
    double *I, double *Cz, double *Sinu, double *sigma, double *aleh, double *neh,
    double *tauforms, double *alp, double *np, double *tausc, double *tauformg,
    double *Cf, double *dx, double *Su, double *R, double *dt, double *loadcoef, int *M, int *prints,
    int *iterates) {
    
    int check=0;
    
    check = ReadIn(qb, Sl, &(*Qtfeed), &(*Lb), &(*Qbf), &(*D), &(*Lamda), &(*theta),
                &(*lamdap), &(*I), &(*Cz), &(*Sinu), &(*sigma), &(*aleh), &(*neh),
                &(*tauforms), &(*alp), &(*np), &(*tausc), &(*tauformg), &(*Cf),
                &(*dx), &(*Su), &(*R), &(*dt), &(*loadcoef), &(*M), &(*iterates), &(*prints));
    if (check == 1) 
        return 1;
        
    SetInitialBed(x, eta, *dx, *M);
    
    return 0;
}
