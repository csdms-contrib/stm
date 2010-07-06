/*
 *  SetupInitialBedandTime.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetupInitialBedandTime.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int SetupInitialBedandTime(double F[][16], double Fl[], double eta[], double x[],
        double dsgs[], double Ds90s[], double *dx, double S, double L, int M,
        double etad, int np, double Dsgsi, double Ds90si, double Sl[]) {
    //Initialize
    int i=0, j=0;
    
    //Run
        //Calc dx
        *dx = L/M;
        
        //Set Initial Bed
        for(i=1; i <= (M+1); i++) {
            x[i] = (*dx)*(i-1);
            eta[i] = etad + (S*L)-(S*x[i]);
        }
        eta[M+1] = etad;
        
        //Set initial GSD for various Grain sizes at various locations
        //also sets initial D90 and Mean
        for (i=1; i <= (M+1); i++) {
            for (j=1; j <= np; j++) {
                F[i][j] = Fl[j];
            }
        dsgs[i] = Dsgsi;
        Ds90s[i] = Ds90si;
        Sl[i] = S;
        }

    //Finalize
    return 0;
}

