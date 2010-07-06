/*
 *  FracSand.c
 *  AgDegNormGravMixSubPW
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FracSand.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

int FracSand(quad GSD[], int np, double *fracsandl) {
    //Initialize
    int i=0;
    
    //Run
        //Fraction Sand Function
        for (i=1; i <= np; i++) {
            if ((GSD[i].di > 2) && (GSD[i+1].di <= 2)) {
                *fracsandl = GSD[i+1].Ffl + ((GSD[i].Ffl - GSD[i+1].Ffl)/(log(GSD[i].di) - log(GSD[i+1].di)))*(log(2) - log(GSD[i+1].di));
                *fracsandl= *fracsandl/100;
            }
        }

    //Finalize
    return 0;
}