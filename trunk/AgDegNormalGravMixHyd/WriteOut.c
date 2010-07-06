/*
 *  WriteOut.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
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

int WriteOut(quad GSD[], char nameOut1[], int prints, int M, int npp, double printmatrix[][101],
    double dsgmatrix[][101], double qbTmatrix[][101], double x[], double H[], double F[][16],
    double pl[][16], double Smatrix[][101], double dlgmatrix[][101], double etaendcyc[],
    double Hflowmax[], double Hflowend[], double tausgflowmax[], double tausgflowend[],
    double dsgsflowmax[], double dsgsflowend[], double dsglflowmax[], double dsglflowend[],
    double Ffinerflowmaxds[], double Ffinerflowendds[], double plfinerflowmaxds[],
    double plfinerflowendds[], int totstep, double qbTfforprint[], double dayforprint[],
    double qwforprint[], double qbToforprint[], double qwave, double qbToave, double dsgsi,
    double dsgsub, double LoadAnn) {
    //Initialize
    int choice=0, i=0, j=0;
    FILE *ptrOut;
    char nameOut[50];
    
    //Run
        //User chooses whether to append or make a new file
        printf("Would you like to:\n1. print some additional output parameters to the output file\n2. create a new output file with some of the additional output parameters\n");
        scanf("%i", &choice);
        switch (choice) {
            case 1:
                ptrOut = fopen(nameOut1, "a");
                fprintf(ptrOut, "\n\n");
                break;
            case 2:
                printf("What do you want to call the additional output parameters file? (less than 50 characters please)\n");
                printf("WARNING: If you have a file with this name it will be overwritten.\n");
                scanf("%s", &nameOut);
                ptrOut = fopen(nameOut, "w");
                break;
            default:
                printf("Invalid Choice! Plot data was not written to file\n");
                return 1;
        }

        //The print information
        //Prints out the initial constants
        fprintf(ptrOut, "\nAverage flood discharge per unit width: \t\t\t%lf\t[m^2/s]\n", qwave);
        fprintf(ptrOut, "Average sediment volume feed per unit width during floods: \t\t\t%lf\t[m^2/s]\n", qbToave);
        fprintf(ptrOut, "Initial surface geometric mean size: \t\t\t%lf\t[mm]\n", dsgsi);
        fprintf(ptrOut, "Substrate geometric mean size: \t\t\t%lf\t[mm]\n", dsgsub);
        fprintf(ptrOut, "Mean annual sediment feed rate: \t\t\t%lf\t[Mt/m/a]\n", LoadAnn);
        fprintf(ptrOut, "\n");
        
        //This prints out the eta, slope, dsg, dlg, and load ratios
        fprintf(ptrOut, "\n\nPlot Data:\n\n\t");
        fprintf(ptrOut, "elev(m)\tS\tDsg(mm)\t");
        for (i=1; i <= prints; i++) {
            fprintf(ptrOut, "elev(m)\tS\tDsg(mm)\tDlg(mm)\tqbT/qbo\t");
        }
        fprintf(ptrOut, "\n");
        fprintf(ptrOut, "x(m)\t");
        fprintf(ptrOut, "%.0lfyr\t%.0lfyr\t%.0lfyr\t", printmatrix[0][0], Smatrix[0][0], dsgmatrix[0][0]);
        for (i=1; i <= prints; i++) {
            fprintf(ptrOut, "%.0lfyr\t%.0lfyr\t%.0lfyr\t%.0lfyr\t%.0lfyr\t", printmatrix[i][0], Smatrix[i][0], dsgmatrix[i][0], qbTmatrix[i][0], dlgmatrix[i][0]);
        }
        fprintf(ptrOut, "final w.s.");
        fprintf(ptrOut, "\n\n");
        for (j=1; j <= (M+1); j++) {
            fprintf(ptrOut, "%lf\t", x[j]);
            fprintf(ptrOut, "%lf\t%lf\t%lf\t", printmatrix[0][j], Smatrix[0][j], dsgmatrix[0][j]);
            for (i=1; i <= prints; i++) {
                fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t%lf\t", printmatrix[i][j], Smatrix[i][j], dsgmatrix[i][j], dlgmatrix[i][j], qbTmatrix[i][j]);
            }
            fprintf(ptrOut, "%lf", (etaendcyc[j] + H[j]));
            fprintf(ptrOut, "\n");
        }
        fprintf(ptrOut, "\n\n");
        
        //Prints the final max and end values
        fprintf(ptrOut, "Hmax\tHend\ttaumax\ttauend\tdsgsmax\tdsgsend\tdsglmax\tdsglend\n");
        for (j=1; j <= (M+1); j++) {
            fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", Hflowmax[j], Hflowend[j], tausgflowmax[j], tausgflowend[j], dsgsflowmax[j], dsgsflowend[j], dsglflowmax[j], dsglflowend[j]);
        }
        fprintf(ptrOut, "\n");
    
        //Prints out the final distribution        
        fprintf(ptrOut, "grain size (mm)\tfeed\tdsmaxflow\tdsendflow\tdslmaxflow\tdslendflow\n");
        for (i=1; i <= npp; i++) {
            fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", GSD[i].di, GSD[i].plff, Ffinerflowmaxds[i], Ffinerflowendds[i], plfinerflowmaxds[i], plfinerflowendds[i]);
        }
        fprintf(ptrOut, "\n");
        
        //Prints out the Hydrograph
        fprintf(ptrOut, "Hydrograph:\n");
        fprintf(ptrOut, "time(days)\tqw[m^2/s]\tqbTo[m^2/s]\tqbTf[m^2/s]\n");
        for (i=1; i <= totstep; i++) {
            fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\n", dayforprint[i], qwforprint[i], qbToforprint[i], qbTfforprint[i]);
        }

    
    //Finalize
    fclose(ptrOut);
    printf("Your file has been written. \n");
    return 0;
}

