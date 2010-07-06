/*
 *  GeometricStandardDeviation.c
 *  AgDegNormGravMixPW
 *
 *  Created by Andrew Leman on 6/19/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "GeometricStandardDeviation.h"
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

int GeometricStandardDeviation(quad data[], double Ft[], int npp, double *sigma) {
        //Initialize
        int i=0;
        double psi[npp+2], psibar=0.0, psimed[npp+1], sigsquared=0;
            
        //Run
        for(i=1; i <= npp; i++) {
            psi[i]=(log(data[i].di))/(log(2));
        }
        for(i=1; i < npp; i++) {
            psimed[i]=(psi[i]+psi[i+1])/2;
            psibar += (psimed[i]*Ft[i]);
        }
        for(i=1; i < npp; i++) {
            sigsquared += (pow((psimed[i]-psibar), 2))*Ft[i];
        }
        *sigma=pow(2, (sqrt(sigsquared)));
        
        //Finalize
        return 0;
    }