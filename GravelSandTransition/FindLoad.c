/*
 *  FindLoad.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindLoad(double qb[], double qgrav[], double qsand[], double tau[], double H[],
    double *qgravghost, double *qsandghost, double Cfg, double Cfs, double qwg,
    double qws, double R, double Dg, double Ds, double qfs, double qfg, double lamdasg,
    int Mg, int Ms) {

    int i=0;
    double taustar=0, taustarGc=0.03, taustarSc=0.0, alp=11.2, np=4.5, aleh=0.05, neh=2.5;
    
    for (i=1; i <= (Mg+1); i++) {
        tau[i] = Cfg*qwg*qwg/(H[i]*H[i]);
        taustar = tau[i]/(R*g*Dg);
        if (taustar <= taustarGc) {
            qgrav[i] = 0;
        }
        else {
            qgrav[i] = sqrt(R*g*Dg)*Dg*alp*pow(taustar, 1.5)*pow((1.0 - (taustarGc/taustar)), np);
        }
        if (i == 1) {
            qsand[i] = qfs;
        }
        else if (i < (Mg+1)) {
            qsand[i] = qsand[i-1] - lamdasg*(qgrav[i-1] - qgrav[i]);
            if (qsand[i] < 0) {
                qsand[i] = 0;
            }
        }
    }
    for (i=(Mg+1); i <= (Mg+Ms+1); i++) {
        tau[i] = Cfs*qws*qws/(H[i]*H[i]);
        taustar = tau[i]/(R*g*Ds);
        if (taustar <= taustarSc) {
            qsand = 0;
        }
        else {
            qsand[i] = sqrt(R*g*Ds)*Ds*aleh*pow((taustar - taustarSc), neh)/Cfs;
        }
        if (i > (Mg+1)) {
            qgrav[i] = 0;
        }
    }
    *qgravghost = qfg;
    *qsandghost = qsand[Mg] + qgrav[Mg+1];
    
    for (i=1; i <= (Mg+1); i++) {
        qb[i] = qgrav[i]+qsand[i];
    }
    for (i=(Mg+2); i <= (Mg+Ms+1); i++) {
        qb[i] = qsand[i];
    }

    return 0;
}