/*
 *  FluvialBackwater.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FluvialBackwater.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int ComputeSfandHs(double *, double *, double *, double, double, double, double);

int FluvialBackwater(double eta[], double H[], double Sf[], double ksi[], double Hs[],
    double ksid, double qw, double dx, double R, double D90s, double D50s, int M) {

    //Declarations
    double fr2dn=0, fnp=0, Hpred=0, fr2up=0, fn=0, Sfpred=0, Hspred=0;
    int check=0, i=0;
    
    //Run
    H[M+1] = ksid - eta[M+1];
    for (i=1; i <= M; i++) {
        if (i == 1) {
            check = ComputeSfandHs(&H[M+2-i], &Sf[M+2-i], &Hs[M+2-i], qw, R, D90s, D50s);
            if (check == 1)
                return 1;
        }
        fr2dn = qw*qw/(g*pow(H[M+2-i], 3));
        fnp = (eta[M+1-i] - eta[M+2-i] - Sf[M+2-i]*dx)/(1.0 - fr2dn);
        Hpred = H[M+2-i] - fnp;
        check = ComputeSfandHs(&Hpred, &Sfpred, &Hspred, qw, R, D90s, D50s);
        if (check == 1)
            return 1;
        fr2up = qw*qw/(g*pow(Hpred, 3));
        fn = (eta[M+1-i] - eta[M+2-i] - Sfpred*dx)/(1.0 - fr2up);
        H[M+1-i] = H[M+2-i] - 0.5*(fnp+fn);
        check = ComputeSfandHs(&H[M+1-i], &Sf[M+1-i], &Hs[M+1-i], qw, R, D90s, D50s);
        if (check == 1)
            return 1;
    }
    for (i=1; i <= M; i++) {
        ksi[i] = eta[i] + H[i];
    }
            
    //Finalize
    return 0;
}