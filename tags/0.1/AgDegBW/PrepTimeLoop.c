/*
 *  PrepTimeLoop.c
 *  AgDegBW
 *
 *  Created by Andrew Leman on 6/4/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "PrepTimeLoop.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int PrepTimeLoop(double eta[], double x[], double ksi[], float *qtg, float dx,
                float S, float qtf, int M, float ksio, float L) {
    //Initialize
    int i=0;
    
    //Run
        //Constants
        *qtg = qtf;
        //Set Initial Bed
        for(i=1; i <= (M+1); i++) {
            x[i] = (dx)*(i-1);
            eta[i] = (S*L)-(S*x[i]);
        }
        ksi[M+1] = ksio;

    //Finalize
    return 0;
}
