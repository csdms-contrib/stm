/*
 *  FindNewSbb.c
 *  1DDeltaBW
 *
 *  Created by Andrew Leman on 7/17/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewSbb.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindNewSbb(double x[], double eta[], double *sbdot, double *sbb, double *etabot,
    double sfmax, double time, double ssdot, double etasdot, double Sa, double Sb,
    double dt, int *bombed, int M) {

    *sbdot = (Sa*ssdot + etasdot)/(Sa - Sb);
    *sbb += *sbdot*dt;
    *etabot += -Sb*(*sbdot)*dt;
    if (*sbb > sfmax) {
        printf("The toe prograded past the sfmax\ntime: %lf\nsbb: %lf\nsfmax: %lf\n", (time/31557600.0), (*sbb), sfmax);
        *bombed = 1;
    }
    else {
        x[M+2] = *sbb;
        eta[M+2] = *etabot;
    }

    return 0;
}