/*
 *  Finalize.c
 *  GSD Calculator
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
        float size;
        float perfiner;
    } pair;
    
int WriteOut(pair [], int, float, float, float [], float [], int);

int Finalize(pair datapoints[], int terms, float Dg, float sigma, float interp[],
    float input[], int numinterp) {

    WriteOut(datapoints, terms, Dg, sigma, interp, input, numinterp);
    printf("\nYour file has been written.\n");
    return 0;

}