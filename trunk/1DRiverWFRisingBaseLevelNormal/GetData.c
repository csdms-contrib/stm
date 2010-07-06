/*
 *  GetData.c
 *  1DRiverWFRisingBaseLevelNormal
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "GetData.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int GetData(double printmatrix[][101], double Slmatrix[][101], double qbmatrix[][101],
    double Bbfmatrix[][101], double Hbfmatrix[][101], double x[], int M, int prints) {

    //Initialize
    int i=0, loop=0, skip=0, printi=40000;
    float time=0;
    char nameOut2[50];
    FILE * ptrOut2;
    
    //Run
    printf("Press 1 for additional output parameters for a given printout, press any other number to exit\n");
    scanf("%i", &loop);

    while (loop == 1) {
        skip = 0;
        printi=40000;
        printf("Specify the time in years of the printout\n");
        scanf("%f", &time);
        for(i=0; i<=prints; i++) {
            if ((fabs(printmatrix[i][0] - time)) <= 0.01) {
                printi = i;
            } 
        }
        if (printi == 40000) {
            printf("There is no printout for this time.  ");
            printf("Please choose another time.\n");
            skip = 1;
        }
        if (skip == 0) {
            printf("What what do you want to call the output file for %f years? (less than 50 characters please)\n", time);
            printf("WARNING: If you have a file with this name it will be overwritten.\n");
            scanf("%s", &nameOut2);
            ptrOut2 = fopen(nameOut2, "w");
            fprintf(ptrOut2, "\n\teta(m)\tSl\tqbT\tBbf(m)\tHbf(m)\n");
            if (time >= 100) {
                fprintf(ptrOut2, "x(m)\t%.0lfyr\t%.0lfyr\t%.0lfyr\t%.0lfyr\t%.0lfyr\n", printmatrix[printi][0], Slmatrix[printi][0], qbmatrix[printi][0], Bbfmatrix[printi][0], Hbfmatrix[printi][0]);
            }
            else if (time >= 0.1) {
                fprintf(ptrOut2, "x(m)\t%.2lfyr\t%.2lfyr\t%.2lfyr\t%.2lfyr\t%.2lfyr\n", printmatrix[printi][0], Slmatrix[printi][0], qbmatrix[printi][0], Bbfmatrix[printi][0], Hbfmatrix[printi][0]);
            }
            else {
                fprintf(ptrOut2, "x(m)\t%.5lfyr\t%.5lfyr\t%.5lfyr\t%.5lfyr\t%.5lfyr\n", printmatrix[printi][0], Slmatrix[printi][0], qbmatrix[printi][0], Bbfmatrix[printi][0], Hbfmatrix[printi][0]);
            }
            for (i=1; i <= (M+1); i++) {
                fprintf(ptrOut2, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", x[i], printmatrix[printi][i], Slmatrix[printi][i], qbmatrix[printi][i], Bbfmatrix[printi][i], Hbfmatrix[printi][i]);
            }
            fclose(ptrOut2);
        }
        printf("Would you like to:\n1. Print more\n2. Exit\n");
        scanf("%i", &loop);
    }
    
    //Finalize
    return 0;
}