/*
 *  ReadIn.c
 *  AgDegNormalFault
 *
 *  Created by Andrew Leman on 6/8/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int ReadIn(double *Qf, double *If, double *B, double *D, double *lamdap, double *kc,
        double *S, double *Gtf, double *L, double *dt, int *iterate, int *prints,
        int *M, double *alphau, double *alphar, double *alphat, double *nt,
        double *tauc, double *phis, double *R, double *Cf, int *formulation, double *rf,
        double *deltaeta, double *tf, double *dx, double *Slmin) {
    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    double temp=0;
    
    //Run
    printf("Please enter the name of your input file\n(has to be a *.txt file)\n");
    scanf("%s", &nameIn);
    ptrIn = fopen(nameIn, "r");
    if (ptrIn == NULL) {
        printf("Error! Input file does not exist. Make sure file is in proper folder.\n");
        return 1;
    }
    
    while (EOF != fscanf(ptrIn, "%c   %lf\n", &indicator, &temp)) {
        switch (indicator) {
            case 'Q':
                    *Qf = temp;
                    break;
            case 'I':
                    *If = temp;
                    break;
            case 'B':
                    *B = temp;
                    break;
            case 'D':
                    *D = temp/1000;
                    break;
            case 'l':
                    *lamdap = temp;
                    break;
            case 'k':
                    *kc = temp/1000;
                    //automatically does the Manning Strickler formulation
                    *formulation += 1;
                    break;
            case 'S':
                    *S = temp;
                    break;
            case 'G':
                    *Gtf = temp;
                    break;
            case 'L':
                    *L = temp;
                    break;
            case 't':
                    *dt = temp*3600*24*365.25;
                    break;
            case 'i':
                    *iterate = temp;
                    break;
            case 'p':
                    *prints = temp;
                    break;
            case 'M':
                    *M = temp;
                    break;
            case 'u':
                    *alphau = temp;
                    break;
            case 'r':
                    *alphar = temp;
                    break;
            case 'a':
                    *alphat = temp;
                    break;
            case 'n':
                    *nt = temp;
                    break;
            case 'T':
                    *tauc = temp;
                    break;
            case 'P':
                    *phis = temp;
                    break;
            case 'R':
                    *R = temp;
                    break;
            case 'd':
                    *deltaeta = temp;
                    break;
            case 'f':
                    *rf = temp;
                    break;
            case 'F':
                    *tf = temp;
                    break;
            case 'C':
                    *Cf = temp;
                    //automatically does the Chézy formulation
                    *formulation += 2;
                    break;
            default:
                    printf("Not a valid entry, please edit file and try again.\n");
                    fclose(ptrIn);
                    return 1;
        }
    }
    //a formulation value of 1 is Manning Strickler and 2 for Chézy
    if (*formulation > 2) {
        printf("Would you like to use:\n");
        printf("1. Manning Strickler Formulation\n2. Chezy Formulation\n");
        scanf("%i", &formulation);
    }
    
    //calculate dx and Slmin
    *dx = (*L)/((*M)*1.0);
    *Slmin = pow(((*tauc)*(*R)*(*D)), (10.0/7.0))*pow(((*alphar)*(*B)*(*B)*(g)/(cbrt(*kc)*(*Qf)*(*Qf))), (3.0/7.0));
    
    //Finalize
    fclose(ptrIn);
    return 0;

}
