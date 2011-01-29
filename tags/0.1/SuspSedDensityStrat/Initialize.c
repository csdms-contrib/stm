/*
 *  Initialize.c
 *  SuspSedDensityStrat
 *
 *  Created by Andrew Leman on 7/6/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *, double *, double *, double *, double *, double *, double *);
int PreliminaryCalculations(double *, double *, double *, double *, double *, double *,
        double *, double, double, double, double, double, double);
int PrepLoop(double [], double [], double [], double [], double [], double [], double,
        int *, double *);
int ComputeUCNormal(double [], double [], double [], double [], double [], double [],
        double [], double *, double *, double *, double, double, double, int, double []);

int Initialize(double *R, double *D, double *H, double *kc, double *ustar, double *nu,
    double *Cr, double zeta[], double Ri[], double Fstrat[], double un[], double cn[],
    double intc[], double unold[], double cnold[], double *una, double *cna, double *qs,
    double *dzeta, double *ustarr, double *Ristar, double *Rep, double *vs, double *Hr,
    double *unr, int *n, double initun[], double initcn[], double *unao, double *cnao, double *qso) {

    //Initialize
    int i=0, nintervals=50;
    
    //Run
    ReadIn(&(*R), &(*D), &(*H), &(*kc), &(*ustar), &(*nu), &(*Cr));
    PreliminaryCalculations(&(*Rep), &(*vs), &(*Hr), &(*ustarr), &(*unr), &(*Cr),
        &(*Ristar), *R, *D, *H, *kc, *ustar, *nu);
    PrepLoop(zeta, Ri, Fstrat, un, cn, intc, *unr, &(*n), &(*dzeta));
    ComputeUCNormal(Ri, zeta, Fstrat, un, cn, unold, cnold, &(*una), &(*cna), &(*qs),
        *dzeta, *ustarr, *Ristar, *n, intc);
    for (i=1; i <= (nintervals + 1); i++) {
        initun[i] = un[i];
        initcn[i] = cn[i];
    }
    *unao = *una;
    *cnao = *cna;
    *qso = *qs;
    
    //Finalize
    return 0;
}
