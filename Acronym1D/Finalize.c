/*
 *  Finalize.c
 *  Acronym1D
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

typedef struct {
    float Qwd;
    float pQf;
} pair2;

int WriteOut(pair [], float [], float, float, float, float, float, float, float,
        float, float, int, float, float, float, float, float, float, float, float,
        int, float [], float [], float [], float [], float [], float []);

int Finalize(pair data[], float pfla[], float qTa, float tausga, float Qwa, float Ha, float ustara,
    float Dsg, float Dlg, float sigmasg, float sigmalg, int npp, float Dx90s, float Dx70s, float Dx50s,
    float Dx30s, float Dx90l, float Dx70l, float Dx50l, float Dx30l, int nd, float Qwr[], float pQ[],
    float qTd[], float Hd[], float ustard[], float tausgd[]) {

    //Write Answers to a text file
    WriteOut(data, pfla, qTa, tausga, Qwa, Ha, ustara, Dsg, Dlg, sigmasg, sigmalg,
            npp, Dx90s, Dx70s, Dx50s, Dx30s, Dx90l, Dx70l, Dx50l, Dx30l, nd, Qwr,
            pQ, qTd, Hd, ustard, tausgd);
    return 0;

}