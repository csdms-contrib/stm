/*
 *  WriteOut.c
 *  GSD Calculator
 *
 *  Created by Andrew Leman on 5/28/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    float size;
    float perfiner;
} pair;

int WriteOut(pair datapoints[], int terms, float Dg, float sigma, float interp[], float input[], int numinterp) {
//Initialize
FILE *ptrOut;
char nameOut[50];
int i=0;

//Run
printf("\nWhat do you want to call the output file? (less than 50 characters, please)\n");
printf("WARNING: If you have a file with this name it will be overwritten.\n");
scanf("%s", &nameOut);
ptrOut = fopen(nameOut, "w");
if(ptrOut == NULL) {
    return 1; }
fprintf(ptrOut, "The following are your organized data points: \n\n");
fprintf(ptrOut, "diameter\tpercent passing\n");
for (i=0; i <= terms; i++) {
    fprintf(ptrOut, "%f\t%f\n", datapoints[i].size, datapoints[i].perfiner);
}
if(Dg == 0)
    fprintf(ptrOut, "The percent passing values given were incorrect.\n");
else {
fprintf(ptrOut, "\nThe geometric mean is:\t\t\t%f\t[mm]\n", Dg);
fprintf(ptrOut, "\nThe geometric standard deviation is:\t\t\t%f\n", sigma);
}
if (numinterp > 0) {
    for(i=0; i < numinterp; i++) {
        fprintf(ptrOut, "\nThe size such that %.1f%% is passing is:\t\t\t%f\t[mm]", input[i], interp[i]);
    }
}

//Finalize
fclose(ptrOut);
return 0;
}