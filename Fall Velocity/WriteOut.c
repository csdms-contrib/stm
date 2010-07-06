/*
 *  WriteOut.c
 *  Fall Velocity
 *
 *  Created by Andrew Leman on 6/4/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>

int WriteOut(float velocity, float Rep, float Rf) {
    // Initialize
    FILE * ptrOut;
    char nameOut[50];
    
    //Run
    printf("\nWhat do you want to call the output file? (less than 50 characters please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut);
    ptrOut = fopen(nameOut ,"w");
    
    fprintf(ptrOut, "The grain's fall velocity is: \n%lf\t[cm/s]\n\n", velocity);
    fprintf(ptrOut, "The particle Reynolds number is: \n%lf\n\n", Rep);
    fprintf(ptrOut, "The dimensionless fall velocity is: \n%lf\n\n", Rf); 

    
    //Finalize
    fclose(ptrOut);
    return 0;
}