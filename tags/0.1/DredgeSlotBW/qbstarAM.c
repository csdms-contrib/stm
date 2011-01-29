/*
 *  qbstarAM.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "qbstarAM.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double qbstarAM(double taus) {

    double qbstarAM=0, tausc=0.05;

    if (taus <= tausc) {
        qbstarAM = 0;
    }
    else {
        qbstarAM = 17.0*(taus - tausc)*(sqrt(taus) - sqrt(tausc));
    }

    return qbstarAM;
}