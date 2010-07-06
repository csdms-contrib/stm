/*
 *  WriteOut.c
 *  Rouse-Vanoni Equilibrium
 *
 *  Created by Andrew Leman on 5/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>

int WriteOut(double column1[], double column2[], int num) {
//Initialize
FILE *ptrOut;
char nameOut[50];
int i=0;

//Run
printf("What do you want to call the output file? (less than 50 characters, please) \n");
printf("WARNING: If you have a file with this name it will be overwritten.\n");
scanf("%s", &nameOut);
ptrOut = fopen(nameOut, "w");
fprintf(ptrOut, "The following are the data for the Rouse-Vanoni Profile: \n\n");
fprintf(ptrOut, "z/H\tc/cb\n");
for (i=0; i < num; i++) {
    fprintf(ptrOut, "%lf\t%lf\n", column1[i], column2[i]);
}


//Finalize
fclose(ptrOut);
return 0;
}