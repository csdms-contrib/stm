/*
 *  GetData.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "GetData.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int GetData(double printmatrix[][202], double Slmatrix[][203], double qbmatrix[][202],
    double xmatrix[][202], double Hmatrix[][202], double taumatrix[][202], int Ms,
    int Mg, int prints) {

    //Initialize
    int i=0, loop=0, skip=0, printi=400005;
    float time=0;
    char nameOut2[50];
    FILE * ptrOut2;
    
    //Run
    printf("Press 1 for additional output parameters for a given printout, press any other number to exit.\n");
    scanf("%i", &loop);

    while (loop == 1) {
        skip = 0;
        printi=400005;
        printf("Specify the time in years of the printout.\n");
        scanf("%f", &time);
        for(i=0; i<=prints; i++) {
            if ((fabs(printmatrix[i][0] - time)) <= 0.01) {
                printi = i;
            } 
        }
        if (printi == 400005) {
            printf("There is no printout for this time.  ");
            printf("Please choose another time.\n");
            skip = 1;
        }
        if (skip == 0) {
            printf("What do you want to call the output file for %f years? (less than 50 characters please)\n", time);
            printf("WARNING: If you have a file with this name it will be overwritten.\n");
            scanf("%s", &nameOut2);
            ptrOut2 = fopen(nameOut2, "w");
            fprintf(ptrOut2, "\nx(m)\teta(m)\tSl\tqb\tH(m)\ttau\n");
            if (time >= 100) {
                fprintf(ptrOut2, "%.0lfyr\t%.0lfyr\t%.0lfyr\t%.0lfyr\t%.0lfyr\t%.0lfyr\n", xmatrix[printi][0], printmatrix[printi][0], Slmatrix[printi][0], qbmatrix[printi][0],  Hmatrix[printi][0], taumatrix[printi][0]);
            }
            else if (time >= 0.1) {
                fprintf(ptrOut2, "%.2lfyr\t%.2lfyr\t%.2lfyr\t%.2lfyr\t%.2lfyr\t%.2lfyr\n", xmatrix[printi][0], printmatrix[printi][0], Slmatrix[printi][0], qbmatrix[printi][0],  Hmatrix[printi][0], taumatrix[printi][0]);
            }
            else {
                fprintf(ptrOut2, "%.5lfyr\t%.5lfyr\t%.5lfyr\t%.5lfyr\t%.5lfyr\t%.5lfyr\n", xmatrix[printi][0], printmatrix[printi][0], Slmatrix[printi][0], qbmatrix[printi][0],  Hmatrix[printi][0], taumatrix[printi][0]);
            }
            for (i=1; i <= (Ms+Mg+1); i++) {
                fprintf(ptrOut2, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", xmatrix[printi][i], printmatrix[printi][i], Slmatrix[printi][i], qbmatrix[printi][i], Hmatrix[printi][i], taumatrix[printi][i]);
                if (i == (Mg+1)) {
                    fprintf(ptrOut2, "\t\t%lf\n", Slmatrix[printi][Ms+Mg+2]);
                }   
            }
            fclose(ptrOut2);
        }
        printf("Would you like to:\n1. Print more\n2. Exit\n");
        scanf("%i", &loop);
    }
    
    //Finalize
    return 0;
}

