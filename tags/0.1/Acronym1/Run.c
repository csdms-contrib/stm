/*
 *  Run.c
 *  Acronym1
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
int CalcLoadandDistribution(pair [], int, int, float *, float, float, float,
        float [], float [], float [], float, double *, float [], float []);
int Interpolation(pair [], float [], int, int, float *, float *, float *, float *, float *,
        float *, float *, float *);

int Run (pair data[], float pfl[], int npp, int np, float *tausg, float R, float *Dsg,
    float ustar, float po[], float so[], float oo[], float *sigmasg, double *qbtot,
    float qb[], float *Dx30s, float *Dx50s, float *Dx70s, float *Dx90s, float *Dx30l,
    float *Dx50l, float *Dx70l, float *Dx90l, float *Dlg, float swap, float *sigmalg) {

    //Calculates the Load Distribution
    CalcLoadandDistribution(data, npp, np, &(*tausg), R, *Dsg, ustar, po,
                            so, oo, *sigmasg, &(*qbtot), pfl, qb);
    
    //Calculates Interpolants for bedload and surface
    if (npp != 1)
    Interpolation(data, pfl, npp, np, &(*Dx30s), &(*Dx50s), &(*Dx70s), &(*Dx90s), &(*Dx30l), &(*Dx50l),
                  &(*Dx70l), &(*Dx90l));
                  
    //Calculates Bedload Geometric Mean
    if (npp != 1)
    GeometricMean(data, pfl, npp, &(*Dsg), &(*Dlg), swap);
    
    //Calculates Bedload Standard Deviation
    if (npp != 1)
    GeometricStandardDeviation(data, pfl, npp, &(*sigmasg), &(*sigmalg), swap);

    return 0;

}