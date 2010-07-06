/*
 *  ReadIn.c
 *  AgDegNormGravMixSubPW
 *
 *  Created by Andrew Leman on 7/7/09.
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

int ReadIn(quad GSD[], double *qw, double *qbTf, double *I,
           double *etad, double *S, double *L, double *dt, int *M, int *prints, int *iterates,
           double *nk, double *na, double *alphar, double *R, double *lps, double *alphau,
           double *atrans, int *npp, int *np, double *rload, double *Cexp, double *nexp,
           double *Sinu, double *subrate, double *lamda, double *rB, double *ExnerFactor,
           double *Cf, int *formulation) {
    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    double temp=0, temp1=0, temp2=0, temp3=0, temp4=0, Lmax=0;
        //CONSTANTS
        double tausc50 = 0.03, tausr50 = 0.04, aload = 11.2, nload = 4.5;
        int i=0, check=0, constants=20, choice=0;

    //Run
    
        //Opens file for reading
        
        printf("Please enter the name of your input file\n(has to be a *.txt file)\n");
        scanf("%s", &nameIn);
        ptrIn = fopen(nameIn, "r");
        if (ptrIn == NULL) {
            printf("Error! Input file does not exist.  Make sure file is in proper folder.\n");
            return 1;
        }
        
        //Reads in 21/22 constant values
        
        printf("If you have the input parameters for both the Chezy and the Manning-Strickler formulation in your input file enter 1 otherwise enter any other number.\n");
        scanf("%i", &choice);
        if (choice == 1) {
            constants++;
        }
        
        for(i=0; i <= constants; i++) {
            fscanf(ptrIn, "%c  %lf\n", &indicator, &temp);
            switch (indicator) {
                case 'q':
                        *qw = temp;
                        break;
                case 'T':
                        *qbTf = temp;
                        break;
                case 'I':
                        *I = temp;
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
                        *dt = temp*86400.0;
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
                        *formulation += 1;
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
                case 'O':
                        *Sinu = temp;
                        break;
                case 's':
                        *subrate = temp;
                        break;
                case 'B':
                        *rB = temp;
                        break;
                case 'V':
                        *lamda = temp;
                        break;
                case 'C':
                        *Cf = temp;
                        *formulation += 2;
                        break;
                default:
                        printf("Error! Wrong alphabetical indicator, please see 'Key for Inputs' \n");
                        return 1;
            }
        }
        
        if (*formulation > 2) {
            printf("Would you prefer to use a:\n1. Manning-Strickler formulation\n2. Chezy formulation\n");
            scanf("%i", &(*formulation));
            if ((*formulation != 1) && (*formulation != 2)) {
                printf("Improper response, please try again...");
                return 1;
            }
        }
        
        //Reads in the GSD Distributions
        
        i=1;
        while (EOF != fscanf(ptrIn, "%lf  %lf  %lf  %lf\n", &temp1, &temp2, &temp3, &temp4)) {
            GSD[i].di = temp1;
            GSD[i].plff = temp2;
            GSD[i].Ffl = temp3;
            GSD[i].Ffs = temp4;
            i++;
        }
        
        //CALCULATION OF CONSTANTS
            
            //Checks that the user has inputted exactly 12 diameter sizes
            *npp = i-1;
            *np = *npp - 1;
            if (*npp != 12) {
                printf("This program requires exactly 12 diameter sizes, see 'Key for Inputs' \n");
                return 1;
            }
            
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
        
            //Calculates rload which is constant, dependent on two other constants
            *rload = tausr50/tausc50;
        
            //Calculates 2 other constants, based on rload
            if (*rload > 1) {
                *Cexp = aload*pow((1 - (1/(*rload))), nload);
                *nexp = nload/((*rload)*(1 - (1/(*rload))));
            }
            
            //Checks that L < Lmax
            Lmax = (*I)*(1+(*lamda))*(*Sinu)*(*qbTf)/((*rB)*(1-(*lps))*((*subrate)/(1000*3600*24*365.25)));
            if ((*L) > Lmax) {
                printf("L exceeds %lf (Lmax).  Please edit inputs and try again.\n", Lmax);
                return 1;
            }
            
            //Subsidence Rate Correction
            *subrate = *subrate/(1000.0)/(3600*24*365.25);
            
            //Finds Exner Factor
            *ExnerFactor = (*Sinu)*(1 + (*lamda))/(*rB);
        
    //Finalize
    fclose(ptrIn);
    return 0;
}