/*
 *  PrepTimeLoop.c
 *  AgDegNormalFault
 *
 *  Created by Andrew Leman on 6/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "PrepTimeLoop.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int PrepTimeLoop(double eta[], double x[], double *qtg, double dx, double S, double qtf,
        double L, int M, double rf, double *ifault) {
    //Initialize
    int i=0;
    
    //Run
        //Ghost node
        *qtg = qtf;
        //Set Initial Bed
        for(i=1; i <= (M+1); i++) {
            x[i] = (dx)*(i-1);
            eta[i] = (S*L)-(S*x[i]);
        }
        eta[M+1] = 0;
        
        //Set fault position
        for (i=1; i <= M; i++) {
            if ((x[i] <= (rf*L)) && (x[i+1] >= (rf*L))) {
                if (((rf*L-x[i])/dx) <= 0.5)
                    *ifault = i;
                else
                    *ifault = (i+1);
            }
        }

    //Finalize
    return 0;
}
