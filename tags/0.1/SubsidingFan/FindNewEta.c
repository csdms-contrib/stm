/*
 *  FindNewEta.c
 *  SubsidingFan
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewEta.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindNewEta(double eta[], double qb[], double x[], double theta, double sigma,
    double dt, double I, double Lamda, double dx, double Sinu, double lamdap,
    double Su, int M) {

    int i=0;
    double Bb=0;
    
    for (i=2; i <= M; i++) {
        Bb = theta*x[i];
        eta[i] = eta[i] - sigma*dt + I*dt*(1.0 + Lamda)*(qb[i-1] - qb[i+1])/(2.0*dx*Bb*Sinu*(1.0 - lamdap));
    }
    eta[M+1] = eta[M];
    eta[1] = eta[2] + Su*dx;

    return 0;
}