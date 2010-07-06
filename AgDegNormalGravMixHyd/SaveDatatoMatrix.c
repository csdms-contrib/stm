/*
 *  SaveDatatoMatrix.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SaveDatatoMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SaveDatatoMatrix(double printmatrix[][101], double dsgmatrix[][101], double qbTmatrix[][101],
    double dlgmatrix[][101], double Smatrix[][101], double Hmatrix[][101], double tausgmatrix[][101],
    double D90matrix[][101], double eta[], double dsgsave[], double qbTave[], double H[], double tausg[],
    double Dx90s[], double qbToave, double time, int M, int k, double Sl[], double dsglave[]) {
    //Initialize
    int i=0;
    
    //Run
    for (i=1; i <= (M+1); i++) {
        printmatrix[k][i] = eta[i];
    }
    for (i=1; i <= (M+1); i++) {
        dsgmatrix[k][i] = dsgsave[i];
    }
    for (i=1; i <=(M+1); i++) {
        Smatrix[k][i] = Sl[i];
    }
    
    if (k > 0) {
        for (i=1; i <= (M+1); i++) {
            qbTmatrix[k][i] = qbTave[i]/qbToave;
        }
        for (i=1; i <=(M+1); i++) {
            dlgmatrix[k][i] = dsglave[i];
        }
    } 
    for (i=1; i <= (M+1); i++) {
        Hmatrix[k][i] = H[i];
    }
    for (i=1; i <= (M+1); i++) {
        tausgmatrix[k][i] = tausg[i];
    }
    for (i=1; i <= (M+1); i++) {
        D90matrix[k][i] = Dx90s[i];
    }   
    printmatrix[k][0] = time/(365.25*86400.0);
    dsgmatrix[k][0] = time/(365.25*86400.0);
    qbTmatrix[k][0] = time/(365.25*86400.0);
    Smatrix[k][0] = time/(365.25*86400.0);
    dlgmatrix[k][0] = time/(365.25*86400.0);
    Hmatrix[k][0] = time/(365.25*86400.0);
    tausgmatrix[k][0] = time/(365.25*86400.0);
    D90matrix[k][0] = time/(365.25*86400.0);
    
    //Finalize
    return 0;
}
