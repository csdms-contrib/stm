/*
 *  Finalize.c
 *  Acronym1R
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  {
    float D;
    float pfs;
} pair;

int WriteOut(pair [], int, float [], float, double, float, float, float, float,
        float, float, float, float, float, float, float, float, float, float);

int Finalize(pair data[], int npp, float pfl[], float tausg, double qbtot, float Dsg,
    float Dlg, float sigmasg, float sigmalg, float Dx30s, float Dx50s, float Dx70s,
    float Dx90s, float Dx30l, float Dx50l, float Dx70l, float Dx90l, float H, float ustar) {

    //Write Answers to a text file
    WriteOut(data, npp, pfl, tausg, qbtot, Dsg, Dlg, sigmasg, sigmalg, Dx30s,
             Dx50s, Dx70s, Dx90s, Dx30l, Dx50l, Dx70l, Dx90l, H, ustar);
    return 0;

}