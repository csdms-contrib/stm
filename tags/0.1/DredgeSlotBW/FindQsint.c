/*
 *  FindQsint.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/28/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindQsint.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindQsint(double zeta[], double *qsint, double ustarr, double Hr, double dzeta) {

    int i=0, nconc=50;
    double zetab=0.05, slr[53];

    for (i=1; i <= (nconc+1); i++) {
        if (zeta[i] == 1.0) {
            slr[i] = 0;
        }
        else {
            slr[i] = pow((((1.0 - zeta[i])/zeta[i])/((1.0 - zetab)/zetab)), (1.0/(0.4*ustarr)))*log(30.0*Hr*zeta[i]);
        }
    }
    *qsint = 0;
    for (i=1; i <= nconc; i++) {
        *qsint += 0.5*(slr[i] + slr[i+1])*dzeta;
    }

    return 0;
}