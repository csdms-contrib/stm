/*
 *  Finalize.c
 *  AgDegNormal
 *
 *  Created by Andrew Leman on 7/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(float, float, float, float, float, float, float, float, float, char []);
int PrintDatatoFile(FILE *, double [][101], double [], int, int, float, float, float);
int GetData(double [][101], double [][101], double [][101], double [][101], double [][101],
        double [], int, int);

int Finalize(double printmatrix[][101], double x[], int M, int prints, float L, float dx,
    float Sult, float H, float taustar, float qstar, float qt, float Gt, float qtf,
    float tauult, float Hult, double Slmatrix[][101], double Hmatrix[][101],
    double taumatrix[][101], double qbmatrix[][101]) {

    //Declare variables
    FILE *ptrOut1;
    char nameOut1[50];

    //Open file for printing data
        
    printf("What do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut1);
    ptrOut1 = fopen(nameOut1, "w");
    
    //Prints data to file
    PrintDatatoFile(ptrOut1, printmatrix, x, M, prints, L, dx, Sult);
    
    //Closes File
    
    fclose(ptrOut1);
    
    //Write out equilibria constants to old file or appends to new
    
    WriteOut(H, taustar, qstar, qt, Gt, qtf, tauult, Sult, Hult, nameOut1);
    
    //Prints more information for a user-selected time
    GetData(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix, x, M, prints);
    return 0;

}