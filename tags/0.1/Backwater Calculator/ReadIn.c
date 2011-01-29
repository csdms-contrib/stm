/*
 *  ReadIn.c
 *  Backwater Calculator
 *
 *  Created by Andrew Leman on 5/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>

int ReadIn(float *S, float *Cz, float *qw, float *R, float *Dmean, float *Ds90,
    float *nk, float *alphar, float *x, float *step, float *initdepth, int *formulation) {
    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    float temp=0;
    int terms=0, checkC=0, checkMS=0;

    //Run
    //reads in and opens the file the user selects
    printf("Please enter the name of your input file\n(has to be a *.txt file)\n");
    scanf("%s", &nameIn);
    ptrIn = fopen(nameIn, "r");
    //checks to make sure file is valid and opened
    if(ptrIn == NULL) {
        printf("Error! Input file does not exist.  Make sure file is in proper folder.\n");
        return 0;
    }
    //reads values into their respective constants, such that input file
    //can have them in any order
    while (EOF != fscanf(ptrIn, "%s  %f\n", &indicator, &temp)) {
        terms++;
        switch (indicator) {
            case 'S':
                    *S = temp;
                    break;
            case 'C':
                    *Cz = temp;
                    checkC = 1;
                    break;
            case 'q':
                    *qw = temp;
                    break;
            case 'R':
                    *R = temp;
                    break;
            case 'M':
                    *Dmean = temp/1000;
                    break;
            case 'D':
                    *Ds90 = temp/1000;
                    checkMS = 1;
                    break;
            case 'n':
                    *nk = temp;
                    break;
            case 'a':
                    *alphar = temp;
                    break;
            case 'x':
                    *x = temp;
                    break;
            case 'd':
                    *step = temp;
                    break;
            case 'H':
                    *initdepth = temp;
                    break;
            default:
                    printf("Not a valid entry, please edit file and try again.\n");
                    return 1;
        }
    }
    
    if ((checkC == 1) && (checkMS ==0)) {
        *formulation = 1;
    }
    else if ((checkMS == 1) && (checkC == 0)) {
        *formulation = 2;
    }
    else if ((checkMS == 1) && (checkC == 1)) {
        printf("Would you like to use a\n1. Chezy formulation\n2. Manning-Strickler formulation\n");
        scanf("%i", &(*formulation));
        if ((*formulation != 1) && (*formulation != 2)) {
            printf("Invalid response!\n");
            return 0;
        }
    }
    else {
        printf("ERROR! You are missing values needed for the Chezy formulation and the Manning-Strickler formulation.\n");
        return 0;
    }
    
    
    //Finalize
    fclose(ptrIn);
    return terms;
    
}