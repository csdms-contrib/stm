/*
 *  SetupInitialBed.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetupInitialBed.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SetupInitialBed(double xbarg[], double x[], double eta[], double xbars[],
    double *sgs, double sgsl, double Ssl, double sfsl, double dxbars, double Sgl,
    double dxbarg, int Mg, int Ms) {

    int i=0;
    
    for (i=1; i <= (Mg+1); i++) {
        xbarg[i] = dxbarg*(i-1);
        x[i] = sgsl*xbarg[i];
        eta[i] = Ssl*sfsl + Sgl*sgsl - Sgl*sgsl*xbarg[i];
    }
    for (i=1; i <= (Ms+1); i++) {
        xbars[i] = dxbars*(i-1);
        if (i > 1) {
            x[Mg+i] = sgsl + sfsl*xbars[i];
            eta[Mg+i] = Ssl*sfsl - Ssl*sfsl*xbars[i];
        }
    }
    *sgs = sgsl;

    return 0;
}