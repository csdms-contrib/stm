/*
 *  CalculateAverages.c
 *  Acronym1D
 *
 *  Created by Andrew Leman on 6/17/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "CalculateAverages.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int CalculateAverages(float Qwr[], float pQ[], float pfld[][16], float qTd[], float Hd[],
                      float ustard[], float tausgd[], float pfla[], float pla[], float *Qwa, float *qTa,
                      float *Ha, float *ustara, float *tausga, int npp, int np, int nd) {
    //Initialize
    int i=0, j=0;
    
    //Run
        if (npp > 1) {
            for (i=0; i < np; i++) {
                pla[i]=0;
            }
        }
        
        for (i=0; i < nd; i++) {
            *Qwa = *Qwa + Qwr[i]*pQ[i];
            *qTa = *qTa + qTd[i]*pQ[i];
            *Ha = *Ha + Hd[i]*pQ[i];
            *ustara = *ustara + ustard[i]*pQ[i];
            *tausga = *tausga + tausgd[i]*pQ[i];
            if (npp > 1) {
                for (j=0; j < npp; j++) {
                    if (i == 0)
                    pla[j] = pfld[j][i]*pQ[i];
                    else
                    pla[j] = pla[j] + pfld[j][i]*pQ[i];
                }
            }
        }
        
        for (i=1; i <= np; i++) {
            pfla[i] = pla[i];
        }
    
    //Finalize
    return 0;
}