/*
 *  Finalize.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 8/3/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [][2002], double [][2002], double [][2002], double [], double,
    double, double, double, double, double, int, int);
int GetData(double [][2002], double [][2002], double [][2002], double [][2002],
    double [][2002], double [][2002], double [], int, int);

int Finalize(double printmatrix[][2002], double Hmatrix[][2002], double Hsmatrix[][2002],
    double qbmatrix[][2002], double qsmatrix[][2002], double ksimatrix[][2002],
    double x[], double Hnorm, double Hsnorm, double Gbnorm, double Gsnorm, double Cnorm,
    double ksid, int M, int prints) {

    WriteOut(printmatrix, ksimatrix, Hmatrix, x, Hnorm, Hsnorm, Gbnorm, Gsnorm, Cnorm, ksid, prints, M);
    GetData(printmatrix, Hmatrix, Hsmatrix, qbmatrix, qsmatrix, ksimatrix, x, M, prints);

    return 0;
}