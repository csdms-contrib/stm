/*
 *  SaveDatatoMatrix.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SaveDatatoMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SaveDatatoMatrix(double printmatrix[][2002], double Hmatrix[][2002], double ksimatrix[][2002],
    double qbmatrix[][2002], double qsmatrix[][2002], double Hsmatrix[][2002], double eta[],
    double H[], double ksi[], double qb[], double qs[], double Hs[], double time, int k, int M) {

    int i=0;

    for (i=1; i <= (M+1); i++) {
        printmatrix[k][i] = eta[i];
        Hmatrix[k][i] = H[i];
        ksimatrix[k][i] = ksi[i];
        qbmatrix[k][i] = qb[i];
        qsmatrix[k][i] = qs[i];
        Hsmatrix[k][i] = Hs[i];
    }
    
    printmatrix[k][0] = time/31557600;
    Hmatrix[k][0] = time/31557600;
    ksimatrix[k][0] = time/31557600;
    qbmatrix[k][0] = time/31557600;
    qsmatrix[k][0] = time/31557600;
    Hsmatrix[k][0] = time/31557600;
    
    return 0;
}