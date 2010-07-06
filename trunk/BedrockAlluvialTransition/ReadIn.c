/*
 *  ReadIn.c
 *  BedrockAlluvialTransition
 *
 *  Created by Andrew Leman on 7/14/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *qw, double *I, double *qtf, double *D, double *Cz, double *Sbase,
    double *Sfinit, double *sd, int *M, double *dt, int *prints, int *iterates,
    double *dxbar, double *alphas, double *R, double *lamdap) {

    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    double temp=0;
    
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
            case 'q':
                    *qw = temp;
                    break;
            case 'I':
                    *I = temp;
                    break;
            case 'Q':
                    *qtf = temp;
                    break;
            case 'D':
                    *D = temp/1000;
                    break;
            case 'C':
                    *Cz = temp;
                    break;
            case 'b':
                    *Sbase = temp;
                    break;
            case 'S':
                    *Sfinit = temp;
                    break;
            case 'd':
                    *sd = temp;
                    break;
            case 'R':
                    *R = temp;
                    break;
            case 'L':
                    *lamdap = temp;
                    break;
            case 'M':
                    *M = temp;
                    break;
            case 't':
                    *dt = temp*31557600;
                    break;
            case 'p':
                    *prints = temp;
                    break;
            case 'i':
                    *iterates = temp;
                    break;
            default:
                    printf("Not a valid entry, pleade edit file and try again.\n");
                    return 1;
        }
    }
    
    //Calculation of constants
    *dxbar = 1.0/(*M);
    *alphas = 0.05*pow((*Cz), 2);
    
    //Finalize
    fclose(ptrIn);
    return 0;
}