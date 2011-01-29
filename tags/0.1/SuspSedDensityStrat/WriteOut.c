/*
 *  WriteOut.c
 *  SuspSedDensityStrat
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double zeta[], double initun[], double initcn[], double un[], double cn[],
    double Ri[], double unao, double cnao, double qso, double una, double cna, double qs) {

    //Declarations
    FILE *ptrOut;
    char nameOut[50];
    int i=0, nintervals=50;

    //Run
        //Opens file to print to
        printf("Whatdo you want to call the output file? (less than 50 characters please)\n");
        printf("WARNING: If you have a file with this name it will be overwritten.\n");
        scanf("%s", &nameOut);
        ptrOut = fopen(nameOut, "w");
        
        //Prints data to file
        fprintf(ptrOut, "\n");
        fprintf(ptrOut, "zeta\tuno\tcno\tun\tcn\tRi\n");
        for (i=1; i <= (nintervals+1); i++) {
            fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", zeta[i], initun[i], initcn[i], un[i], cn[i], Ri[i]);
        }
        fprintf(ptrOut, "\n");
        fprintf(ptrOut, "unao\tcnao\tqso\tuna\tcna\tqs\n");
        fprintf(ptrOut, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", unao, cnao, qso, una, cna, qs);
    

    //Finalize
    fclose(ptrOut);
    return 0;
}