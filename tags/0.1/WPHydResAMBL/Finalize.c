/*
 *  Finalize.c
 *  WPHydResAMBL
 *
 *  Created by Andrew Leman on 7/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(int, double [], double [], double [], double [], double [], double [],
    double [], double [], double [], double [], double [], double []);

int Finalize(int N, double Hs[], double tausg[], double U[], double Gamma[], double H[],
    double qw[], double tau[], double ratio[], double Fr[], double u[], double us[],
    double qb[]) {

    WriteOut(N, Hs, tausg, U, Gamma, H, qw, tau, ratio, Fr, u, us, qb);
    return 0;
}