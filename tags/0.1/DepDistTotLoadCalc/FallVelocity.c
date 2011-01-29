/*
 *  FallVelocity.c
 *  DepDistTotLoadCalc
 *
 *  Created by Andrew Leman on 7/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */
 
#include "FallVelocity.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FallVelocity(double *Rep, double *Rf, double *vs, double D50s, double R, double nu) {

    *Rep = sqrt(981*R*D50s/10)*(D50s/10)/(10000*nu);
    *Rf = exp(-2.891394+0.95296*log(*Rep)-0.056835*pow((log(*Rep)), 2)-0.002892*pow((log(*Rep)), 3)+0.000245*pow((log(*Rep)), 4));
    *vs = sqrt(981*R*D50s/10)*(*Rf);
    return 0;
}