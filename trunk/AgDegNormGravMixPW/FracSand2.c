/*
 *  FracSand2.c
 *  AgDegNormGravMixPW
 *
 *  Created by Andrew Leman on 6/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FracSand2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

int FracSand2(quad GSD[], double Fft[], int np, double *fracsandl) {
    //Initialize
    int i=0;
    
    //Run
        //Fraction Sand Function
        for (i=1; i <= np; i++) {
            if ((GSD[i].di > 2) && (GSD[i+1].di <= 2)) {
                *fracsandl = Fft[i+1] + ((Fft[i] - Fft[i+1])/(log(GSD[i].di) - log(GSD[i+1].di)))*(log(2) - log(GSD[i+1].di));
                *fracsandl= *fracsandl/100;
            }
        }

    //Finalize
    return 0;
}