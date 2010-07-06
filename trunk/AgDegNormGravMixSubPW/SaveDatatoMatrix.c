/*
 *  SaveDatatoMatrix.c
 *  AgDegNormGravMixSubPW
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SaveDatatoMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SaveDatatoMatrix(double printmatrix[][101], double dsgmatrix[][101], double qbTmatrix[][101],
    double Hmatrix[][101], double tausgmatrix[][101], double Slmatrix[][101], double D90matrix[][101],
    double eta[], double dsgs[], double qbT[], double H[], double tausg[], double Sl[], double Dx90s[],
    double qbTf, double time, int M, int k) {
    //Initialize
    int i=0;
    
    //Run
    for (i=1; i <= (M+1); i++) {
        printmatrix[k][i] = eta[i];
    }
    for (i=1; i <= (M+1); i++) {
        dsgmatrix[k][i] = dsgs[i];
    }
    if (k > 0) {
        for (i=1; i <= (M+1); i++) {
            qbTmatrix[k][i] = qbT[i]/qbTf;
        }
    }
    for (i=1; i <= (M+1); i++) {
        Hmatrix[k][i] = H[i];
    }
    for (i=1; i <= (M+1); i++) {
        tausgmatrix[k][i] = tausg[i];
    }
    for (i=1; i <= (M+1); i++) {
        Slmatrix[k][i] = Sl[i];
    } 
    for (i=1; i <= (M+1); i++) {
        D90matrix[k][i] = Dx90s[i];
    }
    printmatrix[k][0] = time/(365.25*86400.0);
    dsgmatrix[k][0] = time/(365.25*86400.0);
    qbTmatrix[k][0] = time/(365.25*86400.0);
    Hmatrix[k][0] = time/(365.25*86400.0);
    tausgmatrix[k][0] = time/(365.25*86400.0);
    Slmatrix[k][0] = time/(365.25*86400.0);
    D90matrix[k][0] = time/(365.25*86400.0);
    
    //Finalize
    return 0;
}