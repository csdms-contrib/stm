/*
 *  Finalize.c
 *  AgDegNormalFault
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int PrintDatatoFile(FILE *, double [][101], double [], int, int);
int WriteOut(double, double, double, double, double, double, double, char []);
int GetData(double [][101], double [][101], double [][101], double [][101], double [][101],
        double [], int, int);

int Finalize(double printmatrix[][101], double x[], int M, int prints, double H, double taustar,
    double qstar, double qt, double Gt, double qtg, double dx, double Slmatrix[][101],
    double Hmatrix[][101], double taumatrix[][101], double qbmatrix[][101]) {

    //Declaration
    char nameOut1[50];
    FILE *ptrOut1;

    //Open file for printing
        
    printf("What do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut1);
    ptrOut1 = fopen(nameOut1, "w");

    //Prints Data to File and closes the file
    PrintDatatoFile(ptrOut1, printmatrix, x, M, prints);
    fclose(ptrOut1);
    printf("Your file has been written. \n");

    //Write out Equilibrium Constants

    WriteOut(H, taustar, qstar, qt, Gt, qtg, dx, nameOut1);

    //Prints extra information for a user-defined point in time
    GetData(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix, x, M, prints);
    
    return 0;

}