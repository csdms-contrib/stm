/*
 *  Interpolation.c
 *  GSD Calculator
 *
 *  Created by Andrew Leman on 5/28/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Interpolation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float size;
    float perfiner;
} pair;

int Interpolation(pair datapoints[], int terms, float interp[], float input[]) {
    //Initialize
    int choice=0, i=0, j=0;
    float x=0, psi[terms+2], psix=0.0, Dx=0.0;
    char write;
    
    //Run
    
    //Infinite Loop allows user to continue calculating interpolants until they exit
    while(1) {
    printf("\nPress\n 1. to calculate a percent finer\n 2. to exit\n");
    scanf("%i", &choice);
    switch (choice) {
        case 1:
                printf("\nWhat percent finer would you like to know?\n");
                scanf("%f", &x);
                i = 0;
                while ((x/100.0) > datapoints[i].perfiner) {
                    i++;
                }
                psi[i-1]=(log(datapoints[i-1].size))/(log(2.0));
                psi[i]=(log(datapoints[i].size))/(log(2.0));
                psix=psi[i-1] + ((psi[i]-psi[i-1])/(datapoints[i].perfiner-datapoints[i-1].perfiner))*((x/100.0)-datapoints[i-1].perfiner);
                Dx=pow(2, psix);
                printf("the size such that %.1f%% is passing is: %f mm\n", x, Dx);
                printf("Would you like to print out this value to the output file (Y/N)? \n");
                printf("No more than 10 values to the output file\n");
                scanf("\n%c", &write);
                switch (write) {
                    case 'Y':
                            interp[j]=Dx;
                            input[j]=x;
                            j++;
                            break;
                    case 'N':
                    default:
                            break;
                    }
                    break;
        case 2:
                return j;
        default:
                return j;
        }
    }
    
    //Finalize
    return j;
}