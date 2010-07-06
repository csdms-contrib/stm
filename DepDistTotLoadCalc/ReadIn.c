/*
 *  ReadIn.c
 *  DepDistTotLoadCalc
 *
 *  Created by Andrew Leman on 7/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *Sl, double *R, double *D50s, double *D90s, double *nk, double *Hso,
    double *Hstep, int *N, double *astrat, double *nu, double *ks) {

    //Initialize
    double temp=0;
    FILE *ptrIn;
    char nameIn[50], indicator;
    
    //Run
    printf("Please enter the name of your input file.\n(has to be a *.txt file)\n");
    scanf("%s", nameIn);
    ptrIn = fopen(nameIn, "r");
    if (ptrIn == NULL) {
        printf("Error! Input file does not exist. Make sure file is in proper folder. \n");
        return 1;
    }

    while (EOF != fscanf(ptrIn, "%s  %lf\n", &indicator, &temp)) {
        switch (indicator) {
            case 'S':
                    *Sl = temp;
                    break;
            case 'R':
                    *R = temp;
                    break;
            case 'd':
                    *D50s = temp;
                    break;
            case 'D':
                    *D90s = temp;
                    break;
            case 'n':
                    *nk = temp;
                    break;
            case 'H':
                    *Hso = temp;
                    break;
            case 's':
                    *Hstep = temp;
                    break;
            case 'N':
                    *N = temp;
                    break;
            case 'v':
                    *nu = temp;
                    break;
            case 'a':
                    *astrat = temp;
                    break;
            default:
                    printf("Not a valid entry, pleade edit file and try again.\n");
                    return 1;
        }
    }
    
    //Calculates ks
    *ks = (*nk)*(*D90s);
    
    //Finalize
    fclose(ptrIn);
    return 0;
}