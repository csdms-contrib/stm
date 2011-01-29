/*
 *  Run.c
 *  SteadyStateAg
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindEta(double [][22], double [], double, double, double, int);

int Run(double printmatrix[][22], double etadev[], double ksid, double ksidot, double time,
    int k) {

    FindEta(printmatrix, etadev, ksid, ksidot, time, k);
    return 0;
}