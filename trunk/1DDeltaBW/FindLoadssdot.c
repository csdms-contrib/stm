/*
 *  FindLoadssdot.c
 *  1DDeltaBW
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindLoadssdot.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindLoadssdot(double tau[], double qb[], double Hfluv[], double *ssdot, double R,
    double D, double tsc, double alphat, double nt, double I, double Sa, double lamdap,
    double sbb, double sss, double Cz, double qw, double alphar, double ks, int M,
    int formulation) {

    int i=0;
    double Cf=0;
    
    for (i=1; i <= (M+1); i++) {
        if (formulation == 1) {
            Cf = 1.0/pow(Cz, 2);
        }
        else {
            Cf = (1.0/(alphar*alphar))*cbrt(ks/Hfluv[i]);
        }
        tau[i] = Cf*pow((qw/Hfluv[i]), 2)/(R*g*D);
        if (tau[i] <= tsc) {
            qb[i] = 0;
        }
        else {
            qb[i] = sqrt(R*g*D)*D*alphat*pow((tau[i] - tsc), nt);
        }
    }
    *ssdot = I*qb[M+1]/(Sa*(1.0 - lamdap)*(sbb - sss));

    return 0;
}