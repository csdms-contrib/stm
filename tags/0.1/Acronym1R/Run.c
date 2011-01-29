/*
 *  Run.c
 *  Acronym1R
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  {
    float D;
    float pfs;
} pair;

int GeometricMean(pair [], float [], int, float *, float *, int);
int GeometricStandardDeviation(pair [], float [], int, float *, float *, int);
int Interpolation(pair [], float [], int, int, float *, float *, float *, float *, float *,
        float *, float *, float *, int);
int FindDepthandVelocity(float *, float *, float, float, float, float, float);
int CalcLoadandDistribution(pair [], int, int, float *, float, float, float,
        float [], float [], float [], float, double *, float [], float []);

int Run(pair data[], float *H, float *ustar, float nk, float *Dx90s, float Qf, float B,
    float S, int npp, int np, float *tausg, float R, float *Dsg, float po[],
    float so[], float oo[], float *sigmasg, double *qbtot, float pfl[], float qb[], float swap,
    float *Dx70s, float *Dx50s, float *Dx30s, float *Dx90l, float *Dx70l, float *Dx50l,
    float *Dx30l, float *Dlg, float *sigmalg) {

    //Declaration
    int check = 0;
    
    //Calculates H and ustar
    check = FindDepthandVelocity(&(*H), &(*ustar), nk, *Dx90s, Qf, B, S);
    if (check == 1)
        return 1;
    
    //Calculates the Load Distribution
    CalcLoadandDistribution(data, npp, np, &(*tausg), R, *Dsg, *ustar, po,
                            so, oo, *sigmasg, &(*qbtot), pfl, qb);
    
    //Calculates Interpolants for Bedload
    if (npp != 1)
    Interpolation(data, pfl, npp, np, &(*Dx30s), &(*Dx50s), &(*Dx70s), &(*Dx90s), &(*Dx30l), &(*Dx50l),
                  &(*Dx70l), &(*Dx90l), swap);
                  
    //Calculates Bedload Geometric Mean
    if (npp != 1)
    GeometricMean(data, pfl, npp, &(*Dsg), &(*Dlg), swap);
    
    //Calculates Bedload Standard Deviation
    if (npp != 1)
    GeometricStandardDeviation(data, pfl, npp, &(*sigmasg), &(*sigmalg), swap);
    return 0;

}