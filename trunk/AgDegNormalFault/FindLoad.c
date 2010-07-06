/*
 *  FindLoad.c
 *  AgDegNormalFault
 *
 *  Created by Andrew Leman on 6/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Deparmtent.
 *  All rights reserved.
 */

#include "FindLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindLoad(double qb[], int M, double phis, double tau[], double tauc, double nt,
             double D, double R, double alphat, double Slmin, double Sl[]) {
    //Initialize
    int i=0;
    double load[M+2];
    
    //Run
    for (i=1; i <= (M+1); i++) {
            if ((phis*tau[i] <= tauc) || (Sl[i] <= Slmin))
                load[i] = 0;
            else
                load[i] = alphat*pow((phis*tau[i]-tauc), nt);
            }
            
        for (i=1; i <= (M+1); i++) {
            qb[i] = load[i]*(D)*sqrt(R*g*(D));
            }
    
    //Finalize
    return 0;
}