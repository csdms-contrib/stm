/*
 *  ReadIn.c
 *  SteadyStateAg
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *Gt, double *L, double *ksidot, double *Qbf, double *B, double *D,
    double *Lamda, double *tauform, double *aleh, double *lamdap, double *Cz, double *I,
    double *Cf, double *Omega, double *R, double *ksid, double *dt, double *Qt,
    double *C, double *BMSS, double *Su, double *beta, int *prints) {

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
            case 'G':
                    *Gt = temp;
                    break;
            case 'L':
                    *L = temp;
                    break;
            case 'x':
                    *ksidot = temp;
                    break;
            case 'Q':
                    *Qbf = temp;
                    break;
            case 'B':
                    *B = temp;
                    break;
            case 'D':
                    *D = temp;
                    break;
            case 'V':
                    *Lamda = temp;
                    break;
            case 'T':
                    *tauform = temp;
                    break;
            case 'a':
                    *aleh = temp;
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
                    *Omega = temp;
                    break;
            case 'R':
                    *R = temp;
                    break;
            case 'X':
                    *ksid = temp;
                    break;
            case 't':
                    *dt = temp;
                    break;
            case 'p':
                    *prints = temp;
                    break;
            default:
                    printf("Not a valid entry, pleade edit file and try again.\n");
                    return 1;
        }
    }
    
    //Calculation of constants
    *Cf = 1.0/pow(*Cz, 2);
    *Qt = *Gt*1000000/(31557600*(*R+1.0)*(*I));
    *C = *Qt/(*Qt + *Qbf);
    *BMSS = (*R + 1.0)*(*Qt)*1000000/(*Qt + *Qbf);
    *Su = *R*sqrt(*Cf)*(*Qt)/(*aleh*(*tauform)*(*Qbf));
    *beta = (1.0 - *lamdap)*(*B*1000)*((*ksidot/1000)/31557600)*(1000*(*L))/(*I*(*Omega)*(*Qt)*(1.0 + *Lamda));
    
    if (*beta >= 1) {
        printf("Adjust L such that the beta parameter is below 1.\nIf beta is greater than 1, the sediment does not reach the delta.\nbeta = %lf", *beta);
        return 1;
    }
    
    //Finalize
    fclose(ptrIn);
    return 0;
}
