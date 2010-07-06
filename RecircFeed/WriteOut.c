/*
 *  WriteOut.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double printmatrix[][101], double SNupvector[], double SNdownvector[],
    double xhat[], int SNcounter, int Nreach, int k) {

     //Initialize
    int i=0, j=0;
    FILE *ptrOut;
    char nameOut[50];
    
    //Run
    printf("What do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut);
    ptrOut = fopen(nameOut, "w");
    
    fprintf(ptrOut, "\ntimehat:\t");
    for (i=0; i <= k; i++) {
        fprintf(ptrOut, "%lf\t", printmatrix[i][0]);
    }
    fprintf(ptrOut, "\nxhat\t");
    for (i=0; i <= k; i++) {
        fprintf(ptrOut, "etahat\t");
    }
    fprintf(ptrOut, "\n");
    for (j=1; j <= Nreach; j++) {
        fprintf(ptrOut, "%lf\t", xhat[j]);
        for (i=0; i <= k; i++) {
            fprintf(ptrOut, "%lf\t", printmatrix[i][j]);
        }
        fprintf(ptrOut, "\n");
    }
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "SNup\tSNdown\n");
    for (i=0; i < SNcounter; i++) {
        fprintf(ptrOut, "%lf\t%lf\n", SNupvector[i], SNdownvector[i]);
    }
    
    //Finalize
    fclose(ptrOut);
    return 0;
}