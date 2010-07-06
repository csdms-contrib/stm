/*
 *  GeometricMean.c
 *  GSD Calculator
 *
 *  Created by Andrew Leman on 5/28/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "GeometricMean.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  {
    float size;
    float perfiner;
} pair;

float GeometricMean(pair datapoints[], int terms) {
    //Initialize
    int i=0;
    float psi[terms+1], psimed[terms], fraction[terms], psibar=0.0, Dg=0.0;
    
    //Run
        //psi transform
        for(i=0; i <= terms; i++) {
            psi[i]=(log(datapoints[i].size))/(log(2));
        }
        //median psi values and fraction calculation and calculation of ψ bar
        for(i=0; i < terms; i++) {
            psimed[i]=(psi[i]+psi[i+1])/2;
            fraction[i]=(datapoints[i+1].perfiner-datapoints[i].perfiner);
            psibar += (psimed[i]*fraction[i]);
        }
        //calculating the geometric mean
        Dg=pow(2, psibar);
    
    //Finalize
    printf("\nThe Geometric Mean is: %f mm\n", Dg);
    return Dg;
}