/*
 *  Initialize.c
 *  SteadyStateAg
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, int *);
int SetupInitialBed(double [], double [], double);
int FindInitialValues(double [], double [], double [], double [], double [], double [],
    double [], double , double, double, double, double, double, double, double, double, 
    double);

int Initialize(double Qtbf[], double Sl[], double etahat[], double etadev[], double Bbf[],
    double Hbf[], double xhat[], double x[], double *Gt, double *L, double *ksidot,
    double *Qbf, double *B, double *D, double *Lamda, double *tauform, double *aleh,
    double *lamdap, double *Cz, double *I, double *Cf, double *Omega, double *R,
    double *ksid, double *dt, double *Qt, double *C, double *BMSS, double *Su,
    double *beta, int *prints) {

    int check=0;
    
    check = ReadIn(&(*Gt), &(*L), &(*ksidot), &(*Qbf), &(*B), &(*D), &(*Lamda),
                &(*tauform), &(*aleh), &(*lamdap), &(*Cz), &(*I), &(*Cf), &(*Omega),
                &(*R), &(*ksid), &(*dt), &(*Qt), &(*C), &(*BMSS), &(*Su), &(*beta),
                &(*prints));
    if (check == 1)
        return 1;
        
    SetupInitialBed(xhat, x, *L);
    FindInitialValues(Qtbf, Sl, etahat, etadev, Bbf, Hbf, xhat, *Qt, *beta, *Su,
        *L, *Cf, *aleh, *R, *D, *Qbf, *tauform);
    
    return 0;
}