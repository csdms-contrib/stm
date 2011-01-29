/*
 *  ReadIn.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

double Rf(double);

int ReadIn(double zeta[], double *Qww, double *I, double *B, double *D50, double *D90,
    double *R, double *S, double *lamdap, double *L, double *Hslot, double *ru,
    double *rd, double *au, double *dt, double *qw, double *dx, double *Rep,
    double *vs, double *dzeta, int *M, int *iterates, int *prints) {

    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    int i=0;
    double temp=0, nu=0.000001, zetab=0.05, nconc=50;
    
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
            case 'Q':
                    *Qww = temp;
                    break;
            case 'I':
                    *I = temp;
                    break;
            case 'B':
                    *B = temp;
                    break;
            case 'd':
                    *D50 = temp/1000;
                    break;
            case 'D':
                    *D90 = temp/1000;
                    break;
            case 'R':
                    *R = temp;
                    break;
            case 'S':
                    *S = temp;
                    break;
            case 'L':
                    *L = temp;
                    break;
            case 'H':
                    *Hslot = temp;
                    break;
            case 'u':
                    *ru = temp;
                    break;
            case 'r':
                    *rd = temp;
                    break;
            case 'l':
                    *lamdap = temp;
                    break;
            case 'a':
                    *au = temp;
                    break;
            case 'M':
                    *M = temp;
                    break;
            case 't':
                    *dt = temp*31557600;
                    break;
            case 'i':
                    *iterates = temp;
                    break;
            case 'p':
                    *prints = temp;
                    break;
            default:
                    printf("Not a valid entry, please edit file and try again.\n");
                    return 1;
        }
    }
    
    //Calculation of constants
    *dx = *L/(*M);
    *qw = *Qww/(*B);
    *Rep = sqrt(*R*(*D50)*g)*(*D50)/(nu);
    *vs = sqrt(*R*(*D50)*g)*Rf(*Rep);
    *dzeta = (1.0 - zetab)/nconc;
    for (i=1; i <= (nconc+1); i++) {
        zeta[i] = zetab + (i-1)*(*dzeta);
    }
    
    //Finalize
    fclose(ptrIn);
    return 0;
}