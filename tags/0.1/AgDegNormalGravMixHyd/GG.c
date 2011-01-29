/*
 *  GG.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "GG.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double GG(double phi) {
//Initialize
    double G=0, Mo=14.2;
    
//Run
    if(phi < 1.0) 
        G = exp(log(phi)*Mo);
    else if(phi <= 1.59)
        G = exp(Mo*(phi - 1.0) - 9.28*pow((phi - 1.0), 2));
    else
        G = 5474*exp(4.5*log(1.0-(0.853/phi)));

//Finalize
    return G;
}

