/*
 *  ComputeNormalFlow.c
 *  1DDeltaBW
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */
 
#include "ComputeNormalFlow.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int ComputeNormalFlow(double *tsn, double *Sn, double *Hn, double *Frn, double qtf,
    double alphat, double D, double R, double nt, double tsc, double Cz, double qw,
    double ksid, double etasl, double alphar, double ks, int formulation) {

    double Hcrit=0, Hi=0, Cf=0;

    *tsn = pow((qtf/(alphat*D*sqrt(R*g*D))), (1.0/nt)) + tsc;
    if(formulation == 1) {
        Cf = 1.0/pow(Cz, 2);
        *Sn = Cz*pow((R*D*(*tsn)), 1.5)*sqrt(g)/qw;
    }
    else {
        *Sn = pow((*tsn*R*D), (10.0/7.0))*pow((alphar*alphar*g/(cbrt(ks)*qw*qw)),(3.0/7.0));
    }
    *Hn = R*D*(*tsn)/(*Sn);
    *Frn = (qw/(*Hn))/sqrt(9.81*(*Hn));
    if (*Frn >= 1)
        return 1;
    Hi = ksid - etasl;
    Hcrit = cbrt(qw*qw/g);
    if (Hi < Hcrit) {
        printf("Hi must be greater than Hcrit for backwater calculation:\nHi = %lf\nHcrit = %lf\n", Hi, Hcrit);
        return 1;
    }
    
    return 0;
}