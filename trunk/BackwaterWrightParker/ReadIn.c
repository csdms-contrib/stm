/*
 *  ReadIn.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *Sl, double *R, double *D50s, double *D90s, double *B, double *Qw,
    double *ksid, double *L, int *M, double *qw, double *dx) {

    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    double Fr=0, temp=0;
    
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
            case 'B':
                    *B = temp;
                    break;
            case 'Q':
                    *Qw = temp;
                    break;
            case 'k':
                    *ksid = temp;
                    break;
            case 'L':
                    *L = temp;
                    break;
            case 'M':
                    *M = temp;
                    break;
            default:
                    printf("Not a valid entry, pleade edit file and try again.\n");
                    return 1;
        }
    }

    //Calculates extra constants
    *qw = (*Qw)/(*B);
    *D50s = (*D50s)/1000;
    *D90s = (*D90s)/1000;
    *dx = (*L)/(*M);
    
    //Checks that Froude Number is < 1
    Fr = (*Qw)/((*B)*(*ksid)*sqrt(9.81*(*ksid)));
    if (Fr >= 1) {
        printf("Please choose a downstream water elevation such that the Froude number is less than 1.\n");
        printf("Your current downstream Froude number is: %lf", Fr);
        return 1;
    }
    
    //Finalize
    return 0;
}