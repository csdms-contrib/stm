/*
 *  FindNormalDepth.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNormalDepth.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindTausmin(double *, double *);
double fi(double, double, double, double);

int FindNormalDepth(double *Hnorm, double qw, double D90s, double D50s, double Sl, double R) {

    //Declarations
    double ep=0.001, er=0, Hnormnew=0, FNt=0, FNtp=0, Fr=0, tausmin=0, taus=0;
    int i=0, bombed=0;

    //Run
    *Hnorm = pow((cbrt(3.0*D90s)*qw*qw/(8.32*8.32*g*Sl)), 0.3);
    for (i=1; i <= 200; i++) {
        Fr = qw/(sqrt(g)*pow((*Hnorm), 1.5));
        taus = (*Hnorm)*Sl/(R*D50s);
        FindTausmin(&Fr, &tausmin);
        if ((*Hnorm) >= (R*D50s*tausmin/Sl)) {
            FNt = (*Hnorm)*fi((*Hnorm), qw, Sl, D90s) - (R*D50s/Sl)*(0.05 + 0.7*pow(taus, 0.8)*pow(Fr, (14.0/25.0)));
            FNtp = fi((*Hnorm), qw, Sl, D90s)*(-1.5) + (R*D50s*0.7*pow(taus, 0.8)*pow(Fr, (14.0/25.0))/(25.0*(*Hnorm)*Sl));
        }
        else {
            FNt = (*Hnorm)*fi((*Hnorm), qw, Sl, D90s) - (*Hnorm);
            FNtp = fi((*Hnorm), qw, Sl, D90s)*(-1.5) - 1;
        }
        Hnormnew = (*Hnorm) - (FNt/FNtp);
        er = fabs(2*(Hnormnew - (*Hnorm))/(Hnormnew + (*Hnorm)));
        if (er < ep) {
            break;
        }
        else if (i == 200) {
            bombed = 1;
            break;
        }
        else {
            (*Hnorm) = Hnormnew;
        }
    }
    if (bombed == 0) {
        *Hnorm = Hnormnew;
    }
    else {
        printf("Calculation of Hnorm failed to converge.\n");
        printf("%lf\n", *Hnorm);
        *Hnorm = 0;
    }

    //Finalize
    return 0;
}