/*
 *  FluvialBackwater.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/28/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FluvialBackwater.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int ComputeHsandSf(double *, double *, double *, double, double, double, double);

int FluvialBackwater(double H[], double Sf[], double Hs[], double eta[], double ksi[],
    double qw, double D90, double D50, double R, double dx, double ksid, int M) {

    double Hpred=0, Fr2up=0, Fr2dwn=0, fnp=0, fn=0, Hspred=0, Sfpred=0;
    int i=0, check=0;
    
    H[M+1] = ksid - eta[M+1];
    for (i=1; i <= M; i++) {
        if (i == 1) {
            check = ComputeHsandSf(&H[M+2-i], &Sf[M+2-i], &Hs[M+2-i], qw, D90, D50, R);
            if (check == 1)
                return 1;
        }
        Fr2dwn = qw*qw/g/pow(H[M+2-i], 3);
        fnp = (eta[M+1-i] - eta[M+2-i] - Sf[M+2-i]*dx)/(1.0 - Fr2dwn);
        Hpred = H[M+2-i] - fnp;
        check = ComputeHsandSf(&Hpred, &Sfpred, &Hspred, qw, D90, D50, R);
        if (check == 1)
            return 1;
        Fr2up = qw*qw/g/pow(Hpred, 3);
        fn = (eta[M+1-i] - eta[M+2-i] - Sfpred*dx)/(1.0 - Fr2up);
        H[M+1-i] = H[M+2-i] - 0.5*(fnp + fn);
        check = ComputeHsandSf(&H[M+1-i], &Sf[M+1-i], &Hs[M+1-i], qw, D90, D50, R);
        if (check == 1)
            return 1;
    }
    for (i=1; i <= M; i++) {
        ksi[i] = eta[i] + H[i];
    }

    return 0;
}