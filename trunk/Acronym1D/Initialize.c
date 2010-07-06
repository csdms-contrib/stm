/*
 *  Initialize.c
 *  Acronym1D
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
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

int ReadIn(pair [], pair2 [], float [], float [], float *, int *, int *, int *,
        float *, float *, float *, float *, float *, float *, float *, float *);
void Scaling(pair [], int);
int SandCheck(pair [], int *, int *, int *);
int Reorder(pair [], int, int);
int EndpointChecker(pair [], int *, int *);
int GeometricMean(pair [], float [], int, float *, float *, int);
int GeometricStandardDeviation(pair [], float [], int, float *, float *, int);
int SetStrainCurves(float [], float [], float []);
int Interpolation(pair [], float [], int, int, float *, float *, float *, float *, float *,
        float *, float *, float *, int);

int Initialize(pair data[], pair2 flowdata[], float Qwr[], float pQ[], float *R, int *npp,
    int *ndd, int *nd, float *Dsg, float *Dlg, float *sigmasg, float *sigmalg, float *S,
    float *B, float *nk, float *Dx90s, int *np, int *nppo, float qb[], float *swap,
    float pfl[], float *Dx30s, float *Dx50s, float *Dx70s, float *Dx30l,
    float *Dx50l, float *Dx70l, float *Dx90l, float po[], float so[], float oo[]) {

    //Declaration
    int check=0;

    //Reads in values from text file and declares variable dependent on npp
    ReadIn(data, flowdata, Qwr, pQ, &(*R), &(*npp), &(*ndd), &(*nd), &(*Dsg), &(*Dlg),
        &(*sigmasg), &(*sigmalg), &(*S), &(*B), &(*nk), &(*Dx90s));
    
    //Crunch the Surface Distribution
        
        //Scales the values to a 0-100 scale if they are not already on it
        Scaling(data, *npp);
    
        //Sand Checking and renormalization if needed
        check = SandCheck(data, &(*npp), &(*np), &(*nppo));
    
        //Exits program if sand is involved
        if (check == 1)
            return 1;
        
        //Reorder so that EndpointChecker works
        if (*npp != 1)
        Reorder(data, *npp, *nppo);
                    
        //Checks to make sure there are endpoints at 100% and 0%
        if (*npp != 1)
        EndpointChecker(data, &(*npp), &(*np));
        
        //Reorders in case extra points were added
        if (*npp != 1)
        Reorder(data, *npp, *nppo);
        
        //Calculates the Geometric Mean
        if (*npp != 1)
        GeometricMean(data, qb, *npp, &(*Dsg), &(*Dlg), *swap);
    
        //Calculates the Geometric Standard Deviation
        if (*npp != 1)
        GeometricStandardDeviation(data, pfl, *npp, &(*sigmasg), &(*sigmalg), *swap);
    
        //Calculates Interpolants for Surface
        if (*npp !=1)
        Interpolation(data, pfl, *npp, *np, &(*Dx30s), &(*Dx50s), &(*Dx70s), &(*Dx90s), &(*Dx30l), &(*Dx50l),
                    &(*Dx70l), &(*Dx90l), *swap);
        *swap = 1;
        
    //Set Strain Curves for use later on
    SetStrainCurves(po, oo, so);
        

    return 0;

}