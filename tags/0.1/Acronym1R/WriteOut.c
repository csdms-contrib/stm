/*
 *  WriteOut.c
 *  Acronym1R
 *
 *  Created by Andrew Leman on 6/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    float D;
    float pfs;
} pair;

int WriteOut(pair data[], int npp, float pfl[], float tausg, double qbtot, float Dsg,
             float Dlg, float sigmasg, float sigmalg, float Dx30s, float Dx50s, float Dx70s,
             float Dx90s, float Dx30l, float Dx50l, float Dx70l, float Dx90l, float H, float ustar) {
    //Initialize
    FILE *ptrOut;
    char nameOut[50];
    int i=0;

    //Run
    printf("\nWhat would you want to call the output file? (less than 50 characters, please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut);
    ptrOut = fopen(nameOut, "w");
    if(ptrOut == NULL) {
        return 1; }
        
    fprintf(ptrOut, "\nqbT:\t%f\n", qbtot);
    fprintf(ptrOut, "taug*:\t%f\n", tausg);
    fprintf(ptrOut, "H:\t%f\n", H);
    fprintf(ptrOut, "u*:\t%f\n\n", ustar);
    fprintf(ptrOut, "Diameter\t%% finer (surface)\t%% finer (bedload)\n");
    for (i=0; i < npp; i++)
        fprintf(ptrOut, "%f\t%f\t%f\n", data[i].D, data[i].pfs, pfl[i]);
    fprintf(ptrOut, "\nStatistics:\n\tsurface\tbedload\n");
    fprintf(ptrOut, "Dg:\t%f\t%f\n", Dsg, Dlg);
    fprintf(ptrOut, "sigmag:\t%f\t%f\n", sigmasg, sigmalg);
    if (npp == 1) {
        fprintf(ptrOut, "D90:\t%f\t%f\n", data[0].D, data[0].D);
        fprintf(ptrOut, "D70:\t%f\t%f\n", data[0].D, data[0].D);
        fprintf(ptrOut, "D50:\t%f\t%f\n", data[0].D, data[0].D);
        fprintf(ptrOut, "D30:\t%f\t%f\n", data[0].D, data[0].D);
    }
    else {
        fprintf(ptrOut, "D90:\t%f\t%f\n", Dx90s, Dx90l);
        fprintf(ptrOut, "D70:\t%f\t%f\n", Dx70s, Dx70l);
        fprintf(ptrOut, "D50:\t%f\t%f\n", Dx50s, Dx50l);
        fprintf(ptrOut, "D30:\t%f\t%f\n", Dx30s, Dx30l);
    }

    //Finalize
    fclose(ptrOut);
    return 0;
}