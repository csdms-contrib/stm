/*
 *  ReadIn.c
 *  AgDegNormal
 *
 *  Created by Andrew Leman on 6/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>

int ReadIn(float *Qf, float *If, float *B, float *D, float *lamdap, float *kc,
        float *S, float *Gtf, float *L, float *dt, int *iterate, int *prints,
        int *M, float *alphau, float *alphar, float *alphat, float *nt,
        float *tauc, float *phis, float *R, float *Cf, int *formulation) {
    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    float temp=0;
    
    //Run
    printf("Please enter the name of your input file\n(has to be a *.txt file)\n");
    scanf("%s", &nameIn);
    ptrIn = fopen(nameIn, "r");
    if (ptrIn == NULL) {
        printf("Error! Input file does not exist. Make sure file is in proper folder.\n");
        return 1;
    }
    
    while (EOF != fscanf(ptrIn, "%c   %f\n", &indicator, &temp)) {
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
                    *D = temp;
                    break;
            case 'l':
                    *lamdap = temp;
                    break;
            case 'k':
                    *kc = temp;
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
                    *dt = temp;
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
    
    //Finalize
    fclose(ptrIn);
    return 0;

}