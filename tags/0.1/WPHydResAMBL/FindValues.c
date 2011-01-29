/*
 *  FindValues.c
 *  WPHydResAMBL
 *
 *  Created by Andrew Leman on 7/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindValues.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindValues(int N, double Hs[], double U[], double Gamma[], double H[], double tausg[],
    double qw[], double ratio[], double Fr[], double u[], double us[], double qb[],
    double Hso, double Hstep, double Sl, double R, double D50s, double D90s, double astrat,
    double nk, double tau[]) {

    //Initialize
    int i=0;
    
    //Run
    for (i=1; i <= N; i++) {
        Hs[i] = Hso + (i-1)*Hstep;
        tausg[i] = Hs[i]*Sl/(R*(D50s/1000));
        U[i] = (8.32/astrat)*sqrt(g*Hs[i]*Sl)*pow((Hs[i]/(nk*(D90s/1000))), (1.0/6.0));
        Gamma[i] = pow(((tausg[i] - 0.05)/0.7), 1.25);
        H[i] = pow((((Gamma[i]*R*(D50s/1000))/Sl)*pow((sqrt(g)/U[i]), 0.7)), (20.0/13.0));
        qw[i] = H[i]*U[i];
        tau[i] = H[i]*Sl/(R*(D50s/1000));
        ratio[i] = tausg[i]/tau[i];
        Fr[i] = U[i]/sqrt(g*H[i]);
        u[i] = sqrt(g*H[i]*Sl);
        us[i] = sqrt(g*Hs[i]*Sl);
        qb[i] = sqrt(R*g*D50s/1000)*(D50s/1000)*17*(tausg[i] - 0.05)*(sqrt(tausg[i])-sqrt(0.05));
    }
    
    
    //Finalize
    return 0;
}