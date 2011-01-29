/*
 *  WriteOut.c
 *  AgDegNormGravMixSubPW
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

int Perfiner(double [], double [], int);

int WriteOut(quad GSD[], char nameOut1[], int prints, int M, int npp, double printmatrix[][101],
    double dsgmatrix[][101], double qbTmatrix[][101], double x[], double H[], double F[][21], double pl[][21]) {
    //Initialize
    int choice=0, i=0, j=0;
    FILE *ptrOut;
    char nameOut[50];
    double pl1[npp+2], F1[npp+2], Fdown[npp+2], pfl1[npp+2], Ff1[npp+2], Ffdown[npp+2];
    
    //Run
        //User chooses whether to append or make a new file
        printf("Would you like to:\n1. print some additional output parameters to the output file\n2. create a new output file with some additional output parameters\n");
        scanf("%i", &choice);
        switch (choice) {
            case 1:
                ptrOut = fopen(nameOut1, "a");
                fprintf(ptrOut, "\n\n");
                break;
            case 2:
                printf("What do you want to call your additional parameters file? (less than 50 characters please)\n");
                printf("WARNING: If you have a file with this name it will be overwritten.\n");
                scanf("%s", &nameOut);
                ptrOut = fopen(nameOut, "w");
                break;
            default:
                printf("Invalid Choice! Plot data was not written to file");
                return 1;
        }

        //The print information
        //This prints out the eta, dsg, and load ratios with the final water surface
        fprintf(ptrOut, "\n\nPlot Data:\n\n\t");
        for (i=0; i <= prints; i++) {
            fprintf(ptrOut, "elev(m)\tDsg(mm)\tqbT/qbf\t");
        }
        fprintf(ptrOut, "\n");
        fprintf(ptrOut, "x(m)\t");
        for (i=0; i <= prints; i++) {
            fprintf(ptrOut, "%.0lfyr\t%.0lfyr\t%.0lfyr\t", printmatrix[i][0], printmatrix[i][0], printmatrix[i][0]);
        }
        fprintf(ptrOut, "final w.s.");
        fprintf(ptrOut, "\n\n");
        for (j=1; j <= (M+1); j++) {
            fprintf(ptrOut, "%lf\t", x[j]);
            for (i=0; i <= prints; i++) {
                fprintf(ptrOut, "%lf\t%lf\t%lf\t", printmatrix[i][j], dsgmatrix[i][j], qbTmatrix[i][j]);
            }
            fprintf(ptrOut, "%lf", (printmatrix[prints][j] + H[j]));
            fprintf(ptrOut, "\n");
        }
        fprintf(ptrOut, "\n\n");
    
        //Preps the GSD for final printout
        for (i=1; i <= (npp-1); i++) {
            pl1[i] = pl[1][i];
            F1[i] = F[1][i];
            Fdown[i] = F[M+1][i];
        }
        Perfiner(pl1, pfl1, npp);
        Perfiner(F1, Ff1, npp);
        Perfiner(Fdown, Ffdown, npp);
    
        //This prints out the final distribution
        fprintf(ptrOut, "Substrate distribution and\nfinal distribution at upstream and downstream nodes:\n\n");
        fprintf(ptrOut, "Di (mm)\tFfs\tpfeed\tFup\tFdown\n");
        for (i=1; i <= npp; i++) {
            fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t%lf\n", GSD[i].di, GSD[i].Ffs, pfl1[i], Ff1[i], Ffdown[i]);
        }
        
    
    //Finalize
    fclose(ptrOut);
    printf("\nYour file has been written.\n");
    return 0;
}

