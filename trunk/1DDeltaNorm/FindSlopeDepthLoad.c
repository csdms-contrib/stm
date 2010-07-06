/*
 *  FindSlopeDepthLoad.c
 *  1DDeltaNorm
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindSlopeDepthLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindSlopeDepthLoad(double Sl[], double eta[], double H[], double tau[], double qb[],
    double *ssdot, double *sbdot, double etasl, double I, double lamdap, double sbb, 
    double Sa, double Sb, double dxbar, double sss, double qw, double Cz, double ks,
    double alphar, double alphat, double tsc, double nt, double R, double D, int formulation,
    int M) {

    //Declarations
    int i=0;

    //Find Slope
    Sl[1] = (eta[1] - eta[2])/(dxbar*sss);
    Sl[M+1] = (eta[M] - eta[M+1])/(dxbar*sss);
    for (i=2; i <= M; i++) {
        Sl[i] = (eta[i-1] - eta[i+1])/(2*dxbar*sss);
    }
    //Find Depth, Shear, Load
    for (i=1; i <= (M+1); i++) {
        if (formulation == 1) {
            H[i] = cbrt(qw*qw/(Cz*Cz*g*Sl[i]));
        }
        else {
            H[i] = pow((qw*qw*cbrt(ks)/(g*Sl[i]*alphar*alphar)), 0.3);
        }
        tau[i] = H[i]*Sl[i]/(R*D);
        qb[i] = alphat*pow((tau[i] - tsc), nt)*D*sqrt(R*g*D);
    }
    //Change the endpoint
    eta[M+1] = etasl;
    *ssdot = I*qb[M+1]/(Sa*(1.0-lamdap)*(sbb-sss));
    *sbdot = Sa*(*ssdot)/(Sa-Sb);
    
    return 0;
}