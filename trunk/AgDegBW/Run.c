/*
 *  Run.c
 *  AgDegBW
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
int FindShieldsandLoad(double [], double [], int, float, float, double [], float,
            float, float, float, float, float, float, float, int);
int FindNewEta(double [], int, float, float, float, float, float, double [], float);
int FluvialBackwater(double [], double [], double [], int, float, float, float,
            float, float, float, int);

int Run(double Sl[], int M, double eta[], float dx, double tau[], double qb[],
    float Cf, float alphar, double H[], float kc, float qw, float R, float D,
    float tauc, float nt, float phis, float alphat, int formulation, float dt,
    float lamdap, float If, float alphau, float qtg, double ksi[], float ksio) {

    FindSlopes(Sl, M, eta, dx);
    FindShieldsandLoad(tau, qb, M, Cf, alphar, H, kc, qw, R, D, tauc, nt, phis, alphat, formulation);
    FindNewEta(eta, M, dt, lamdap, If, alphau, dx, qb, qtg);
    FluvialBackwater(eta, ksi, H, M, qw, alphar, kc, ksio, dx, Cf, formulation);
    return 0;

}