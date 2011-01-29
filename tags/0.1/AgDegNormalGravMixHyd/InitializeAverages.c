/*
 *  InitializeAverages.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "InitializeAverages.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int InitializeAverages(double Fave[][16], double plave[][16], double qbTave[],
    int M, int npp) {
    //Initialize
    int i=0, j=0;
    
    //Run
    for (i=1; i <= (M+1); i++) {
        qbTave[i] = 0;
        for (j=1; j < npp; j++) {
            Fave[i][j] = 0;
            plave[i][j] = 0;
        }
    }
    
    //Finalize
    return 0;
}