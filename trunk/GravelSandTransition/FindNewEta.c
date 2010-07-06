/*
 *  FindNewEta.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewEta.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindNewEta(double qgrav[], double qsand[], double eta[], double x[], double xbarg[],
    double xbars[], double *sgs, double Yearstart, double Yearstop, double dxbarg,
    double dxbars, double L, double qgravghost, double qsandghost, double subrate,
    double dt, double sgsdot, double Ifgeff, double Ifseff, double lampg, double lamps,
    double *ksid, double ksidot, double time, int Ms, int Mg) {

    double qgravdev=0, etagravdev=0, qsanddev=0, etasanddev=0, xidotdummy=0;
    int i=0;
    
    for (i=1; i <= (Mg); i++) {
        if (i == 1) {
            qgravdev = (qgrav[i] - qgravghost)/(dxbarg*(*sgs));
            etagravdev = (eta[i+1] - eta[i])/(dxbarg*(*sgs));
        }
        else {
            qgravdev = (qgrav[i] - qgrav[i-1])/(dxbarg*(*sgs));
            etagravdev = (eta[i+1] - eta[i-1])/(2.0*dxbarg*(*sgs));
        }
        eta[i] += -subrate*dt;
        eta[i] += (xbarg[i]*sgsdot)*etagravdev*dt;
        eta[i] += -Ifgeff*qgravdev*dt/(1.0 - lampg);
    }
    for (i=(Mg+1); i <= (Mg+Ms+1); i++) {
        if (i == (Mg+1)) {
            qsanddev = (qsand[i] - qsandghost)/(dxbars*(L - *sgs));
            etasanddev = (eta[i+1] - eta[i])/(dxbars*(L - *sgs));
        }
        else if (i == (Mg+Ms+1)) {
            qsanddev = (qsand[i] - qsand[i-1])/(dxbars*(L - *sgs));
            etasanddev = (eta[i] - eta[i-1])/(dxbars*(L - *sgs));
        }
        else {
            qsanddev = (qsand[i] - qsand[i-1])/(dxbars*(L - *sgs));
            etasanddev = (eta[i+1] - eta[i-1])/(2.0*dxbars*(L - *sgs));
        }
        eta[i] += -subrate*dt;
        eta[i] += ((1.0 - xbars[i])*sgsdot)*etasanddev*dt;
        eta[i] += -Ifseff*qsanddev*dt/(1.0 - lamps);
    }

    *sgs += sgsdot*dt;
    for (i=1; i <= Mg; i++) {
        x[i] = dxbarg*(i - 1.0)*(*sgs);
    }
    for (i=(Mg+1); i <= (Mg+Ms+1); i++) {
        x[i] = *sgs + dxbars*(i - Mg - 1.0)*(L - (*sgs));
    }
    
    if ((time+dt) < Yearstart) {
        xidotdummy = 0;
    }
    else if ((time+dt) < Yearstop) {
        xidotdummy = ksidot;
    }
    else {
        xidotdummy = 0;
    }
    
    *ksid += xidotdummy*dt;
    
    return 0;
}