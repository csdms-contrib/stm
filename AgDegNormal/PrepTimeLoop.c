/*
 *  PrepTimeLoop.c
 *  AgDegNormal
 *
 *  Created by Andrew Leman on 6/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "PrepTimeLoop.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int PrepTimeLoop(double eta[], double x[], float *qtg, float *dx, float S, float qtf, float L, int M) {
    //Initialize
    int i=0;
    
    //Run
        //Constants
        *qtg = qtf;
        *dx = L/M;
        //Set Initial Bed
        for(i=1; i <= (M+1); i++) {
            x[i] = (*dx)*(i-1);
            eta[i] = (S*L)-(S*x[i]);
        }
        eta[M+1] = 0;

    //Finalize
    return 0;
}