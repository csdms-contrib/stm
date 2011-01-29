/*
 *  Initialize.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *, double *, double *, double *, double *, double *, double *,
    double *, int *, double *, double *);
int SetInitialBed(double [], double [], double [], double, double, double, double, int);

int Initialize(double x[], double eta[], double ksi[], double *Sl, double *R,
    double *D50s, double *D90s, double *B, double *Qw, double *ksid, double *L,
    double *qw, double *dx, int *M) {

    //Declarations
    int check=0;

    //Run
    check = ReadIn(&(*Sl), &(*R), &(*D50s), &(*D90s), &(*B), &(*Qw), &(*ksid), &(*L), &(*M), &(*qw), &(*dx));
    if (check == 1)
        return 1;
        
    SetInitialBed(x, eta, ksi, *dx, *Sl, *L, *ksid, *M);

    //Finalize
    return 0;
}