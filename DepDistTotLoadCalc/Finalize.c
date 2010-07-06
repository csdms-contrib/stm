/*
 *  Finalize.c
 *  DepDistTotLoadCalc
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
    double [], double [], double [], double [], double [], double [], double [],
    double [], double [], double [], double [], double [], double [], double [],
    double []);

int Finalize(int N, double Hs[], double tausg[], double U[], double Gamma[], double H[],
    double qw[], double tau[], double ratio[], double Fr[], double u[], double us[],
    double qb[], double Cz[], double kc[], double Zu[], double E[], double I[], double qs[],
    double qt[], double qbqt[], double vsku[]) {

    WriteOut(N, Hs, tausg, U, Gamma, H, qw, tau, ratio, Fr, u, us, qb, Cz, kc, Zu,
        E, I, qs, qt, qbqt, vsku);
    return 0;
}