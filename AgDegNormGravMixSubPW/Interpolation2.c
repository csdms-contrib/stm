/*
 *  Interpolation2.c
 *  AgDegNormGravMixSubPW
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Interpolation2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

typedef struct  {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

int Interpolation2(quad data[], double Ft[], int npp, double *Dx50s, double *Dx90s) {
    //Initialize
    double psi[npp+2], psix=0;
    int i=1, x=0;
    
    //Run
    for (x=50; x <= 90; x += 40) {
        i=1;
        while (x < Ft[i]) {
            i++;
        }
        psi[i-1]=(log(data[i-1].di))/(log(2.0));
        psi[i]=(log(data[i].di))/(log(2.0));
        psix=psi[i] + ((psi[i-1]-psi[i])/(Ft[i-1]-Ft[i]))*(x*1.0-Ft[i]);
        if (x == 50)
        *Dx50s = pow(2, psix);
        else
        *Dx90s = pow(2, psix);
    }
        
    //Finalize
    return 0;
}