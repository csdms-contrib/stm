/*
 *  ReadFile.c
 *  I:O Subfunctions
 *
 *  Created by Andrew Leman on 5/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>

int ReadIn(double alias[]) {
    // Initialize
    char nameIn[50], indicator;
    FILE *ptrIn;
    double temp=0.0;
    
    //Run
    // prompts user for the input file
    printf("Please enter the name of your input file.\n(has to be a *.txt file)\n");
    scanf("%s", &nameIn);
    
    //opens file for reading only, and checks to make sure file opened
    ptrIn = fopen(nameIn, "r");
    if (ptrIn == NULL) {
        printf("Error! Input file does not exist.  Make sure file is in proper folder\n");
        return 1;
    }
    
    //actually reads values into matrix
    while (EOF != fscanf(ptrIn, "%c  %lf\n", &indicator, &temp)) {
        switch(indicator) {
            case 'v':
                        alias[0]=temp;
                        break;
            case 'R':
                        alias[1]=temp;
                        break;
            case 'D':
                        alias[2]=temp;
                        break;
            case 'g':   
                        alias[3]=temp;
                        break;
            default:
                        printf("Not a valid entry, please edit file and try again.\n");
                        return 1;
        }
    }
    
    //Finalize
    //close the file that we are reading in from
    fclose(ptrIn);
    return 0;
}
