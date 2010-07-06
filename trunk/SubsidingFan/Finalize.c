/*
 *  Finalize.c
 *  SubsidingFan
 *
 *  Created by Andrew Leman on 7/23/09.
 *  Copyright 2009 The University of illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [][101], double [], int, int);
int GetData(double [][101], double [][101], double [][101], double [], int, int);

int Finalize(double printmatrix[][101], double Slmatrix[][101], double qbmatrix[][101],
    double x[], int prints, int M) {

    WriteOut(printmatrix, x, prints, M);
    GetData(printmatrix, Slmatrix, qbmatrix, x, M, prints);

    return 0;
}