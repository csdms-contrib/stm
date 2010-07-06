/*
 *  Finalize.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

typedef struct {
    double qw;
    double qbTf;
    int nstep;
} triple;

int PrintDatatoFile(FILE *, double [][101], double [], int, int);
int WriteOut(quad [], char [], int, int, int, double [][101], double [][101], double [][101],
        double [], double [], double [][16], double [][16], double [][101], double [][101],
        double [], double [], double [], double [], double [], double [], double [], double [],
        double [], double [], double [], double [], double [], int, double [], double [], double [],
        double [], double, double, double, double, double);
int GetData(double [][101], double [][101], double [][101], double [][101], double [][101],
        double [][101], double [][101], double [], int, int, double);

int Finalize(quad GSD[], double printmatrix[][101], double dsgmatrix[][101], double qbTmatrix[][101], double tausgmatrix[][101],
    double Smatrix[][101], double dlgmatrix[][101], double Hmatrix[][101], double F[][16], double pl[][16], double H[],
    double D90matrix[][101], double x[], double etaendcyc[], double Hflowmax[], double Hflowend[], double tausgflowmax[],
    double tausgflowend[], double dsgsflowmax[], double dsgsflowend[], double dsglflowmax[],
    double dsglflowend[], double Ffinerflowmaxds[], double Ffinerflowendds[], double plfinerflowmaxds[],
    double plfinerflowendds[], int totstep, double qbTfforprint[], double dayforprint[],
    double qwforprint[], double qbToforprint[], double qwave, double qbToave, double Dsgsi,
    double Dsgsub, double LoadAnn, int M, int prints, int npp) {

    //Declarations
    FILE * ptrOut1;
    char nameOut1[50];

    //Open file for printing data
        printf("What do you want to call the output file? (less than 50 characters please)\n");
        printf("WARNING: If you have a file with this name it will be overwritten.\n");
        scanf("%s", &nameOut1);
        ptrOut1 = fopen(nameOut1, "w");
        
    //Writes data to File
        PrintDatatoFile(ptrOut1, printmatrix, x, M, prints);
        
        fclose(ptrOut1);
        
    //Writes graph data and constants to a file or appends them
        WriteOut(GSD, nameOut1, prints, M, npp, printmatrix, dsgmatrix, qbTmatrix, x, H, F, pl,
            Smatrix, dlgmatrix, etaendcyc, Hflowmax, Hflowend, tausgflowmax, tausgflowend,
            dsgsflowmax, dsgsflowend, dsglflowmax, dsglflowend, Ffinerflowmaxds, Ffinerflowendds,
            plfinerflowmaxds, plfinerflowendds, totstep, qbTfforprint, dayforprint, qwforprint,
            qbToforprint, qwave, qbToave, Dsgsi, Dsgsub, LoadAnn);
            
    //Prints extra information at user defined time
        GetData(printmatrix, Smatrix, Hmatrix, tausgmatrix, qbTmatrix, dsgmatrix,
            D90matrix, x, M, prints, qbToave);

    return 0;

}