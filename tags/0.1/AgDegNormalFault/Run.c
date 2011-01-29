/*
 *  Run.c
 *  AgDegNormalFault
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FaultBed(double, double, int *, double, int, double [], double, double);
int FindSlopes(double [], int, double [], double);
int FindDepthShear(double [], double [], int, double, double, double, double, double [], double,
        double, double, int);
int FindLoad(double [], int, double, double [], double, double, double, double, double,
        double, double []);
int FindNewEta(double [], int, double, double, double, double, double, double [], double);

int Run(int *notfaultedyet, double tf, double time, double ifault, int M, double eta[],
    double deltaeta, double dt, double Sl[], double dx, double tau[], double Ht[],
    double Qf, double kc, double alphar, double B, double D, double R, double Cf,
    int formulation, double qb[], double phis, double tauc, double nt, double alphat,
    double Slmin, double lamdap, double If, double alphau, double qtg) {

    //While the bed has not faulted it checks to see if it ought to
    if (*notfaultedyet == 1) {
        FaultBed(tf, time, &(*notfaultedyet), ifault, M, eta, deltaeta, dt);
    }
    FindSlopes(Sl, M, eta, dx);
    FindDepthShear(tau, Ht, M, Qf, kc, alphar, B, Sl, D, R, Cf, formulation);
    FindLoad(qb, M, phis, tau, tauc, nt, D, R, alphat, Slmin, Sl);
    FindNewEta(eta, M, dt, lamdap, If, alphau, dx, qb, qtg);
    return 0;

}