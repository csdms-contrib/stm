/*
 *  FindSlopes.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindSlopes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindSlopes(double Sgrav[], double Ssand[], double eta[], double Sl[], double x[],
    double *Sbgb, double *Sggs, double *Ssgs, double *Ssd, int Mg, int Ms) {

    int i=0;
    
    for (i=1; i <= (Mg+1); i++) {
        if (i == 1) {
            Sgrav[i] = (eta[i] - eta[i+1])/(x[i+1] - x[i]);
        }
        else if (i == (Mg + 1)) {
            Sgrav[i] = (eta[i-1] - eta[i])/(x[i] - x[i-1]);
        }
        else {
            Sgrav[i] = (eta[i-1] - eta[i+1])/(x[i+1] - x[i-1]);
        }
    }
    for (i = (Mg+1); i <= (Mg+Ms+1); i++) {
        if (i == (Mg+1)) {
            Ssand[i] = (eta[i] - eta[i+1])/(x[i+1]-x[i]);
        }
        else if (i == (Mg+Ms+1)) {
            Ssand[i] = (eta[i-1] - eta[i])/(x[i] - x[i-1]);
        }
        else {
            Ssand[i] = (eta[i-1] - eta[i+1])/(x[i+1] - x[i-1]);
        }
    }
    *Sbgb = Sgrav[1];
    *Sggs = Sgrav[Mg+1];
    *Ssgs = Ssand[Mg+1];
    *Ssd = Ssand[Mg+Ms+1];
    
    for (i=1; i <= (Mg+1); i++) {
        Sl[i] = Sgrav[i];
    }
    for (i=(Mg+2); i <= (Ms+Mg+1); i++) {
        Sl[i] = Ssand[i];
    }
    Sl[Mg+Ms+2] = Ssand[Mg+1];

    return 0;
}