/*
 *  FindSlopes.c
 *  AgDegBW
 *
 *  Created by Andrew Leman on 7/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindSlopes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindSlopes(double Sl[], int M, double eta[], float dx) {
    //Initialize
    int i=0;
    
    //Run
        for (i=1; i <= (M+1); i++) {
            if (i == 1)
                Sl[i] = (eta[1]-eta[2])/dx;
            else if (i == (M+1))
                Sl[i] = (eta[M]-eta[M+1])/dx;
            else
                Sl[i] = (eta[i-1]-eta[i+1])/(2*dx);
            }
    
    //Finalize
    return 0;
}
