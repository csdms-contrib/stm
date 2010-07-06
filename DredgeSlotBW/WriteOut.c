/*
 *  WriteOut.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double printmatrix[][2002], double ksimatrix[][2002], double Hmatrix[][2002],
    double x[], double Hnorm, double Hsnorm, double Gbnorm, double Gsnorm, double Cnorm,
    double ksid, int prints, int M) {

    //Initialize
    int i=0, j=0;
    FILE *ptrOut;
    char nameOut[50];

    //Run
    printf("What do you want to call the output file? (less than 50 characters, please) \n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut);
    ptrOut = fopen(nameOut, "w");
    
    fprintf(ptrOut, "time(yr):\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "%lf\t\t\t", printmatrix[i][0]);
    }
    fprintf(ptrOut, "\n");
    
    fprintf(ptrOut, "x[m]");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "\teta[m]\tksi[m]\tH[m]");
    }
    fprintf(ptrOut, "\n");
    
    for (i=1; i <= (M+1); i++) {
        fprintf(ptrOut, "%lf", x[i]);
        for (j=0; j <= prints; j++) {
            fprintf(ptrOut, "\t%lf\t%lf\t%lf", printmatrix[j][i], ksimatrix[j][i], Hmatrix[j][i]);
        }
        fprintf(ptrOut, "\n");
    }
    
    fprintf(ptrOut, "\nNormal Depth: \t\t\t%lf\t[m]", Hnorm);
    fprintf(ptrOut, "\nNormal Depth due to skin friction: \t\t\t%lf\t[m]", Hsnorm);
    fprintf(ptrOut, "\nBedload Transport Rate: \t\t\t%lf\t(tons/annum)", Gbnorm);
    fprintf(ptrOut, "\nSuspended Load Transport Rate: \t\t\t%lf\t(tons/annum)", Gsnorm);
    fprintf(ptrOut, "\nUpstream Volume Suspended Concentration: \t\t\t%lf", Cnorm);
    fprintf(ptrOut, "\nDownstream Water Surface Elevation: \t\t\t%lf\t[m]", ksid);
    
    //Finalize
    fclose(ptrOut);
    return 0;
}