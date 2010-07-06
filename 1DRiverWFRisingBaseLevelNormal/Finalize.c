/*
 *  Finalize.c
 *  1DRiverWFRisingBaseLevelNormal
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [][101], double [][101], double [][101], double [], int, int);
int GetData(double [][101], double [][101], double [][101], double [][101], double [][101],
    double [], int, int);

int Finalize(double printmatrix[][101], double Bbfmatrix[][101], double Hbfmatrix[][101],
    double Slmatrix[][101], double qbmatrix[][101], double x[], int prints, int M) {

    WriteOut(printmatrix, Bbfmatrix, Hbfmatrix, x, prints, M);
    GetData(printmatrix, Slmatrix, qbmatrix, Bbfmatrix, Hbfmatrix, x, M, prints);
    return 0;
}