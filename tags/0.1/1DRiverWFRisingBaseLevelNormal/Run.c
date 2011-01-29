/*
 *  Run.c
 *  1DRiverWFRisingBaseLevelNormal
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindSlopeandLoad(double [], double [], double [], double [], double [], double,
    double, double, double, double, double, int);
int FindNewEta(double [], double [], double, double, double, double, double, double, double,
    double, double, double, double, double, int);

int Run(double Sl[], double eta[], double Qt[], double Bbf[], double Hbf[], double dx,
    double loadcoef, double widthcoef, double depthcoef, double D, double Qf, double I,
    double Sinu, double lambig, double Bf, double lamp, double dt, double time,
    double Qbtffeed, double Yearstart, double Yearstop, double etaddot, int M) {

    FindSlopeandLoad(Sl, eta, Qt, Bbf, Hbf, dx, loadcoef, widthcoef, depthcoef, D, Qf, M);
    FindNewEta(eta, Qt, I, Sinu, lambig, Bf, lamp, dt, time, dx, Qbtffeed, Yearstart, Yearstop, etaddot, M);
    return 0;
}