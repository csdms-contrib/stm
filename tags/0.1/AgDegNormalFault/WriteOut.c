/*
 *  WriteOut.c
 *  AgDegNormalFault
 *
 *  Created by Andrew Leman on 6/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int WriteOut(double H, double taustar, double qstar, double qt, double Gt, double qtg, double dx, char nameOut1[]) {
    //Initialize
    int choice=0;
    FILE *ptrOut;
    char nameOut[50];
    
    //Run
    printf("Would you like to:\n1. print some additional output parameters to the output file\n2. create a new output file with some of the additional output parameters\n");
    scanf("%i", &choice);
    switch (choice) {
        case 1:
            ptrOut = fopen(nameOut1, "a");
            fprintf(ptrOut, "\n\n");
            break;
        case 2:
            printf("What do you want to call the additional output parameters file? (less than 50 characters please)\n");
            printf("WARNING: If you have a file with this name it will be overwritten.\n");
            scanf("%s", &nameOut);
            ptrOut = fopen(nameOut, "w");
            break;

        default:
            printf("Invalid Choice! Additional output parameters were not written to file\n");
            return 1;
    }

    fprintf(ptrOut, "The flow depth at flood: \t\t\t%lf\t[m]\n", H);
    fprintf(ptrOut, "The Shield's number at flood: \t\t\t%lf\n", taustar);
    fprintf(ptrOut, "The Einstein number at flood: \t\t\t%lf\n", qstar);
    fprintf(ptrOut, "The Volume Sediment Transport Rate per Unit Width: \t\t\t%lf\n", qt);
    fprintf(ptrOut, "The Ambient Annual Sediment Transport Rate: \t\t\t%lf\t[tons/a]\n", Gt);
    fprintf(ptrOut, "The feed rate at the ghost node at flood: \t\t\t%lf\t[m^2/s]\n", qtg);
    fprintf(ptrOut, "The spatial step is: \t\t\t%lf\t[m]\n", dx);

    //Finalize
    fclose(ptrOut);
    printf("Your file has been written. \n");
    return 0;
}