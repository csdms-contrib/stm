/*
 *  GeometricMean.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "GeometricMean.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

int GeometricMean(quad data[], double Ft[], int npp, double *Dsg) {
    //Initialize
    int i=0;
    double psi[npp+1], psimed[npp], fraction[npp], psibar=0.0;
    
    //Run
            //psi transform
            for(i=1; i <= npp; i++) {
                psi[i]=(log(data[i].di))/(log(2));
            }
            //median psi values and fraction calculation and calculation of ψ bar
            for(i=1; i < npp; i++) {
                psimed[i]=(psi[i]+psi[i+1])/2;
                fraction[i]=Ft[i];
                psibar += (psimed[i]*fraction[i]);
            }
            //calculating the geometric mean
            *Dsg=pow(2, psibar);
       
    
    //Finalize
    return 0;
}

