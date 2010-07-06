/*
 *  DownstreamCondition.c
 *  AgDegBW
 *
 *  Created by Andrew Leman on 6/8/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "DownstreamCondition.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int DownstreamCondition(double *Frni, double *Frnu, double *Hc, double *ksimin,
                        double *ksiinit, float Qf, float B, float Ha, float Hult) {
    //Initialize
    
    //Run
    *Frni = sqrt((Qf*Qf)/(g*B*B*pow(Ha, 3)));
    *Frnu = sqrt((Qf*Qf)/(g*B*B*pow(Hult, 3)));
    *Hc = cbrt(Qf*Qf/(B*B*g));
    *ksimin = *Hc;
    *ksiinit = Ha;
    if ((*Frni > 1) || (*Frnu > 1))
        return 1;
    
    //Finalize
    return 0;
}