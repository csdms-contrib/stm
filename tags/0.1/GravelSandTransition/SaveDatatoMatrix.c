/*
 *  SaveDatatoMatrix.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SaveDatatoMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SaveDatatoMatrix(double printmatrix[][202], double Slmatrix[][203],
    double Hmatrix[][202], double qbmatrix[][202], double taumatrix[][202],
    double xmatrix[][202], double eta[], double Sl[], double H[], double qb[],
    double tau[], double x[], double sgsvector[], double Lvector[], double time,
    double sgs, double L, int Ms, int Mg, int k) {

    int i=0;
    
    for (i=1; i <= (Ms+Mg+1); i++) {
        printmatrix[k][i] = eta[i];
        Slmatrix[k][i] = Sl[i];
        Hmatrix[k][i] = H[i];
        qbmatrix[k][i] = qb[i];
        taumatrix[k][i] = tau[i];
        xmatrix[k][i] = x[i];
    }
    Slmatrix[k][Ms+Mg+2]=Sl[Ms+Mg+2];
    
    sgsvector[k] = sgs;
    Lvector[k] = L;
    
    printmatrix[k][0] = time/31557600;
    Slmatrix[k][0] = time/31557600;
    Hmatrix[k][0] = time/31557600;
    qbmatrix[k][0] = time/31557600;
    taumatrix[k][0] = time/31557600;
    xmatrix[k][0] = time/31557600;

    return 0;
}