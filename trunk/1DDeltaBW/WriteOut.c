/*
 *  WriteOut.c
 *  1DDeltaBW
 *
 *  Created by Andrew Leman on 7/17/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double printmatrix[][102], double xmatrix[][102], double Hmatrix[][102],
    double eta[], double sssvector[], double sbbvector[], double Volinit, double Volfin,
    double Volfed, double ervol, int prints, int M) {

    //Initialize
    int i=0, j=0;
    FILE *ptrOut;
    char nameOut[50];
    
    //Run
    printf("What do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten. \n");
    scanf("%s", &nameOut);
    ptrOut = fopen(nameOut, "w");
    
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "time (yr):\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "%lf\t\t", printmatrix[i][0]);
    }
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "sss (m):\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "%lf\t\t", sssvector[i]);
    }
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "sbb (m):\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "%lf\t\t", sbbvector[i]);
    }
    fprintf(ptrOut, "\n\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "x(m)\teta(m)\t");
    }
    fprintf(ptrOut, "Final w.s.");
    fprintf(ptrOut, "\n\t");
    for (i=1; i <= (M+2); i++) {
        for (j=0; j <= prints; j++) {
            fprintf(ptrOut, "%lf\t%lf\t", xmatrix[j][i], printmatrix[j][i]);
        }
        fprintf(ptrOut, "%lf", (eta[i] + Hmatrix[prints][i]));
        fprintf(ptrOut, "\n\t");
    }
    
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "time(yr)\tsss\tsbb\tetaup\tetatop\tetabottom\n");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", printmatrix[i][0], sssvector[i], sbbvector[i], printmatrix[i][1], printmatrix[i][M+1], printmatrix[i][M+2]);
    }
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "Volume of sediment per unit width for the initial bed: \t\t\t%lf\n", Volinit);
    fprintf(ptrOut, "Volume of sediment per unit width fed in: \t\t\t%lf\n", Volfed);
    fprintf(ptrOut, "Volume of sediment per unit width for the final bed: \t\t\t%lf\n", Volfin);
    fprintf(ptrOut, "Fractional error in mass balance: \t\t\t%lf\n", ervol);
    
    //Finalize
    fclose(ptrOut);
    return 0;
}