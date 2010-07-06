/*
 *  Chezy Formulation.c
 *  Backwater Calculator
 *
 *  Created by Andrew Leman on 5/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Chezy Formulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int ChezyFormulation(float S, float Cz, float qw, float *H, float *U, float *Fr, float *taub) {
    //Initialize
    float arg=0;
    
    //Run
        //Compute H (m)
        arg = (pow(qw, 2))/((pow(Cz, 2))*g*S);
        *H = cbrt(arg);
        
        //Compute U (m/s)
        *U = (qw/(*H));
        
        //Compute Fr
        *Fr = (*U)/(sqrt(g*(*H)));
        
        //Compute τ(b)
        *taub = 1000*((pow(*U, 2))/(pow(Cz, 2)));
    
    //Finalize
    return 0;
}