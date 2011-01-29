/*
 *  FindDepthShear.c
 *  AgDegNormal
 *
 *  Created by Andrew Leman on 6/3/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Deparmtent.
 *  All rights reserved.
 */

#include "FindDepthShear.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindDepthShear(double tau[], double H[], int M, float Qf, float kc, float alphar, float B,
                    double Sl[], float D, float R, float Cf, int formulation) {
    //Initialize
    int i=0;

    //Run
    for (i=1; i <= (M+1); i++) {
        if (formulation == 1)
        H[i] = pow(((Qf*Qf*cbrt(kc/1000))/(alphar*alphar*B*B*g*Sl[i])), (3.0/10.0));
        else
        H[i] = cbrt(Qf*Qf*Cf/(g*Sl[i]*B*B));
        tau[i] = (H[i]*Sl[i])/(R*D/1000);
        }
    
    //Finalize
    return 0;

}