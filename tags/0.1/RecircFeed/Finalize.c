/*
 *  Finalize.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [][101], double[], double [], double [], int, int, int);
int GetData(double [][101], double [][101], double [][101], double [][101], double [], int, int);

int Finalize(double printmatrix[][101], double Slmatrix[][101], double qbmatrix[][101],
    double Hmatrix[][101], double SNupvector[], double SNdownvector[], double xhat[],
    int SNcounter, int Nreach, int k, int M) {

    WriteOut(printmatrix, SNupvector, SNdownvector, xhat, SNcounter, Nreach, k);
    GetData(printmatrix, Slmatrix, qbmatrix, Hmatrix, xhat, M, k);
    return 0;
}