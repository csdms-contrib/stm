/*
 *  FindLoad.c
 *  BedrockAlluvialTransition
 *
 *  Created by Andrew Leman on 7/15/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindLoad(double eta[], double S[], double qb[], double H[], double qtf, double dxbar,
    double sd, double sba, double Cz, double alphas, double qw,
    double R, double D, int M) {

    //Declarations and constants
    int i=0;
    double St[101], taus=0, tausc=0, ns=2.5;
    
    S[1] = (eta[1] - eta[2])/(dxbar*(sd-sba));
    qb[1] = qtf;
    for (i=2; i <= M; i++) {
        S[i] = (eta[i-1] - eta[i+1])/(2*dxbar*(sd-sba));
    }
    for (i=2; i <= (M+1); i++) {
        St[i] = (eta[i-1] - eta[i])/(dxbar*(sd-sba));
        H[i] = cbrt((qw*qw/(g*St[i]*pow(Cz, 2))));
        taus = H[i]*St[i]/(R*D);
        if (taus <= 0) {
            qb[i] = 0;
        }
        else {
            qb[i] = alphas*(pow((taus - tausc), ns)*sqrt(R*g*D))*D;
        }
    }

    return 0;
}