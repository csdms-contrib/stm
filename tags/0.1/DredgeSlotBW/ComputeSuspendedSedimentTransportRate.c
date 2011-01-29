/*
 *  ComputeSuspendedSedimentTransportRate.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ComputeSuspendedSedimentTransportRate.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindQsint(double [], double *, double, double, double);

int ComputeSuspendedSedimentTransportRate(double qs[], double Hs[], double Sf[],
    double H[], double Ent[], double zeta[], double *ustarr, double *Hr, double *qsint,
    double vs, double Rep, double qw, double dzeta, int M) {

    int i=0;
    double Z=0, Cz=0, kc=0, Aa=0.00000057;
    
    for (i=1; i <= (M+1); i++) {
        if (Sf[i] <= 0) {
            Ent[i] = 0;
            qs[i] = 0;
        }
        else {
            Z = (sqrt(g*Hs[i]*Sf[i])/vs)*pow(Rep, 0.6)*pow(Sf[i], 0.07);
            Ent[i] = Aa*pow(Z, 5)/(1 + Aa*pow(Z, 5)/0.3);
            Cz = qw/(H[i]*sqrt(g*H[i]*Sf[i]));
            kc = 11.0*H[i]/exp(0.4*Cz);
            *ustarr = sqrt(g*H[i]*Sf[i])/vs;
            *Hr = H[i]/kc;
            FindQsint(zeta, &(*qsint), *ustarr, *Hr, dzeta);
            qs[i] = Ent[i]*H[i]*sqrt(g*H[i]*Sf[i])*(*qsint)/0.4;
        }
    }

    return 0;
}