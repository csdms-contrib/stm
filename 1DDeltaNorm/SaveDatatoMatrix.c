/*
 *  SaveDatatoMatrix.c
 *  1DDeltaNorm
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SaveDatatoMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SaveDatatoMatrix(double printmatrix[][102], double Slmatrix[][102], double qbmatrix[][102],
    double Hmatrix[][102], double taumatrix[][102], double xmatrix[][102], double eta[],
    double Sl[], double qb[], double H[], double tau[], double x[], double suvector[],
    double sssvector[], double sbbvector[], double time, double su, double sss, double sbb,
    int k, int M) {

    int i=0;

    for (i=1; i <= (M+2); i++) {
        printmatrix[k][i] = eta[i];
        Slmatrix[k][i] = Sl[i];
        qbmatrix[k][i] = qb[i];
        Hmatrix[k][i] = H[i];
        taumatrix[k][i] = tau[i];
        xmatrix[k][i] = x[i];
    }

    suvector[k] = su;
    sssvector[k] = sss;
    sbbvector[k] = sbb;

    printmatrix[k][0] = time/(31557600.0);
    Slmatrix[k][0] = time/(31557600.0);
    qbmatrix[k][0] = time/(31557600.0);
    Hmatrix[k][0] = time/(31557600.0);
    taumatrix[k][0] = time/(31557600.0);
    xmatrix[k][0] = time/(31557600.0);
    
    return 0;
}