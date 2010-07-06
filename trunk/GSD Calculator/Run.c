/*
 *  Run.c
 *  GSD Calculator
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
        float size;
        float perfiner;
    } pair;
    
float GeometricMean(pair [], int);
float GeometricStandardDeviation(pair [], int);
int Interpolation(pair [], int, float [], float []);
    
int Run(pair datapoints[], float interp[], float input[], int terms, float *Dg,
    float *sigma, int *numinterp) {

     //Calculates the Geometric Mean
    *Dg = GeometricMean(datapoints, terms);

    //Calculates the Geometric Standard Deviation
    *sigma = GeometricStandardDeviation(datapoints, terms);

    //Interpolation Calculator
    *numinterp = Interpolation(datapoints, terms, interp, input);
    return 0;

}