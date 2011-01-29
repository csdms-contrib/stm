/*
 *  ReadIn.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/26/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

typedef struct {
    double qw;
    double qbTf;
    int nstep;
} triple;

int ReadIn(quad GSD[], triple hydro[], int *ncyc, double *etad, double *S, double *L,
           int *M, int *prints, int *iterates, double *nk, double *na, double *alphar,
           double *R, double *lps, double *alphau, double *atrans, int *npp, int *np,
           int *ndisc, double *dtflood, double *dx, int *totstep) {
    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    double temp=0, temp1=0, temp2=0, temp3=0, temp4=0;
    int i=0, check=0;

    //Run
    
        //Opens file for reading
        
        printf("Please enter the name of your input file\n(has to be a *.txt file)\n");
        scanf("%s", &nameIn);
        ptrIn = fopen(nameIn, "r");
        if (ptrIn == NULL) {
            printf("Error! Input file does not exist.  Make sure file is in proper folder.\n");
            return 1;
        }
        
        //Reads in 16 constant values
        
        for(i=0; i <= 15; i++) {
            fscanf(ptrIn, "%c  %lf\n", &indicator, &temp);
            switch (indicator) {
                case 'N':
                        *ndisc = temp;
                        break;
                case 'c':
                        *ncyc = temp;
                        break;
                case 'e':
                        *etad = temp;
                        break;
                case 'S':
                        *S = temp;
                        break;
                case 'L':
                        *L = temp;
                        break;
                case 't':
                        *dtflood = temp;
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
                case 'k':
                        *nk = temp;
                        break;
                case 'n':
                        *na = temp;
                        break;
                case 'r':
                        *alphar = temp;
                        break;
                case 'R':
                        *R = temp;
                        break;
                case 'l':
                        *lps = temp;
                        break;
                case 'u':
                        *alphau = temp;
                        break;
                case 'a':
                        *atrans = temp;
                        break;
                default:
                        printf("Error! Wrong alphabetical indicator, please see 'Key for Inputs' \n");
                        break;
            }
        }
        
        //Reads in the Hydrograph
        
        for (i=1; i <= *ndisc; i++) {
            fscanf(ptrIn, "%lf  %lf  %lf\n", &temp1, &temp2, &temp3);
            hydro[i].qw = temp1;
            hydro[i].qbTf = temp2;
            hydro[i].nstep = temp3;
        }
        
        i=1;
        while (EOF != fscanf(ptrIn, "%lf  %lf  %lf  %lf\n", &temp1, &temp2, &temp3, &temp4)) {
            GSD[i].di = temp1;
            GSD[i].plff = temp2;
            GSD[i].Ffl = temp3;
            GSD[i].Ffs = temp4;
            i++;
        }
        
        //CALCULATION OF CONSTANTS
            
            //Calculates npp and np
            *npp = i-1;
            *np = *npp - 1;
            
            //Calculates dx
            *dx = *L/(*M);
            
            //Scales the GSD values up to 0-100 scale if they are not already
            for(i=1; i <= *npp; i++) {
                if (GSD[i].plff <= 1.01)
                    check++;
                }
                if (check == (*npp)) {
                    for (i=1; i <= *npp; i++){
                    GSD[i].plff = GSD[i].plff*100;
                    }
                }
            check = 0;
            
            for(i=1; i <= *npp; i++) {
                if (GSD[i].Ffl <= 1.01)
                    check++;
                }
                if (check == (*npp)) {
                    for (i=1; i <= *npp; i++){
                    GSD[i].Ffl = GSD[i].Ffl*100;
                    }
                }
            check = 0;
            
            for(i=1; i <= *npp; i++) {
                if (GSD[i].Ffs <= 1.01)
                    check++;
                }
                if (check == (*npp)) {
                    for (i=1; i <= *npp; i++){
                    GSD[i].Ffs = GSD[i].Ffs*100;
                    }
                }
                
            //Calculates totstep
            *totstep = hydro[1].nstep;
            for (i=2; i <= *ndisc; i++) {
                *totstep += hydro[i].nstep;
            }
        
    //Finalize
    fclose(ptrIn);
    return 0;
}
