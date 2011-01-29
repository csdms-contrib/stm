/*
 *  ReadIn.c
 *  1DRiverWFRisingBaseLevelNormal
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double Qt[], double Sl[], double *Qf, double *Qbtffeed, double *lambig,
    double *I, double *D, double *R, double *L, double *Bf, double *Sinu, double *lamp,
    double *Cz, double *Sfbl, double *etaddot, int *M, int *prints, int *iterates, double *dt,
    double *Yearstart, double *Yearstop, double *aleh, double *neh, double *tausforms,
    double *alp, double *np, double *tausc, double *tausformg, double *Cf, double *rform,
    double *tausform, double *loadcoef, double *widthcoef, double *depthcoef, double *dx) {
    
    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    double temp=0;
    
    //Run
    printf("Please enter the name of your input file\n(has to be a *.txt file)\n");
    scanf("%s", nameIn);
    ptrIn = fopen(nameIn, "r");
    if (ptrIn == NULL) {
        printf("Error! Input file does not exist. Make sure file is in proper folder. \n");
        return 1;
    }
    
    while (EOF != fscanf(ptrIn, "%s  %lf\n", &indicator, &temp)) {
        switch (indicator) {
            case 'Q':
                    *Qf = temp;
                    break;
            case 'q':
                    *Qbtffeed = temp;
                    break;
            case 'V':
                    *lambig = temp;
                    break;
            case 'I':
                    *I = temp;
                    break;
            case 'D':
                    *D = temp;
                    break;
            case 'R':
                    *R = temp;
                    break;
            case 'L':
                    *L = temp;
                    break;
            case 'B':
                    *Bf = temp;
                    break;
            case 'O':
                    *Sinu = temp;
                    break;
            case 'l':
                    *lamp = temp;
                    break;
            case 'C':
                    *Cz = temp;
                    break;
            case 'S':
                    *Sfbl = temp;
                    break;
            case 'e':
                    *etaddot = temp;
                    break;
            case 'M':
                    *M = temp;
                    break;
            case 'p':
                    *prints = temp;
                    break;
            case 'i':
                    *iterates = temp;
                    break;
            case 't':
                    *dt = temp;
                    break;
            case 'y':
                    *Yearstart = temp;
                    break;
            case 'Y':
                    *Yearstop = temp;
                    break;
            case 'a':
                    *aleh = temp;
                    break;
            case 'n':
                    *neh = temp;
                    break;
            case 'T':
                    *tausforms = temp;
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
                    *tausformg = temp;
                    break;
            default:
                    printf("Not a valid entry, pleade edit file and try again.\n");
                    return 1;
        }
    }
    
    //Calculation of constants
    *Cf = 1/((*Cz)*(*Cz));
    *rform = pow((1 - (*tausc)/(*tausformg)), 4.5);
    *dt = (*dt)*31557600;
    if ((*D) < 2) {
        *tausform = *tausforms;
        *loadcoef = (*aleh)*(*tausform)/((*R)*sqrt(*Cf));
        *widthcoef = (*Cf)/((*aleh)*pow((*tausform), 2.5)*sqrt(*R));
        *depthcoef = (*aleh)*pow((*tausform), 2)/(sqrt(*Cf));
    }
    else {
        *tausform = *tausformg;
        *loadcoef = (*alp)*(*rform)*sqrt(*Cf)/(*R);
        *widthcoef = 1/((*alp)*(*rform)*pow((*tausform), 1.5)*sqrt(*R));
        *depthcoef = (*alp)*(*tausform)*(*rform)*(sqrt(*Cf));
    }
    *D = *D/1000;
    *dx = (*L)/(*M);
    Qt[1] = *Qbtffeed;
    Sl[(*M)+1] = 0;
    *etaddot = *etaddot/(1000.0)/(31557600.0);
    *Yearstart = *Yearstart*31557600;
    *Yearstop = *Yearstop*31557600;
    
    //Finalize
    fclose(ptrIn);
    return 0;
}