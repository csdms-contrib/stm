/*
 *  GeometricStandardDeviation.c
 *  Acronym1
 *
 *  Created by Andrew Leman on 6/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "GeometricStandardDeviation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float D;
    float pfs;
} pair;

int GeometricStandardDeviation(pair data[], float pfl[], int npp, float *sigmasg, float *sigmalg, int swap) {
    //Initialize
    int i=0;
    float psi[npp+1], psibar=0.0, psimed[npp], fraction[npp], sigsquared=0.0;
    
    
    //Run
        if(swap == 0) {
            //psi transform
            for(i=0; i < npp; i++) {
                psi[i]=(log(data[i].D))/(log(2));
            }
            //median psi values and fraction calculation and calculation of ψ bar
            for(i=0; i < (npp-1); i++) {
                psimed[i]=(psi[i]+psi[i+1])/2;
                fraction[i]=(data[i+1].pfs-data[i].pfs)/100;
                psibar += (psimed[i]*fraction[i]);
            }
            //Equation for σ squared
            for(i=0; i < (npp-1); i++) {
                sigsquared += (pow((psimed[i]-psibar), 2))*fraction[i];
            }
            //Convert back out of log 2 scale
            *sigmasg=pow(2, (sqrt(sigsquared)));
        }
        else {
            //psi transform
            for(i=0; i < npp; i++) {
                psi[i]=(log(data[i].D))/(log(2));
            }
            //median psi values and fraction calculation and calculation of ψ bar
            for(i=0; i < (npp-1); i++) {
                psimed[i]=(psi[i]+psi[i+1])/2;
                fraction[i]=(pfl[i+1]-pfl[i])/100;
                psibar += (psimed[i]*fraction[i]);
            }
            //Equation for σ squared
            for(i=0; i < (npp-1); i++) {
                sigsquared += (pow((psimed[i]-psibar), 2))*fraction[i];
            }
            //Convert back out of log 2 scale
            *sigmalg=pow(2, (sqrt(sigsquared)));
        }

    //Finalize
        return 0;
}
