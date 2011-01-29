/*
 *  ReadIn.c
 *  1DDeltaNorm
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *qw, double *I, double *qtf, double *D, double *Cz, double *nt,
    double *tsc, double *etasl, double *etabl, double *Sfi, double *Sb, double *ssfi,
    double *Sa, double *R, double *lamdap, double *ks, double *alphat, double *alphar,
    double *dt, double *dxbar, int *M, int *prints, int *iterates, int *formulation) {

    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    double temp=0;
    int check=0;
    
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
                    (*formulation)++;
                    break;
            case 'n':
                    *nt = temp;
                    break;
            case 'T':
                    *tsc = temp;
                    break;
            case 'E':
                    *etasl = temp;
                    break;
            case 'e':
                    *etabl = temp;
                    break;
            case 'f':
                    *Sfi = temp;
                    break;
            case 'b':
                    *Sb = temp;
                    break;
            case 's':
                    *ssfi = temp;
                    break;
            case 'S':
                    *Sa = temp;
                    break;
            case 'R':
                    *R = temp;
                    break;
            case 'L':
                    *lamdap = temp;
                    break;
            case 'k':
                    *ks = temp/1000;
                    *formulation += 2;
                    break;
            case 'a':
                    *alphat = temp;
                    break;
            case 'r':
                    *alphar = temp;
                    check = 1;
                    break;
            case 'M':
                    *M = temp;
                    break;
            case 't':
                    *dt = temp*86400;
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
    
    
    //Choose Chezy or Manning Strickler if both coefficients are present
    if ((*formulation == 2) && (check == 0)) {
        printf("Error! Both the ks and alphar values must be present for a Manning Strickler formulation\n");
        return 1;
    }
    else if ((*formulation == 3) && (check == 0)) {
        *formulation = 1;
    }
    
    if (*formulation > 2) {
        printf("Would you like to use a\n1. Chezy formulation\n2. Manning Strickler formulation\n");
        scanf("%i", &(*formulation));
        if ((*formulation != 1) && (*formulation != 2)) {
            printf("Improper response, please restart the program and try again.\n");
            return 1;
        }
        else if ((*formulation == 2) && (check == 0)) {
            printf("Error! Both the ks and alphar values must be present for a Manning Strickler formulation\n");
            return 1;
        }
    }
    
    //Calculation of constants
    *dxbar = 1.0/(*M);
    
    //Finalize
    fclose(ptrIn);
    return 0;
}
