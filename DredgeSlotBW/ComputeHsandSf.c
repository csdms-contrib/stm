/*
 *  ComputeHsandSf.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/28/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ComputeHsandSf.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int Findtausmin(double *, double, int *);

int ComputeHsandSf(double *H, double *Sf, double *Hs, double qw, double D90, double D50, double R) {

    double ep=0.001, Frloc=0, Snom=0, tausnom=0, filoc=0, filocnew=0, ratloc=0, a1=0;
    double a2=0, Ff=0, Ffp=0, err=0, tausmin=0;
    int i=0, bombed=0, bombed1=0, check=0;
    
    Frloc = qw/(sqrt(g)*pow(*H, 1.5));
    Snom = pow((Frloc/(8.32*pow((*H/(3.0*D90)), (1.0/6.0)))), 2);
    tausnom = *H*Snom/(R*D50);
    filoc = 0.9;
    for (i=1; i <= 21; i++) {
        check = Findtausmin(&tausmin, Frloc, &bombed);
        if (check == 1)
            return 1;
        ratloc = pow((tausnom/tausmin), 0.75);
        a1 = 0.7*pow(tausnom, 0.8)*pow(Frloc, (14.0/25.0));
        if (filoc <= ratloc) {
            a2 = tausnom*pow(filoc, (-1.0/3.0)) - 0.05;
            Ff = filoc - pow((a2/a1), (-15.0/16.0));
            Ffp = 1.0 - (15.0/16.0)*pow((a2/a1), (-31.0/16.0))*pow(filoc, (-4.0/3.0))*tausnom/(3*a1);
        }
        else {
            Ff = filoc - 1.0;
            Ffp = 1.0;
        }
        filocnew = filoc - Ff/Ffp;
        if (filocnew < 0) {
            filocnew = 1.02;
        }
        err = fabs(2.0*(filocnew - filoc)/(filocnew + filoc));
        if (err < ep) {
            break;
        }
        else if (i > 20) {
            bombed1 = 1;
            break;
        }
        else {
            filoc = filocnew;
        }
    }
    if (bombed1 == 0) {
        filoc = filocnew;
        *Hs = filoc*(*H);
        *Sf = pow(filoc, (-4.0/3.0))*Snom;
    }
    else {
        filoc = 1.0;
    }

    return 0;
}