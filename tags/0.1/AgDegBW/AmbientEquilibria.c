/*
 *  AmbientEquilibria.c
 *  AgDegBW
 *
 *  Created by Andrew Leman on 6/4/09.
 *  Copyright 2009 The University of Illinos-Civil Engineering Department.
 *  All rights reserved.
 *
 */

#include "AmbientEquilibria.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int AmbientEquilibria(float *Ha, float *taustar, float *qstar, float *qt, float *Gt,
                        float Qf, float kc, float alphar, float S, float B, float R,
                        float alphat, float phis, float nt, float If, float D, float tauc,
                        float Cf, int formulation) {
    //Initialize
    
    //Run
        //calculates depth based on what formulation is desired
        if (formulation == 1)
        *Ha = pow((((pow(Qf,2))*(cbrt(kc)))/(pow(alphar, 2)*g*S*pow(B,2))), 0.3);
        else
        *Ha = cbrt(Qf*Qf*Cf/(g*S*B*B));
        //calculates the shield's number, einstein's number, etc.
        *taustar = ((*Ha)*S)/(R*D);
        if (phis*(*taustar) <= tauc)
        *qstar = 0;
        else
        *qstar = alphat*(pow((phis*(*taustar)-tauc),nt));
        *qt = (*qstar)*sqrt(g*R*D)*D;
        *Gt = (*qt)*B*60*60*24*365.25*(1+R)*If;
    
    //Finalize
    return 0;
}
