/*
 *  SetInitialBed.c
 *  SubsidingFan
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetInitialBed.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SetInitialBed(double x[], double eta[], double dx, int M) {

    int i=0;
    
    for (i=1; i <= (M+1); i++) {
        x[i] = dx*(i-1);
        eta[i] = 0;
    }

    return 0;
}