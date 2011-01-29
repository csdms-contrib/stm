/*
 *  MassBalance.c
 *  1DDeltaNorm
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "MassBalance.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MassBalance(double x[], double eta[], double *Volfin, double *Volfed, double *ervol,
    double Volinit, double qtf, double lamdap, double dt, double Sb, double abase,
    int prints, int iterates, int M) {

    //Declarations
    int i=0;
    double etabase=0, etad[102];

    for (i=1; i <= (M+2); i++) {
        etabase = abase - Sb*x[i];
        etad[i] = eta[i] - etabase;
    }
    
    *Volfin = 0.5*etad[1]*(x[2]-x[1]);
    
    for (i=1; i <= (M+1); i++) {
        *Volfin += 0.5*(etad[i] + etad[i+1])*(x[i+1] - x[i]);
    }
    
    *Volfin = (1.0 - lamdap)*(*Volfin + 0.5*etad[M+2]*(x[M+2] - x[M+1]));
    *Volfed = qtf*dt*prints*iterates;
    *ervol = fabs((*Volfin - Volinit - *Volfed)/(*Volfed));

    return 0;
}