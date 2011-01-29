/*
 *  WriteOut.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double printmatrix[][202], double xmatrix[][202], double Hmatrix[][202],
    double Slmatrix[][203], double qbmatrix[][202], double sgsvector[], double Lvector[],
    double H[], int Ms, int Mg, int prints) {

    //Initialize
    int i=0, j=0, choice=0;
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
    fprintf(ptrOut, "sgs (m):\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "%lf\t\t", sgsvector[i]);
    }
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "L (m):\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "%lf\t\t", Lvector[i]);
    }
    fprintf(ptrOut, "\n\t");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "x(m)\teta(m)\t");
    }
    fprintf(ptrOut, "Final w.s.");
    fprintf(ptrOut, "\n\t");
    for (i=1; i <= (Ms+Mg+1); i++) {
        for (j=0; j <= prints; j++) {
            fprintf(ptrOut, "%lf\t%lf\t", xmatrix[j][i], printmatrix[j][i]);
        }
        fprintf(ptrOut, "%lf", (printmatrix[prints][i] + H[i]));
        fprintf(ptrOut, "\n\t");
    }
    
    fprintf(ptrOut, "\n");
    fprintf(ptrOut, "year\tsgs\tL\n");
    for (i=0; i <= prints; i++) {
        fprintf(ptrOut, "%lf\t%lf\t%lf\n", printmatrix[i][0], sgsvector[i], Lvector[i]);
    }
    
    printf("Press 1 to print out plot data for additional parameters.\n");
    printf("Press any other number to leave these parameters out\n");
    scanf("%i", &choice);
    if (choice == 1) {
        fprintf(ptrOut, "\n\n");
        fprintf(ptrOut, "time (yr):\t");
        for (i=0; i <= prints; i++) {
            fprintf(ptrOut, "%.2lf\t\t\t\t", printmatrix[i][0]);
        }
        fprintf(ptrOut, "\n\t");
        for (i=0; i <= prints; i++) {
            fprintf(ptrOut, "x(m)\tSl\tH(m)\tqb(m^2/s)\t");
        }
        fprintf(ptrOut, "\n\t");
        for (i=1; i <= (Ms+Mg+1); i++) {
            for (j=0; j <= prints; j++) {
                fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t", xmatrix[j][i], Slmatrix[j][i], Hmatrix[j][i], qbmatrix[j][i]);
            }
            if (i == (Mg+1)) {
                fprintf(ptrOut, "\n\t");
            }
            for (j=0; j <= prints; j++) {
                 if (i == (Mg+1)) {
                    fprintf(ptrOut, "\t%lf\t\t\t", Slmatrix[j][Ms+Mg+2]);
                }
            }
            fprintf(ptrOut, "\n\t");
        }
    }
    
    //Finalize
    fclose(ptrOut);
    return 0;
}