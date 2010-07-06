/*
 *  FluvialBackwater.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FluvialBackwater.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FluvialBackwater(double H[], double eta[], double x[], double ksid, double Cfs,
    double Cfg, double qws, double qwg, int Ms, int Mg) {

    double Hpred=0, fr2p=0, fr2=0, fnp=0, fn=0, dx=0, Cftemp=0, qwtemp=0;
    int i=0;
    
    H[Mg+Ms+1] = ksid - eta[Ms+Mg+1];
    for (i=1; i <= Ms; i++) {
        dx = x[Ms+Mg+2-i] - x[Mg+Ms+1-i];
        Cftemp = Cfs;
        qwtemp = qws;
        fr2p = qwtemp*qwtemp/(g*pow(H[Mg+Ms+2-i], 3));
        fnp = (eta[Mg+Ms+1-i] - eta[Mg+Ms+2-i] - Cftemp*fr2p*dx)/(1.0 - fr2p);
        Hpred = H[Mg+Ms+2-i] - fnp;
        fr2 = qwtemp*qwtemp/(g*pow(Hpred, 3));
        fn = (eta[Mg+Ms+1-i] - eta[Mg+Ms+2-i] - Cftemp*fr2*dx)/(1.0 - fr2);
        H[Mg+Ms+1-i] = H[Mg+Ms+2-i] - 0.5*(fnp+fn);
    }
    for (i = (Ms+1); i <= (Ms+Mg); i++) {
        dx = x[Ms+Mg+2-i] - x[Mg+Ms+1-i];
        Cftemp = Cfg;
        qwtemp = qwg;
        fr2p = qwtemp*qwtemp/(g*pow(H[Mg+Ms+2-i], 3));
        fnp = (eta[Mg+Ms+1-i] - eta[Mg+Ms+2-i] - Cftemp*fr2p*dx)/(1.0 - fr2p);
        Hpred = H[Mg+Ms+2-i] - fnp;
        fr2 = qwtemp*qwtemp/(g*pow(Hpred, 3));
        fn = (eta[Mg+Ms+1-i] - eta[Mg+Ms+2-i] - Cftemp*fr2*dx)/(1.0 - fr2);
        H[Mg+Ms+1-i] = H[Mg+Ms+2-i] - 0.5*(fnp+fn);
    }

    return 0;
}