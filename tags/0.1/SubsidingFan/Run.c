/*
 *  Run.c
 *  SubsidingFan
 *
 *  Created by Andrew Leman on 7/23/09.
 *  Copyright 2009 The University of illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindSlopeLoad(double [], double [], double [], double, double, double, int);
int FindNewEta(double [], double [], double [], double, double, double, double, double, double, double, double, double, int);

int Run(double Sl[], double qb[], double eta[], double x[], double dx, double loadcoef,
    double Qbf, double theta, double sigma, double dt, double I, double Lamda, double Sinu,
    double lamdap, double Su, int M) {

    FindSlopeLoad(Sl, qb, eta, dx, loadcoef, Qbf, M);
    FindNewEta(eta, qb, x, theta, sigma, dt, I, Lamda, dx, Sinu, lamdap, Su, M);

    return 0;
}