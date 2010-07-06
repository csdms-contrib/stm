/*
 *  FindMovingBoundSpeed.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindMovingBoundSpeed.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindMovingBoundSpeed(double qsand[], double qgrav[], double *sgsdot, double Ifseff,
    double Ifgeff, double Sggs, double Ssgs, double qsandghost, double L, double sgs,
    double dxbars, double dxbarg, double lamps, double lampg, int Mg) {

    *sgsdot = (Ifseff/(Sggs - Ssgs))*((qsand[Mg+1] - qsandghost)/((L-sgs)*dxbars*(1.0 - lamps)));
    *sgsdot += -(Ifgeff/(Sggs - Ssgs))*((qgrav[Mg+1] - qgrav[Mg])/(sgs*dxbarg*(1.0 - lampg)));
    
    return 0;
}