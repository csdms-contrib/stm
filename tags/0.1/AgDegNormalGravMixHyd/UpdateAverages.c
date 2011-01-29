/*
 *  UpdateAverages.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "UpdateAverages.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int UpdateAverages(double Fave[][16], double F[][16], double plave[][16], double pl[][16],
    double qbTave[], double qbT[], int M, int np) {
    //Initialize
    int i=0, j=0;
    
    //Run
    for (i=1; i <= (M+1); i++) {
        qbTave[i] += qbT[i];
        for (j=1; j<= np; j++) {
            Fave[i][j] += F[i][j];
            plave[i][j] += pl[i][j]*qbT[i];
        }
    }
    
    //Finalize
    return 0;
}