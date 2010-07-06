/*
 *  FindNewEta.c
 *  BedrockAlluvialTransition
 *
 *  Created by Andrew Leman on 7/15/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewEta.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindNewEta(double eta[], double S[], double qb[], double xbar[], double x[], double I,
    double lamdap, double Sbase, double dt, double sd, double *sba, double *etaup,
    double dxbar, int M) {

    int i=0;
    double eta1old=0, sbadot=0;
    
    eta1old = eta[1];
    eta[1] += (Sbase/(Sbase - S[1]))*(qb[1] - qb[2])*dt/(dxbar*(sd- *sba));
    sbadot = (eta1old - eta[1])/(Sbase*dt);
    for (i=2; i <= M; i++) {
        eta[i] += (-dt)*S[i]*sbadot*(1 - xbar[i]);
        eta[i] += I*dt*(qb[i] - qb[i+1])/(dxbar*(sd- *sba)*(1.0 - lamdap));
    }
    *sba += sbadot*dt;
    *etaup = eta[1];
    for (i=1; i <= (M+1); i++) {
        x[i] = *sba + xbar[i]*(sd - *sba);
    }

    return 0;
}