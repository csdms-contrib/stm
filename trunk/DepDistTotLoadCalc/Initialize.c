/*
 *  Initialize.c
 *  DepDistTotLoadCalc
 *
 *  Created by Andrew Leman on 7/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *, double *, double *, double *, double *, double *, double *,
    int *, double *, double *, double *);

int Initialize(double *Sl, double *R, double *D50s, double *D90s, double *nk, double *Hso,
    double *Hstep, int *N, double *astrat, double *nu, double *ks) {

    //Declarations
    int check=0;

    //Run
    check = ReadIn(&(*Sl), &(*R), &(*D50s), &(*D90s), &(*nk), &(*Hso), &(*Hstep),
                &(*N), &(*astrat), &(*nu), &(*ks));
    if (check == 1)
        return 1;
        
    //Finalize
    return 0;
    
}