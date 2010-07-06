/*
 *  Renormalize.c
 *  AgDegNormGravMixPW
 *
 *  Created by Andrew Leman on 6/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Renormalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int Renormalize(double Ft[], int np) {
    //Initialize
    int j=0;
    double sum=0;
    
    //Run
    for (j=1; j <= np; j++) {
        if (Ft[j] < 0) {
            Ft[j] = 0;
        }
        sum += Ft[j];
    }
    for (j=1; j <= np; j++) {
        Ft[j] = Ft[j]/sum;
    }
    
    //Finalize
    return 0;
}