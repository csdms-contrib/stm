/*
 *  WriteOut.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double x[], double eta[], double ksi[], double H[], double Hs[], int M, double Hnorm) {

    //Initialize
    int i=0;
    FILE *ptrOut;
    char nameOut[50];

    //Run
    printf("What do you want to call the output file? (less than 50 characters, please) \n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut);
    ptrOut = fopen(nameOut, "w");
    
    fprintf(ptrOut, "\n");
    if (Hnorm != 0) {
    fprintf(ptrOut, "The Normal Depth, Hnorm = \t\t\t%lf\n", Hnorm);
    fprintf(ptrOut, "\n");
    }
    fprintf(ptrOut, "Node\tx[m]\teta[m]\tksi[m]\tH[m]\tHs[m]\n");
    for (i=1; i <= (M+1); i++) {
        fprintf(ptrOut, "%i\t%lf\t%lf\t%lf\t%lf\t%lf\n", i, x[i], eta[i], ksi[i], H[i], Hs[i]);
    }
    
    //Finalize
    fclose(ptrOut);
    return 0;
}