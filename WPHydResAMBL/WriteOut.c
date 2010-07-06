/*
 *  WriteOut.c
 *  WPHydResAMBL
 *
 *  Created by Andrew Leman on 7/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(int N, double Hs[], double tausg[], double U[], double Gamma[], double H[],
    double qw[], double tau[], double ratio[], double Fr[], double u[], double us[],
    double qb[]) {

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
    fprintf(ptrOut, "Hs\ttausg\tU\tGamma\tH\tqw\ttau\tratio\tFr\tu*\tu*s\tqb\n");
    for (i=1; i <= N; i++) {
        if (ratio[i] <= 1) {
            fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", Hs[i], tausg[i], U[i], Gamma[i], H[i], qw[i], tau[i], ratio[i], Fr[i], u[i], us[i], qb[i]);
        }
        else {
            fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\tthe ratio is > 1, therefore these values have no meaning\n", Hs[i], tausg[i], U[i], Gamma[i], H[i], qw[i], tau[i], ratio[i]);
        }
    }
    
    //Finalize
    fclose(ptrOut);
    return 0;
}