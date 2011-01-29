/*
 *  Finalize.c
 *  AgDegBW
 *
 *  Created by Andrew Leman on 7/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int PrintDatatoFile(FILE *, double [][101], double [][101], double [][101], double [],
            int, int);
int WriteOut(float, float, float, float, float, float, float, float, float, float,
            float, float, float, float, char []);
int GetData(double [][101], double [][101], double [][101], double [][101], double [][101],
            double [][101], double [], int, int);

int Finalize(double printmatrix[][101], double Hmatrix[][101], double ksimatrix[][101],
    double x[], int M, int prints, float Ha, float taustar, float qstar, float qt,
    float Gt, float qtf, float tauult, float Sult, float Hult, double Frni, double Frnu,
    double Hc, double ksimin, double ksiinit, double Slmatrix[][101], double taumatrix[][101],
    double qbmatrix[][101]) {

    //Declarations
    FILE *ptrOut1;
    char nameOut1[50];

    //Open file for printing data
    printf("What do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut1);
    ptrOut1 = fopen(nameOut1, "w");
    
    //Prints Data Out
    PrintDatatoFile(ptrOut1, printmatrix, Hmatrix, ksimatrix, x, M, prints);
    
    //Close file that was printed to
    fclose(ptrOut1);
    
    //Writes Constants to new file or appends to old
    WriteOut(Ha, taustar, qstar, qt, Gt, qtf, tauult, Sult, Hult, Frni, Frnu, Hc, ksimin, ksiinit, nameOut1);
    
    //Prints user selected time in more depth
    GetData(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix, ksimatrix, x, M, prints);
    return 0;

}