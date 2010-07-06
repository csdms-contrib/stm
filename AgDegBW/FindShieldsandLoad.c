/*
 *  FindShieldsandLoad.c
 *  AgDegBW
 *
 *  Created by Andrew Leman on 6/5/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindShieldsandLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindShieldsandLoad(double tau[], double qb[], int M, float Cf, float alphar,
                        double H[], float kc, float qw, float R, float D,
                        float tauc, float nt, float phis, float alphat, int formulation) {
    //Initialize
    int i=0;
    float Cf1=0, qstar=0;
    
    //Run
    for(i=1; i <= (M+1); i++) {
        if(formulation == 1)
            Cf1 = (1/pow(alphar, 2))*pow((kc/H[i]), (1.0/3.0));
        else
            Cf1 = Cf;
        tau[i] = Cf1*pow((qw/H[i]),2)/(R*g*D);
        if (tau[i] > tauc)
            qstar = alphat*pow((phis*tau[i]-tauc),nt);
        else
            qstar = 0;
        qb[i] = pow((R*g*D), 0.5)*D*qstar;
    }
    
    //Finalize
    return 0;
}