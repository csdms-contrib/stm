/*
 *  Finalize.c
 *  BedrockAlluvialTransition
 *
 *  Created by Andrew Leman on 7/15/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [][101], double [][101], int, int);
int GetData(double [][101], double [][101], double [][101], double [][101], double [][101], int, int);

int Finalize(double printmatrix[][101], double xmatrix[][101], double Slmatrix[][101],
    double qbmatrix[][101], double Hmatrix[][101], int M, int prints) {

    WriteOut(printmatrix, xmatrix, M, prints);
    GetData(printmatrix, Slmatrix, qbmatrix, xmatrix, Hmatrix, M, prints);
    return 0;
}