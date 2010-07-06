/*
 *  WriteOut.c
 *  SteadyStateAg
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double printmatrix[][22], double xhat[], double x[], double Qtbf[],
    double Sl[], double etahat[], double etadev[], double Bbf[], double Hbf[],
    int prints) {

    //Initialize
    int i=0, j=0;
    FILE *ptrOut;
    char nameOut[50];
    
    //Run
    printf("What do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut);
    ptrOut = fopen(nameOut, "w");
    
    fprintf(ptrOut, "xhat\tx(km)\tQtbf(m^3/s)\tS\tetahat\tetadev(m)\tBbf(m)\tHbf(m)\teta(m)\n\t\t\t\t\t\t\t\t");
    for (i=0; i <= prints; i++) {
        if (printmatrix[i][0] < 100) {
            fprintf(ptrOut, "%.1lfyr\t", printmatrix[i][0]);
        }
        else {
            fprintf(ptrOut, "%.1lfyr\t", printmatrix[i][0]);
        }
    }
    fprintf(ptrOut, "\n");
    for (i=1; i <= 21; i++) {
        fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t", xhat[i], x[i], Qtbf[i], Sl[i], etahat[i], etadev[i], Bbf[i], Hbf[i]);
        for (j=0; j <= prints; j++) {
            fprintf(ptrOut, "%lf\t", printmatrix[j][i]);
        }
        fprintf(ptrOut, "\n");
    }
    
    //Finalize
    fclose(ptrOut);
    return 0;
}