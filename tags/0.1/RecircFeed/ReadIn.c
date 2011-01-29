/*
 *  ReadIn.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *Fro, double *nt, double *Fl, double *etatilainit, double *taur,
    double *SNl, int *M, double *dt, int *prints, int *iterates, int *Nreach,
    double *dxhat, double *Nhalf, double *qw, double *Ntot, double *qtilg) {

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
            case 'F':
                    *Fro = temp;
                    break;
            case 'n':
                    *nt = temp;
                    break;
            case 'f':
                    *Fl = temp;
                    break;
            case 'e':
                    *etatilainit = temp;
                    break;
            case 'T':
                    *taur = temp;
                    break;
            case 'S':
                    *SNl = temp;
                    break;
            case 'M':
                    *M = temp;
                    break;
            case 't':
                    *dt = temp;
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
    
    //Check that Froude is less than 1
    if (*Fro >= 1) {
        printf("Froude number must be less than 1.  Edit input and try again.\n");
        return 1;
    }

    //Calculation of constants
    *Nreach = (*M + 1);
    *dxhat = 1.0/((*Nreach) - 1.0);
    *Nhalf = *Nreach/2.0;
    *qw = 1.0;
    *Ntot = 0;
    *qtilg = 1.0;
    
    //Finalize
    fclose(ptrIn);
    return 0;
}