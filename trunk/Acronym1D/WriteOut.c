/*
 *  WriteOut.c
 *  Acronym1D
 *
 *  Created by Andrew Leman on 6/17/09.
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

int WriteOut(pair data[], float pfla[], float qTa, float tausga, float Qwa, float Ha,
             float ustara, float Dsg, float Dlg, float sigmasg, float sigmalg, int npp,
             float Dx90s, float Dx70s, float Dx50s, float Dx30s, float Dx90l,
             float Dx70l, float Dx50l, float Dx30l, int nd, float Qwr[], float pQ[],
             float qTd[], float Hd[], float ustard[], float tausgd[]) {
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
        
    fprintf(ptrOut, "\nqbTa:\t%f\n", qTa);
    fprintf(ptrOut, "Qwa: \t%f\n", Qwa);
    fprintf(ptrOut, "taug*a:\t%f\n", tausga);
    fprintf(ptrOut, "Ha:\t%f\n", Ha);
    fprintf(ptrOut, "u*a:\t%f\n\n", ustara);
    fprintf(ptrOut, "Diameter\t%% finer (surface)\t%% finer (bedload)\n");
    for (i=0; i < npp; i++)
        fprintf(ptrOut, "%f\t%f\t%f\n", data[i].D, data[i].pfs, pfla[i]);
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
    
    if (nd != 1) {
        fprintf(ptrOut, "\nQwr\tpQ\tqbTr\tH\tustar\ttaustar\n");
        fprintf(ptrOut, "m^3/s\t\tm^2/s\tm\tm/s\n");
        for (i=1; i < nd; i++) {
            fprintf(ptrOut, "%f\t%f\t%f\t%f\t%f\t%f\n", Qwr[i], pQ[i], qTd[i], Hd[i], ustard[i], tausgd[i]);
        }
    }

    //Finalize
    fclose(ptrOut);
    return 0;
}