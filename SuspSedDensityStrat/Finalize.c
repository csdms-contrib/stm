/*
 *  Finalize.c
 *  SuspSedDensityStrat
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [], double [], double [], double [], double [], double [], double,
    double, double, double, double, double);

int Finalize(double zeta[], double initun[], double initcn[], double un[], double cn[],
    double Ri[], double unao, double cnao, double qso, double una, double cna,
    double qs, int bombed) {

    //Initialize
    
    //Run
    if (bombed == 1) {
        printf("The calculation failed to converge.  Please edit data and try again.\n");
        return 1;
    }
    else {
        WriteOut(zeta, initun, initcn, un, cn, Ri, unao, cnao, qso, una, cna, qs);
    }
    
    //Finalize
    return 0;
}