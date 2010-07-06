/*
 *  SaveDatatoMatrix.c
 *  SubsidingFan
 *
 *  Created by Andrew Leman on 7/23/09.
 *  Copyright 2009 The University of illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SaveDatatoMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SaveDatatoMatrix(double printmatrix[][101], double Slmatrix[][101], double qbmatrix[][101],
    double eta[], double Sl[], double qb[], double time, int k, int M) {

    int i=0;
    
    for (i=1; i <= (M+1); i++) {
        printmatrix[k][i] = eta[i];
        Slmatrix[k][i] = Sl[i];
        qbmatrix[k][i] = qb[i];
    }
    
    printmatrix[k][0] = time/31557600;
    Slmatrix[k][0] = time/31557600;
    qbmatrix[k][0] = time/31557600;

    return 0;
}