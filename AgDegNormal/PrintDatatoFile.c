/*
 *  PrintDatatoFile.c
 *  AgDegNormal
 *
 *  Created by Andrew Leman on 6/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "PrintDatatoFile.h"
#include <stdio.h>
#include <stdlib.h>

int PrintDatatoFile(FILE *ptrOut1, double printmatrix[][101], double x[], int M, int prints,
    float L, float dx, float Sult){
    //Initialize
    int i=0, j=0;
    
    //Run
    fprintf(ptrOut1, "\n\t");
    for (i=0; i<= (prints+1); i++) {
        fprintf(ptrOut1, "eta(m)\t");
    }
    fprintf(ptrOut1, "\nx(m)\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut1, "%.0lfyr\t", printmatrix[i][0]);
    }
    fprintf(ptrOut1, "Ultimate");
    fprintf(ptrOut1, "\n");
    for (i=1; i <= (M+1); i++) {
        fprintf(ptrOut1, "%lf\t", x[i]);
        for (j=0; j<= prints; j++) {
            fprintf(ptrOut1, "%lf\t", printmatrix[j][i]);
        }
        fprintf(ptrOut1, "%lf", (Sult*L - Sult*dx*(i-1)));
        fprintf(ptrOut1, "\n");
    }
    
    //Finalize
    return 0;
}