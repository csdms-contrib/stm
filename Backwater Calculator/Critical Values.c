/*
 *  Critical Values.c
 *  Backwater Calculator
 *
 *  Created by Andrew Leman on 5/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Critical Values.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int CriticalValues(float qw, float *H, float *U) {
    //Initialize
    
    //Run
    *H = cbrt((pow(qw, 2))/g);
    *U = qw/(*H);
    
    //Finalize
    return 0;
}