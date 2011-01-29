/*
 *  PrintDatatoFile.c
 *  AgDegNormGravMixPW
 *
 *  Created by Andrew Leman on 6/18/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "PrintDatatoFile.h"
#include <stdio.h>
#include <stdlib.h>

int PrintDatatoFile(FILE *ptrOut1, double printmatrix[][101], double x[], int M, int prints){
    //Initialize
    int i=0, j=0;
    
    //Run
    fprintf(ptrOut1, "\n");
    fprintf(ptrOut1, "time (yrs):\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut1, "%lf\t", printmatrix[i][0]);
    }
    fprintf(ptrOut1, "\n");
    fprintf(ptrOut1, "x (m)\t");
    for (i=0; i <=prints; i++) {
        fprintf(ptrOut1, "eta (m)\t");
    }
    fprintf(ptrOut1, "\n");
    for (j=1; j <= (M+1); j++) {
        fprintf(ptrOut1, "%lf\t", x[j]);
        for (i=0; i <= prints; i++) {
            fprintf(ptrOut1, "%lf\t", printmatrix[i][j]);
        }
        fprintf(ptrOut1, "\n");
    }
    
    //Finalize
    return 0;
}