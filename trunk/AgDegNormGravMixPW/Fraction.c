/*
 *  Fraction.c
 *  AgDegNormGravMixPW
 *
 *  Created by Andrew Leman on 6/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Fraction.h"
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

int Fraction(quad GSD[], int npp, double plf[], double Fl[], double Fs[]) {
    //Initialize
    int i=0;
    
    //Run
        for (i=1; i < npp; i++) {
            plf[i] = (GSD[i].plff - GSD[i+1].plff)/100;
            Fl[i] = (GSD[i].Ffl - GSD[i+1].Ffl)/100;
            Fs[i] = (GSD[i].Ffs - GSD[i+1].Ffs)/100;
        }
    
    //Finalize
    return 0;
}