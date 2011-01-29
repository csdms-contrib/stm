/*
 *  ValuesandIntegration.c
 *  DepDistTotLoadCalc
 *
 *  Created by Andrew Leman on 7/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ValuesandIntegration.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FallVelocity(double *, double *, double *, double, double, double);
int Integration(int, double [], double [], double [], double []);

int ValuesandIntegration(int N, double Cz[], double U[], double u[], double kc[],
    double H[], double Zu[], double us[], double E[], double I[], double qs[],
    double qt[], double qbqt[], double vsku[], double qb[], double D50s,
    double R, double nu, double Sl) {

    //Declarations
    int i=0;
    double Rep=0, Rf=0, vs=0;
    
    //Run
    FallVelocity(&Rep, &Rf, &vs, D50s, R, nu);
    
    for (i=1; i <= N; i++) {
        Cz[i] = U[i]/u[i];
        kc[i] = 11*H[i]*1000/exp(0.4*Cz[i]);
        Zu[i] = us[i]*pow(Rep, 0.6)*pow(Sl, 0.07)/(vs/100);
        E[i] = 0.00000057*pow(Zu[i], 5)/(1+(0.00000057/0.3)*pow(Zu[i], 5));
        vsku[i] = vs/(100*0.4*u[i]);
    }
    
    Integration(N, vsku, H, kc, I);
    
    for (i=1; i <= N; i++) {
        qs[i] = u[i]*E[i]*H[i]*I[i]/0.4;
        qt[i] = qb[i] + qs[i];
        qbqt[i] = qb[i]/qt[i];
    }
    
    //Finalize
    return 0;
}