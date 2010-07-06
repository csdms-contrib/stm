/*
 *  SetInitialBedandTime.c
 *  1DRiverWFRisingBaseLevelNormal
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetInitialBedandTime.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SetInitialBedandTime(double x[], double eta[], double Sfbl, double L, double dx, int M) {

    //Initialize
    int i=0;
    
    //Run
    for (i=1; i<= (M+1); i++) {
        x[i] = dx*(i-1);
        eta[i] = L*Sfbl - x[i]*Sfbl;
    }

    //Finalize
    return 0;
}