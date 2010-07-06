/*
 *  ReadIn.c
 *  SuspSedDensityStrat
 *
 *  Created by Andrew Leman on 7/6/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *R, double *D, double *H, double *kc, double *ustar, double *nu, double *Cr) {

    //Initialize
        double temp=0;
        char nameIn[50], indicator;
        FILE *ptrIn;
    
    //Run
        //reads in and opens the file the user selects
        printf("Please enter the name of your input file.\n(has to be a *.txt file)\n");
        scanf("%s", &nameIn);
        ptrIn = fopen(nameIn, "r");
        //checks to make sure file is valid and opened
        if(ptrIn == NULL) {
            printf("Error! Input file does not exist.  Make sure file is in proper folder.\n");
            return 1;
        }
        
        //reads values into their respective constants, such that input file
        //can have them in any order
        while (EOF != fscanf(ptrIn, "%s  %lf\n", &indicator, &temp)) {
            switch (indicator) {
                case 'R':
                        *R = temp;
                        break;
                case 'D':
                        *D = temp;
                        break;
                case 'H':
                        *H = temp;
                        break;
                case 'k':
                        *kc = temp;
                        break;
                case 'u':
                        *ustar = temp;
                        break;
                case 'v':
                        *nu = temp;
                        break;
                case 'C':
                        *Cr = temp;
                        break;
                default:
                        printf("Not a valid entry, please edit file and try again.\n");
                        return 1;
            }
        }

    //Finalize
    return 0;
}
