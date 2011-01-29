/*
 *  WriteOut.c
 *  AgDegNormal
 *
 *  Created by Andrew Leman on 6/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int WriteOut(float H, float taustar, float qstar, float qt, float Gt, float qtf,
            float tauult, float Sult, float Hult, char nameOut1[]) {
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
            printf("Invalid Choice! Constants were not written to file");
            return 1;
    }

    fprintf(ptrOut, "The flow depth at flood: \t\t\t%f\t[m]\n", H);
    fprintf(ptrOut, "The Shield's number at flood: \t\t\t%f\n", taustar);
    fprintf(ptrOut, "The Einstein number at flood: \t\t\t%f\n", qstar);
    fprintf(ptrOut, "The Volume Sediment Transport Rate per Unit Width: \t\t\t%f\n", qt);
    fprintf(ptrOut, "The Ambient Annual Sediment Transport Rate: \t\t\t%f\t[tons/a]\n", Gt);
    
    fprintf(ptrOut, "\nThe Upstream Imposed Volume Sediment Rate per Unit Width: \t\t\t%f\t[m^2/s]\n", qtf);
    fprintf(ptrOut, "The Ultimate Equilibrium Shield's Number: \t\t\t%f\n", tauult);
    fprintf(ptrOut, "The Ultimate Slope to which the bed will aggrade: \t\t\t%f\n", Sult);
    fprintf(ptrOut, "The Ultimate Flow Depth: \t\t\t%f\t[m]\n\n", Hult);
    
    //Finalize
    fclose(ptrOut);
    printf("Your file has been written. \n");
    return 0;
}