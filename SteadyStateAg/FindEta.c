/*
 *  FindEta.c
 *  SteadyStateAg
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindEta.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindEta(double printmatrix[][22], double etadev[], double ksid, double ksidot,
    double time, int k) {

    int j=0;
    
        for (j=1; j <= 21; j++) {
            printmatrix[k][j] = ksid + (ksidot/1000)*time + etadev[j];
        }
        printmatrix[k][0] = time;

    return 0;
}