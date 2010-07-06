/*
 *  SaveDatatoMatrix.c
 *  BedrockAlluvialTransition
 *
 *  Created by Andrew Leman on 7/15/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SaveDatatoMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SaveDatatoMatrix(double printmatrix[][101], double Slmatrix[][101], double qbmatrix[][101],
    double Hmatrix[][101], double xmatrix[][101], double x[], double eta[], double Sl[],
    double qb[], double H[], double time, int M, int k) {

    int i=0;
    
    for (i=1; i <= (M+1); i++) {
        printmatrix[k][i] = eta[i];
        Slmatrix[k][i] = Sl[i];
        qbmatrix[k][i] = qb[i];
        Hmatrix[k][i] = H[i];
        xmatrix[k][i] = x[i];
    }

    printmatrix[k][0] = time/31557600;
    Slmatrix[k][0] = time/31557600;
    qbmatrix[k][0] = time/31557600;
    Hmatrix[k][0] = time/31557600;
    xmatrix[k][0] = time/31557600;

    return 0;
}