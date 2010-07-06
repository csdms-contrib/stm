/*
 *  FindNormalDepth.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNormalDepth.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int Findtausmin(double *, double, int *);
double fi(double, double, double, double);

int FindNormalDepth(double *Hnorm, int *bombedH, double D90, double qw, double S, double D50, double R) {

    double ep=0.001;
    double Hnormnew=0, err=0, FNt=0, FNtp=0, Fr=0, tausmin=0, taus=0;
    int i=0, bombed=0, check=0;
    
    *Hnorm = pow((cbrt(3*D90)*qw*qw/(8.32*8.32*g*S)), 0.3);
    for (i=1; i <= 201; i++) {
        Fr = qw/(sqrt(g)*pow(*Hnorm, 1.5));
        taus = *Hnorm*S/(R*D50);
        check = Findtausmin(&tausmin, Fr, &bombed);
        if (check == 1) 
            return 1;
        if (*Hnorm >= (R*D50*tausmin/S)) {
            FNt = *Hnorm*fi(*Hnorm, qw, S, D90) - R*D50*(0.05 + 0.7*pow(taus, 0.8)*pow(Fr, (14.0/25.0)))/S;
            FNtp = fi(*Hnorm, qw, S, D90) - 2.5*fi(*Hnorm, qw, S, D90) + 0.7*R*D50*pow(taus, 0.8)*pow(Fr, (14.0/25.0))/(25*(*Hnorm)*S);
        }
        else {
            FNt = *Hnorm*fi(*Hnorm, qw, S, D90) - *Hnorm;
            FNtp = fi(*Hnorm, qw, S, D90) - 2.5*fi(*Hnorm, qw, S, D90) - 1.0;
        }
        Hnormnew = *Hnorm - FNt/FNtp;
        err = fabs(2*(Hnormnew - *Hnorm)/(Hnormnew + *Hnorm));
        if (err < ep) {
            break;
        }
        else if (i > 200) {
            *bombedH = 1;
            break;
        }
        else {
            *Hnorm = Hnormnew;
        }
    }
    
    if (*bombedH == 0) {
        *Hnorm = Hnormnew;
    }
    else {
        printf("The Hnorm calculation failed to converge!  Please try again.\n");
        return 1;
    }

    return 0;
}