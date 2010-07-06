/*
 *  FindNewEta.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewEta.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindNewEta(double eta[], double qb[], double qs[], double *MassIn, double *MassOut,
    double *MassStored, double *FracDisc, double qbf, double qsf, double au, double dt,
    double I, double lamdap, double dx, double R, double B, int M) {

    int i=0;
    double qtback=0, qtfrnt=0, qtit=0, qtdif=0, MassStoreInc=0, etaold[2002];
    
    for (i=1; i <= (M+1); i++) {
        etaold[i] = eta[i];
    }
    for (i=1; i <= M; i++) {
        if (i == 1) {
            qtback = qbf + qsf;
        }
        else {
            qtback = qb[i-1] + qs[i-1];
        }
        qtit = qb[i] + qs[i];
        qtfrnt = qb[i+1] + qs[i+1];
        qtdif = au*(qtback - qtit) + (1.0 - au)*(qtit - qtfrnt);
        eta[i] += dt*qtdif*I/((1.0 - lamdap)*dx);
    }
    qtdif = qb[M] - qb[M+1] + qs[M] - qs[M+1];
    eta[M+1] += dt*qtdif*I/((1.0 - lamdap)*dx);
    *MassIn += au*(qbf + qsf)*B*(R+1.0)*dt*I;
    *MassIn += (1.0 - au)*(qb[1] + qs[1])*B*(R+1.0)*dt*I;
    *MassOut += (qb[M+1] + qs[M+1])*B*(R+1.0)*dt*I;
    MassStoreInc = 0;
    for (i=1; i <= (M+1); i++) {
        MassStoreInc += (eta[i] - etaold[i])*dx*B*(1.0 - lamdap)*(R+1.0);
    }
    *MassStored += MassStoreInc;
    *FracDisc = (*MassIn - *MassStored - *MassOut)/(*MassIn);

    return 0;
}