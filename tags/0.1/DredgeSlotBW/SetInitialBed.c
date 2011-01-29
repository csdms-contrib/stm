/*
 *  SetInitialBed.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/28/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetInitialBed.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SetInitialBed(double x[], double eta[], double ksi[], double *MassIn, double
    *MassStored, double *MassOut, double *FracDisc, double dx, double S, double L,
    double ksid, double ru, double rd, double Hslot, int M) {

    int i=0, iup=0, idwn=0;
    
    for (i=1; i <= (M+1); i++) {
        x[i] = dx*(i-1);
        eta[i] = S*L - S*x[i];
    }
    ksi[M+1] = ksid;
    for (i=1; i <= (M+1); i++) {
        if ((x[i] <= ru*L) && (x[i+1] >= ru*L)) {
            if (((ru*L - x[i])/dx) <= 0.5) {
                iup = i;
            }
            else {
                iup = i + 1;
            }
        }
        if ((x[i] <= rd*L) && (x[i+1] >= rd*L)) {
            if (((rd*L - x[i])/dx) <= 0.5) {
                idwn = i;
            }
            else {
                idwn = i + 1;
            }
        }
    }
    for (i=1; i <= (M+1); i++) {
        if ((i >= iup) && (i <= idwn)) {
            eta[i] += -Hslot;
        }
    }
    *MassIn = 0;
    *MassStored = 0;
    *MassOut = 0;
    *FracDisc = 0;

    return 0;
}