/*
 *  Finalize.c
 *  1DDeltaBW
 *
 *  Created by Andrew Leman on 7/17/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [][102], double [][102], double [][102], double [], double [],
    double [], double, double, double, double, int, int);
int MassBalance(double [], double [], double, double, double, double, double, double,
    double *, double *, double *, int, int, int);
int GetData(double [][102], double [][102], double [][102], double [][102], double [][102],
    double [][102], int, int);

int Finalize(double printmatrix[][102], double xmatrix[][102], double Slmatrix[][102],
    double qbmatrix[][102], double Hmatrix[][102], double taumatrix[][102],
    double sssvector[], double sbbvector[], double x[], double eta[], double Volinit,
    double Volfin, double Volfed, double ervol, double dt, double qtf, double lamdap,
    double Sb, double abase, int prints, int M, int iterates) {


    MassBalance(x, eta, abase, Sb, lamdap, qtf, dt, Volinit, &Volfin, &Volfed,
        &ervol, M, prints, iterates);
    WriteOut(printmatrix, xmatrix, Hmatrix, eta, sssvector, sbbvector, Volinit, Volfin, Volfed,
        ervol, prints, M);
    GetData(printmatrix, Slmatrix, qbmatrix, xmatrix, Hmatrix, taumatrix, M, prints);

    return 0;
}