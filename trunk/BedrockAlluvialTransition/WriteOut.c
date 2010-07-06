/*
 *  WriteOut.c
 *  BedrockAlluvialTransition
 *
 *  Created by Andrew Leman on 7/15/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double printmatrix[][101], double xmatrix[][101], int M, int prints) {

    //Initialize
    int i=0, j=0;
    FILE *ptrOut;
    char nameOut[50];
    
    //Run
    printf("What do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut);
    ptrOut = fopen(nameOut, "w");
    
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "time (yr):\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "%.2lf\t\t", printmatrix[i][0]);
    }
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "sba (m):\t");
    for (i=0; i <= prints; i++) {
        if (fabs(xmatrix[i][1]) >= 100) {
            fprintf(ptrOut, "%lf\t\t", xmatrix[i][1]);
        }
        else {
            fprintf(ptrOut, "%lf\t\t", xmatrix[i][1]);
        }
    }
    fprintf(ptrOut, "\n\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "x(m)\teta(m)\t");
    }
    fprintf(ptrOut, "\n\t");
    for (i=1; i <= (M+1); i++) {
        for (j=0; j <= prints; j++) {
            fprintf(ptrOut, "%lf\t%lf\t", xmatrix[j][i], printmatrix[j][i]);
        }
        fprintf(ptrOut, "\n\t");
    }
    
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "year\tsba\n");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "%lf\t%lf\n", printmatrix[i][0], xmatrix[i][1]);
    }
    
    //Finalize
    fclose(ptrOut);
    return 0;
}