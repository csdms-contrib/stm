/*
 *  ComputeBedloadTransportRate.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */


#include "ComputeBedloadTransportRate.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

double qbstarAM(double);

int ComputeBedloadTransportRate(double qb[], double Hs[], double Sf[], double D50,
    double R, int M) {

    int i=0;
    double tausskin=0, tausc=0.05;

    for (i=1; i <= (M+1); i++) {
        tausskin = Hs[i]*Sf[i]/(R*D50);
        if (tausskin > tausc) {
            qb[i] = qbstarAM(tausskin);
        }
        else {
            qb[i] = 0;
        }
        qb[i] = sqrt(R*g*D50)*D50*qb[i];
    }

    return 0;
}