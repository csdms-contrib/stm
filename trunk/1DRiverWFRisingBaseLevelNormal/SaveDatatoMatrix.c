/*
 *  SaveDatatoMatrix.c
 *  1DRiverWFRisingBaseLevelNormal
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SaveDatatoMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SaveDatatoMatrix(double printmatrix[][101], double Bbfmatrix[][101], double Hbfmatrix[][101],
    double Slmatrix[][101], double qbmatrix[][101], double eta[], double Bbf[], double Hbf[],
    double Sl[], double Qt[], double time, int k, int M) {
    
    //Declarations
    int i=0;
    
    for(i=1; i <= (M+1); i++) {
        printmatrix[k][i] = eta[i];
        Bbfmatrix[k][i] = Bbf[i];
        Hbfmatrix[k][i] = Hbf[i];
        Slmatrix[k][i] = Sl[i];
        qbmatrix[k][i] = Qt[i];
    }
    printmatrix[k][0] = time;
    Bbfmatrix[k][0] = time;
    Hbfmatrix[k][0] = time;
    Slmatrix[k][0] = time;
    qbmatrix[k][0] = time;
    return 0;
}