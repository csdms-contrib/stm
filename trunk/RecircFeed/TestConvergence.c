/*
 *  TestConvergence.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/14/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "TestConvergence.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int TestConvergence(double Htilendnew, double *Htilend, int *converged) {

    double err=0, epdepth=0.0001;
    
    err = 2*fabs((Htilendnew - *Htilend)/(Htilendnew + *Htilend));
    if (err < epdepth)
        *converged = 1;
    else 
        *Htilend = Htilendnew;
        
    return 0;
}