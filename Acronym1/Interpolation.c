/*
 *  Interpolation.c
 *  Acronym1
 *
 *  Created by Andrew Leman on 6/15/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Interpolation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

typedef struct  {
    float D;
    float pfs;
} pair;

int Interpolation(pair data[], float pfl[], int npp, int np, float *Dx30s, float *Dx50s,
                  float *Dx70s, float *Dx90s, float *Dx30l, float *Dx50l, float *Dx70l,
                  float* Dx90l) {
    //Initialize
    float psi[npp+2], psix=0;
    int i=0, x=0;
    
    //Run
    for (x=30; x <= 90; x += 20) {
        while (x > data[i].pfs) {
            i++;
        }
        psi[i-1]=(log(data[i-1].D))/(log(2.0));
        psi[i]=(log(data[i].D))/(log(2.0));
        psix=psi[i-1] + ((psi[i]-psi[i-1])/(data[i].pfs-data[i-1].pfs))*(x-data[i-1].pfs);
        if (x == 30)
        *Dx30s = pow(2, psix);
        else if (x == 50)
        *Dx50s = pow(2, psix);
        else if (x == 70)
        *Dx70s = pow(2, psix);
        else
        *Dx90s = pow(2, psix);
    }
    
    i=0;
    for (x=30; x <= 90; x += 20) {
        while (x > pfl[i]) {
            i++;
        }
        psi[i-1]=(log(data[i-1].D))/(log(2.0));
        psi[i]=(log(data[i].D))/(log(2.0));
        psix=psi[i-1] + ((psi[i]-psi[i-1])/(pfl[i]-pfl[i-1]))*(x-pfl[i-1]);
        if (x == 30)
        *Dx30l = pow(2, psix);
        else if (x == 50)
        *Dx50l = pow(2, psix);
        else if (x == 70)
        *Dx70l = pow(2, psix);
        else
        *Dx90l = pow(2, psix);
    }
    
    //Finalize
    return 0;
}