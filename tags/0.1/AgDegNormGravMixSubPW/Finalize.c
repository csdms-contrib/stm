/*
 *  Finalize.c
 *  AgDegNormGravMixSubPW
 *
 *  Created by Andrew Leman on 7/7/09.
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

int PrintDatatoFile(FILE *, double [][101], double [], int, int);
int WriteOut(quad [], char [], int, int, int, double [][101], double [][101], double[][101], double [],
        double [], double [][21], double [][21]);
int GetData(double [][101], double [][101], double [][101], double [][101], double [][101],
        double [][101], double [][101], double [], double, int, int);

int Finalize(double printmatrix[][101], double x[], int M, int prints, quad GSD[], int npp,
    double dsgmatrix[][101], double qbTmatrix[][101], double H[], double F[][21], double pl[][21],
    double Slmatrix[][101], double Hmatrix[][101], double tausgmatrix[][101], double D90matrix[][101],
    double qbTf) {

    //Declarations
    FILE * ptrOut1;
    char nameOut1[50];

     //Open file for printing data
    printf("What do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten. \n");
    scanf("%s", &nameOut1);
    ptrOut1 = fopen(nameOut1, "w");
        
    //Prints data to that file
    PrintDatatoFile(ptrOut1, printmatrix, x, M, prints);
    
    fclose(ptrOut1);
    
    //Writes out the plot data
    WriteOut(GSD, nameOut1, prints, M, npp, printmatrix, dsgmatrix, qbTmatrix, x, H, F, pl);
    
    //Prints extra information at user defined point in time
    GetData(printmatrix, Slmatrix, Hmatrix, tausgmatrix, qbTmatrix, dsgmatrix, D90matrix, x, qbTf, M, prints);
    
    return 0;

}