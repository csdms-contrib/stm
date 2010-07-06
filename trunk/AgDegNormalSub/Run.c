/*
 *  Run.c
 *  AgDegNormalSub
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Deparmtent.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindSlopes(double [], int, double [], float);
int FindDepthShear(double [], double [], int, float, float, float, double [], float, float, float, int);
int FindLoad(double [], int, float, double [], float, float, float, float, float, double []);
int FindNewEta(double [], int, float, float, float, float, float, double [], float, float, float, float, float);

int Run(double Sl[], int M, double eta[], float dx, double tau[], double H[], float qw,
    float kc, float alphar, float D, float R, float Cf, int formulation, double qb[],
    float phis, float tauc, float nt, float alphat, float dt, float lamdap, float If,
    float alphau, float qtg, float sigma, float rB, float omega, float lamda) {

    FindSlopes(Sl, M, eta, dx);
    FindDepthShear(tau, H, M, qw, kc, alphar, Sl, D, R, Cf, formulation);
    FindLoad(qb, M, phis, tau, tauc, nt, D, R, alphat, Sl);
    FindNewEta(eta, M, dt, lamdap, If, alphau, dx, qb, qtg, sigma, rB, omega, lamda);
    return 0;

}