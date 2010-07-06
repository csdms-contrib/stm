/*
 *  ManningStricklerFormulation.c
 *  Backwater Calculator
 *
 *  Created by Andrew Leman on 5/29/09.
 *
 */

#include "ManningStricklerFormulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int ManningStricklerFormulation(float S, float qw, float nk, float Ds90, float alphar,
                                float R, float Dmean, float *H, float *U, float *Fr,
                                float *taub) {
    //Initialize
    float arg=0, kc=0;
    
    //Run
        //Compute kc
        kc = nk*Ds90;
        
        //Compute H (m)
        arg = ((pow(qw, 2))*cbrt(kc))/(g*S*alphar*alphar);
        *H = pow(arg, 0.3);
        
        //Compute U (m/s)
        *U = qw/(*H);
        
        //Compute Fr
        *Fr = (*U)/(sqrt(g*(*H)));
        
        //Compute τ(b)
        arg = arg*S;
        *taub = (pow(arg, 0.3))*(pow(S, 0.7))/(R*Dmean);
    
    //Finalize
    return 0;

}
