/*
 *  Finalize.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [], double [], double [], double [], double [], int, double);

int Finalize(double x[], double eta[], double ksi[], double H[], double Hs[], int M, double Hnorm) {

    WriteOut(x, eta, ksi, H, Hs, M, Hnorm);
    return 0;
}