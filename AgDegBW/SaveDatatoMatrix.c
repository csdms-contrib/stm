/*
 *  SaveDatatoMatrix.c
 *  AgDegBW
 *
 *  Created by Andrew Leman on 7/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SaveDatatoMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SaveDatatoMatrix(double printmatrix[][101], double Slmatrix[][101], double Hmatrix[][101],
    double taumatrix[][101], double qbmatrix[][101], double ksimatrix[][101], double eta[],
    double Sl[], double Ht[], double tau[], double qb[], double ksi[], float time, int k, int M) {
    //Initialize
    int i=0;
    
    //Run
    for (i=1; i <= (M+1); i++) {
        printmatrix[k][i] = eta[i];
    }
    printmatrix[k][0] = time;
    
    for (i=1; i <= (M+1); i++) {
        Slmatrix[k][i] = Sl[i];
    }
    Slmatrix[k][0] = time;
    
    for (i=1; i <= (M+1); i++) {
        Hmatrix[k][i] = Ht[i];
    }
    Hmatrix[k][0] = time;
    
    for (i=1; i <= (M+1); i++) {
        taumatrix[k][i] = tau[i];
    }
    taumatrix[k][0] = time;
    
    for (i=1; i <= (M+1); i++) {
        qbmatrix[k][i] = qb[i];
    }
    qbmatrix[k][0] = time;
    
    for (i=1; i <= (M+1); i++) {
        ksimatrix[k][i] = ksi[i];
    }
    ksimatrix[k][0] = time;
    
    //Finalize
    return 0;
}
