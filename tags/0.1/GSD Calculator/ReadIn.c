/*
 *  ReadIn.c
 *  GSD Calculator
 *
 *  Created by Andrew Leman on 5/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(float D[], float f[]) {
    //Initialize
    FILE *ptrIn;
    char nameIn[50];
    int i=0;
    float temp1=0, temp2=0;

    //Run
    printf("Please enter the name of your input file.\n(has to be a *.txt file)\n");
    scanf("%s", &nameIn);
    ptrIn = fopen(nameIn, "r");
    if (ptrIn == NULL) {
        printf("Error! Input file does not exist.  Make sure file is in proper folder.\n");
        return 0;
    }
    while (EOF != fscanf(ptrIn, "%f %f \n", &temp1, &temp2)) {
        D[i]=temp1;
        f[i]=temp2;
        i++;
    }

    //Finalize
    fclose(ptrIn);
    return (i-1);
}