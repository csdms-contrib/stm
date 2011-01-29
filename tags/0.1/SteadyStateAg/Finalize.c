/*
 *  Finalize.c
 *  SteadyStateAg
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [][22], double [], double [], double [], double [], double [], double [], double [], double [], int);

int Finalize(double printmatrix[][22], double xhat[], double x[], double Qtbf[],
    double Sl[], double etahat[], double etadev[], double Bbf[], double Hbf[], int prints) {
    
    WriteOut(printmatrix, xhat, x, Qtbf, Sl, etahat, etadev, Bbf, Hbf, prints);
    return 0;
}