/*
 *  ComputeUCNormal.c
 *  SuspSedDensityStrat
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ComputeUCNormal.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ComputeUCNormal(double Ri[], double zeta[], double Fstrat[], double un[], double cn[],
    double unold[], double cnold[], double *una, double *cna, double *qs, double dzeta,
    double ustarr, double Ristar, int n, double intc[]) {
    
    //Initialize
    double ku1=0, ku2=0, kc1=0, kc2=0, kappa=0.4, X=0;
    int i=0, nintervals=50;
    
    //Run
    if (n > 0) {
        for (i=1; i <= (nintervals+1); i++) {
            unold[i] = un[i];
            cnold[i] = cn[i];
        }
    }
    for (i=2; i <= (nintervals+1); i++) {
        ku1 = 1/(kappa*zeta[i-1]*Fstrat[i-1]);
        ku2 = 1/(kappa*zeta[i]*Fstrat[i]);
        un[i] = un[i-1] + (0.5*(ku1+ku2)*dzeta);
        kc1 = 1/((1 - zeta[i-1])*zeta[i-1]*Fstrat[i-1]);
        kc2 = 1/((1 - zeta[i])*zeta[i]*Fstrat[i]);
        intc[i] = intc[i-1] + (0.5*(kc1+kc2)*dzeta);
        cn[i] = exp(-intc[i]/(kappa*ustarr));
    }
    *una = 0.5*dzeta*(un[1]+un[nintervals+1]);
    *cna = 0.5*dzeta*(cn[1]+cn[nintervals+1]);
    *qs = 0.5*dzeta*(un[1]*cn[1] + un[nintervals+1]*cn[nintervals+1]);
    for (i=2; i <= (nintervals+1); i++) {
        *una += dzeta*un[i];
        *cna += dzeta*cn[i];
        *qs += dzeta*un[i]*cn[i];
    }
    for (i=1; i <= (nintervals+1); i++) {
        Ri[i] = Ristar*cn[i]*(kappa*zeta[i]*Fstrat[i])/(ustarr*(1-zeta[i]));
        X = 1.35*Ri[i]/(1 + (1.35*Ri[i]));
        Fstrat[i] = 1/(1+(10*X));
    }
    Ri[nintervals+1] = 0;
    Fstrat[nintervals+1] = 1;
    
    //Finalize
    return 0;
}