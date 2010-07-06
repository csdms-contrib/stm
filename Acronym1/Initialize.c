/*
 *  Initialize.c
 *  Acronym1
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

int ReadIn(pair [], float *, float *, int *, float *, float *, float *, float *);
void Scaling(pair [], int);
int SandCheck(pair [], int *, int *, int *);
int Reorder(pair [], int, int);
int EndpointChecker(pair [], int *, int *);
int GeometricMean(pair [], float [], int, float *, float *, int);
int GeometricStandardDeviation(pair [], float [], int, float *, float *, int);
int SetStrainCurves(float [], float [], float []);

int Initialize(pair data[], float *R, float *ustar, int *npp, float *Dsg, float *Dlg, float *sigmasg,
    float *sigmalg, int *np, int *nppo, float qb[], float *swap, float pfl[], float po[], float oo[],
    float so[]) {

    //Declaration
    int check=0;
    
    //Reads in values from text file
    ReadIn(data, &(*R), &(*ustar), &(*npp), &(*Dsg), &(*Dlg), &(*sigmasg), &(*sigmalg));
    
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
    *swap = 1;
    
    //Set Strain Curves for use later on
    SetStrainCurves(po, oo, so);
    return 0;

}