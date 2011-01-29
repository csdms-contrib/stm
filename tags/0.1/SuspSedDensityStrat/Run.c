/*
 *  Run.c
 *  SuspSedDensityStrat
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ComputeUCNormal(double [], double [], double [], double [], double [], double [],
        double [], double *, double *, double *, double, double, double, int, double []);
int CheckConvergence(int, double [], double [], double [], double [], int *);

int Run(double Ri[], double zeta[], double Fstrat[], double un[], double cn[],
    double unold[], double cnold[], double *una, double *cna, double *qs, double *dzeta,
    double *ustarr, double *Ristar, int *n, double intc[], int *bombed) {
    
    //Declarations
    int converges=0;
    
    //Run
    while ((*bombed == 0) && (converges == 0)) {
        *n += 1;
        ComputeUCNormal(Ri, zeta, Fstrat, un, cn, unold, cnold, &(*una), &(*cna), &(*qs),
            *dzeta, *ustarr, *Ristar, *n, intc);
        *bombed = CheckConvergence(*n, un, cn, unold, cnold, &converges);
    }
    printf("%i\n", *n);
    
    //Finalize
    return 0;
}