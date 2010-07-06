/*
 *  WriteOut.c
 *  1DRiverWFRisingBaseLevelNormal
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double printmatrix[][101], double Bbfmatrix[][101], double Hbfmatrix[][101], double x[], int prints, int M) {

    //Initialize
    int i=0, j=0;
    FILE *ptrOut;
    char nameOut[50];
    
    //Run
    printf("What do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut);
    ptrOut = fopen(nameOut, "w");
    
    fprintf(ptrOut, "\ntime (yrs):\t");
    for (i=0; i <= (prints); i++) {
        fprintf(ptrOut, "%lf\t", printmatrix[i][0]);
    }
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "x(m)\t");
    for (i=0; i <= (prints); i++) {
        fprintf(ptrOut, "eta (m)\t");
    }
    fprintf(ptrOut, "\n");
    for (i=1; i <= (M+1); i++) {
        fprintf(ptrOut, "%lf\t", x[i]);
        for (j=0; j <= (prints); j++) {
            fprintf(ptrOut, "%lf\t", printmatrix[j][i]);
        }
        fprintf(ptrOut, "\n");
    }
    
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "\ntime (yrs):\t");
    for (i=0; i <= (prints); i++) {
        fprintf(ptrOut, "%lf\t", printmatrix[i][0]);
    }
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "x(m)\t");
    for (i=0; i <= (prints); i++) {
        fprintf(ptrOut, "Bbf (m)\t");
    }
    fprintf(ptrOut, "\n");
    for (i=1; i <= (M+1); i++) {
        fprintf(ptrOut, "%lf\t", x[i]);
        for (j=0; j <= (prints); j++) {
            fprintf(ptrOut, "%lf\t", Bbfmatrix[j][i]);
        }
        fprintf(ptrOut, "\n");
    }
    
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "\ntime (yrs):\t");
    for (i=0; i <= (prints); i++) {
        fprintf(ptrOut, "%lf\t", printmatrix[i][0]);
    }
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "x(m)\t");
    for (i=0; i <= (prints); i++) {
        fprintf(ptrOut, "Hbf (m)\t");
    }
    fprintf(ptrOut, "\n");
    for (i=1; i <= (M+1); i++) {
        fprintf(ptrOut, "%lf\t", x[i]);
        for (j=0; j <= (prints); j++) {
            fprintf(ptrOut, "%lf\t", Hbfmatrix[j][i]);
        }
        fprintf(ptrOut, "\n");
    }
    
    //Finalize
    fclose(ptrOut);
    return 0;
}