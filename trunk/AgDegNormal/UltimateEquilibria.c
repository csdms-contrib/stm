/*
 *  UltimateEquilibria.c
 *  AgDegNormal
 *
 *  Created by Andrew Leman on 6/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "UltimateEquilibria.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int UltimateEquilibria(float *qtf, float *tauult, float *Sult, float *Hult, float Gtf,
                        float R, float If, float B, float tauc, float D, float alphat,
                        float nt, float phis, float alphar, float Qf, float kc, float Cf,
                        int formulation, float S) {
    //Initialize
    float exponent1=(10.0/7.0), exponent2=(3.0/7.0), arg1=0, arg2=0;
    
    //Run
    *qtf = Gtf/((R+1)*60*60*24*365.25*B*If);
    *tauult = (tauc + pow((*qtf/(sqrt(g*R*D/1000)*D*alphat/1000)),(1/nt)))/phis;
    if (formulation == 1) {
        arg1 = (R*D*(*tauult)/1000);
        arg2 = ((alphar*alphar*B*B*g)/(Qf*Qf*cbrt(kc/1000)));
        *Sult = pow(arg1, exponent1)*pow(arg2, exponent2);
    }
    else {
        arg1 = (R*D*(*tauult)/1000)*cbrt(g*B*B/(Qf*Qf*Cf));
        *Sult = pow(arg1, 1.5);
    }
    *Hult = R*D*(*tauult)/(1000*(*Sult));
    
    //Finalize
    return 0;
}