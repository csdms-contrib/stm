/*
 *  GeometricMean.c
 *  Acronym1
 *
 *  Created by Andrew Leman on 6/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "GeometricMean.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  {
    float D;
    float pfs;
} pair;

int GeometricMean(pair data[], float pfl[], int npp, float *Dsg, float *Dlg, int swap) {
    //Initialize
    int i=0;
    float psi[npp+1], psimed[npp], fraction[npp], psibar=0.0;
    
    //Run
        if (swap == 0) {
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
            //calculating the geometric mean
            *Dsg=pow(2, psibar);
        }
        else {
            //psi transform
            for(i=0; i < npp; i++) {
                psi[i]=(log(data[i].D))/(log(2));
            }
            //median psi values and fraction calculation and calculation of ψ bar
            for(i=0; i < (npp-1); i++) {
                psimed[i]=(psi[i+1]+psi[i])/2;
                fraction[i]=(pfl[i+1]-pfl[i])/100;
                psibar += (psimed[i]*fraction[i]);
            }
            //calculating the geometric mean
            *Dlg=pow(2, psibar);
        }
    
    //Finalize
    return 0;
}
