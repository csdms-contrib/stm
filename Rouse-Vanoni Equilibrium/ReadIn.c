/*
 *  ReadIn.c
 *  Rouse-Vanoni Equilibrium
 *
 *  Created by Andrew Leman on 6/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>

int ReadIn(double *init_ratio, double *vs, double *u) {
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
            case 'v':
                    *vs = temp;
                    break;
            case 'b':
                    *init_ratio = temp;
                    break;
            case 'u':
                    *u = temp;
                    break;
            default:
                    printf("Not a valid entry, pleade edit file and try again.\n");
                    return 1;
        }
    }
    
    //Finalize
    fclose(ptrIn);
    return 0;
}