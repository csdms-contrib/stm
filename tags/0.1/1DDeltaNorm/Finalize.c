/*
 *  Finalize.c
 *  1DDeltaNorm
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MassBalance(double [], double [], double *, double *, double *, double, double,
    double, double, double, double, int, int, int);
int WriteOut(double [][102], double [][102], double [], double [], double [], double,
    double, double, double, int, int);
int GetData(double [][102], double [][102], double [][102], double [][102], double [][102], double [][102], int, int);

int Finalize(double printmatrix[][102], double xmatrix[][102], double Slmatrix[][102],
    double qbmatrix[][102], double Hmatrix[][102], double taumatrix[][102],
    double suvector[], double sssvector[], double sbbvector[], double x[], double eta[], 
    double Volinit, double qtf, double lamdap, double dt, double Sb, double abase,
    int iterates, int prints, int M) {
    
    //Declarations
    double Volfin=0, Volfed=0, ervol=0;
            
    MassBalance(x, eta, &Volfin, &Volfed, &ervol, Volinit, qtf, lamdap, dt, Sb,
        abase, prints, iterates, M);
    WriteOut(printmatrix, xmatrix, suvector, sssvector, sbbvector, Volinit, Volfin,
        Volfed, ervol, prints, M);
    GetData(printmatrix, Slmatrix, qbmatrix, xmatrix, Hmatrix, taumatrix, M, prints);

    return 0;
}