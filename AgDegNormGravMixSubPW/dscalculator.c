/*
 *  dscalculator.c
 *  AgDegNormGravMixSubPW
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "dscalculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

int dscalculator(quad GSD[], double ds[], double psi[], int np) {
    //Initialize
    int i=0;
    
    //Run
        //Calculates values of ds
            for (i=1; i <= np; i++)
                ds[i] = sqrt(GSD[i].di*GSD[i+1].di);

        //Calculates psi values
            for (i=1; i <= np; i++)
                psi[i] = log(ds[i])/log(2);
    
    //Finalize
    return 0;
}