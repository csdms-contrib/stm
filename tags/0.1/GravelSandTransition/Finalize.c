/*
 *  Finalize.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [][202], double [][202], double [][202], double [][203], double [][202], double [], double [], double [], int, int, int);
int GetData(double [][202], double [][203], double [][202], double [][202], double [][202], double [][202], int, int, int);

int Finalize(double printmatrix[][202], double xmatrix[][202], double Hmatrix[][202],
    double Slmatrix[][203], double qbmatrix[][202], double taumatrix[][202],
    double sgsvector[], double Lvector[], double H[], int Ms, int Mg, int prints) {

    WriteOut(printmatrix, xmatrix, Hmatrix, Slmatrix, qbmatrix, sgsvector, Lvector, H, Ms, Mg, prints);
    GetData(printmatrix, Slmatrix, qbmatrix, xmatrix, Hmatrix, taumatrix, Ms, Mg, prints);
    
    return 0;
}