/*
 *  ReadIn.c
 *  SubsidingFan
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926

int ReadIn(double qb[], double Sl[], double *Qtfeed, double *Lb, double *Qbf, double *D,
    double *Lamda, double *theta, double *lamdap, double *I, double *Cz, double *Sinu,
    double *sigma, double *aleh, double *neh, double *tauforms, double *alp, double *np,
    double *tausc, double *tauformg, double *Cf, double *dx, double *Su, double *R,
    double *dt, double *loadcoef, int *M, int *iterates, int *prints) {

    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    double temp=0, rform=0;
    
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
                    *Qtfeed = temp;
                    break;
            case 'L':
                    *Lb = temp;
                    break;
            case 'Q':
                    *Qbf = temp;
                    break;
            case 'D':
                    *D = temp/1000;
                    break;
            case 'V':
                    *Lamda = temp;
                    break;
            case 'T':
                    *theta = (temp/360)*(2*pi);
                    break;
            case 'l':
                    *lamdap = temp;
                    break;
            case 'I':
                    *I = temp;
                    break;
            case 'C':
                    *Cz = temp;
                    break;
            case 'O':
                    *Sinu = temp;
                    break;
            case 's':
                    *sigma = (temp/1000)/31557600;
                    break;
            case 'a':
                    *aleh = temp;
                    break;
            case 'n':
                    *neh = temp;
                    break;
            case 'S':
                    *tauforms = temp;
                    break;
            case 'P':
                    *alp = temp;
                    break;
            case 'N':
                    *np = temp;
                    break;
            case 'c':
                    *tausc = temp;
                    break;
            case 'G':
                    *tauformg= temp;
                    break;
            case 'R':
                    *R = temp;
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
                    printf("Not a valid entry, pleade edit file and try again.\n");
                    return 1;
        }
    }
    
    //Calculation of Constants
    *Cf = 1.0/pow(*Cz, 2);
    rform = pow((1.0 - *tausc/(*tauformg)), 4.5);
    if ((1000*(*D)) < 2) {
        *loadcoef = *aleh*(*tauforms)/(*R*sqrt(*Cf));
    }
    else {
        *loadcoef = *alp*rform*sqrt(*Cf)/(*R);
    }
    *dx = *Lb/(*M);
    qb[1] = *Qtfeed;
    Sl[*M+1] = 0;
    *Su = (1.0/(*loadcoef))*(*Qtfeed)/(*Qbf);
    
    //Finalize
    fclose(ptrIn);
    return 0;
}

