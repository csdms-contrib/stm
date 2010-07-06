/*
 *  Run.c
 *  AgDegNormal
 *
 *  Created by Andrew Leman on 7/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindSlopes(double [], int, double [], float);
int FindDepthShear(double [], double [], int, float, float, float, float, double [], float, float, float, int);
int FindLoad(double [], int, float, double [], float, float, float, float, float);
int FindNewEta(double [], int, float, float, float, float, float, double [], float);

int Run(double Sl[], int M, double eta[], float dx, double tau[], double Ht[], float Qf,
    float kc, float alphar, float B, float D, float R, float Cf, int formulation,
    double qb[], float phis, float tauc, float nt, float alphat, float dt, float lamdap,
    float If, float alphau, float qtg) {

    FindSlopes(Sl, M, eta, dx);
    FindDepthShear(tau, Ht, M, Qf, kc, alphar, B, Sl, D, R, Cf, formulation);
    FindLoad(qb, M, phis, tau, tauc, nt, D, R, alphat);
    FindNewEta(eta, M, dt, lamdap, If, alphau, dx, qb, qtg);

    return 0;

}