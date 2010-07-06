/*
 *  FaultBed.c
 *  AgDegNormalFault
 *
 *  Created by Andrew Leman on 6/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Deparmtent.
 *  All rights reserved.
 */

#include "FaultBed.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FaultBed(double tf, double time, int *notfaultedyet, double ifault, int M,
        double eta[], double deltaeta, double dt) {
    //Initialize
    int i=0;
    
    //Run
    
    //If the time is less than the fault time, or if the fault time
    //and if one more iteration is past the fault time--fault the bed
    if (((time <= tf) || (tf == 0)) && (time + (dt/(3600*24*365.25)) >= tf)) {
        *notfaultedyet = 0;
        for (i=ifault; i <= (M+1); i++) {
            eta[i] -= deltaeta;
        }
    }
    
    //Finalize
    return 0;
}