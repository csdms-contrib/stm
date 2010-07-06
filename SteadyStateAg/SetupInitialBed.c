/*
 *  SetupInitialBed.c
 *  SteadyStateAg
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetupInitialBed.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SetupInitialBed(double xhat[], double x[], double L) {

    //Declarations
    int i=0;
    
    for (i=1; i <= 21; i++) {
        xhat[i] = 0.05*(i-1);
        x[i] = L*xhat[i];
    }

    return 0;
}