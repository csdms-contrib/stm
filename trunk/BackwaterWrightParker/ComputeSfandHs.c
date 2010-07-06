/*
 *  ComputeSfandHs.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ComputeSfandHs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindTausmin(double *, double *);

int ComputeSfandHs(double *xH, double *xSf, double *xHs, double qw, double R, double D90s, double D50s) {

    //Declarations
    double ep=0.001, Frloc=0, Snom=0, tausnom=0, filoc=0, filocnew=0, a1=0, a2=0;
    double Ff=0, Ffp=0, ratioc=0, er=0, tausmin=0;
    int i=0, bombed=0, check=0;
    
    //Run
    Frloc = qw/(sqrt(g)*pow((*xH), 1.5));
    Snom = pow((Frloc/(8.32*pow(((*xH)/(3.0*D90s)), (1.0/6.0)))), 2);
    tausnom = (*xH)*Snom/(R*D50s);
    filoc = 0.9;
    for (i=1; i <= 21; i++) {
        check = FindTausmin(&Frloc, &tausmin);
        if (check == 1) {
            return 1;
        }
        ratioc = pow((tausnom/tausmin), 0.75);
        a1 = 0.7*pow(tausnom, 0.8)*pow(Frloc, (14.0/25.0));
        if (filoc <= ratioc) {
            a2 = (tausnom/cbrt(filoc) - 0.05);
            Ff = filoc - pow((a2/a1), (-15.0/16.0));
            Ffp = 1.0 - (15.0/16.0)*pow((a2/a1), (-31.0/16.0))*pow(filoc, (-4.0/3.0))*tausnom/(3.0*a1);
        }
        else {
            Ff = filoc - 1.0;
            Ffp = 1.0;
        }
        filocnew = filoc - (Ff/Ffp);
        if (filocnew < 0)
            filocnew = 1.02;
        er = fabs(2.0*(filocnew - filoc)/(filocnew + filoc));
        if (er < ep) {
           break; 
        }
        else if (i == 20) {
            bombed = 1;
            break;
        }
        else {
            filoc = filocnew;
        }
    }
    if (bombed == 0) {
        filoc = filocnew;
        *xHs = filoc*(*xH);
        *xSf = pow(filoc, (-4.0/3.0))*Snom;
    }
    else {
        filoc = 1.0;
    }

    //Finalize
    return 0;
}