/*
 *  Finalize.c
 *  AgDegNormalSub
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Deparmtent.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int PrintDatatoFile(FILE *, double [][101], double [][101], double [][101], double [], int, int, float);
int GetData(double [][101], double [][101], double [][101], double [][101], double [][101], double [], int, int);

int Finalize(double printmatrix[][101], double Slmatrix[][101], double qbmatrix[][101],
    double Hmatrix[][101], double taumatrix[][101], double x[], int M, int prints, float qtf) {

    //Declarations
    char nameOut1[50];
    FILE * ptrOut1;

    //Open file for printing
        
    printf("What do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut1);
    ptrOut1 = fopen(nameOut1, "w");
    
    //Prints data to file and closes
    PrintDatatoFile(ptrOut1, printmatrix, Slmatrix, qbmatrix, x, M, prints, qtf);
    printf("Your file has been written. \n");
    fclose(ptrOut1);

    //Prints more information on a user chosen point in time
    GetData(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix, x, M, prints);

    return 0;

}