/*
 *  ComputeNormalFlow.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ComputeNormalFlow.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindNormalDepth(double *, int *, double, double, double, double, double);
double fi(double, double, double, double);
double qbstarAM(double);
int FindQsint(double [], double *, double, double, double);

int ComputeNormalFlow(double zeta[], double *Hnorm, double *Hsnorm, double *Gbnorm,
    double *Gsnorm, double *ustarr, double *Hr, double *qsint, double *ksid, double *qbf,
    double *qsf, double *Cnorm, double dzeta, double D90, double D50, double qw,
    double R, double S, double I, double B, double Rep, double vs) {

    double Cznorm=0, kcnorm=0, tausnorm=0, Znorm=0, entnorm=0, qbnorm=0, qsnorm=0, Aa=0.00000057;
    int bombedH=0, check=0;

    check = FindNormalDepth(&(*Hnorm), &bombedH, D90, qw, S, D50, R);
    if (check == 1) 
        return 1;
    Cznorm = qw/((*Hnorm)*sqrt(*Hnorm*S*g));
    kcnorm = 11.0*(*Hnorm)/exp(0.4*Cznorm);
    *Hsnorm = *Hnorm*fi(*Hnorm, qw, S, D90);
    tausnorm = *Hsnorm*S/(R*D50);
    qbnorm = qbstarAM(tausnorm)*sqrt(R*g*D50)*D50;
    *Gbnorm = qbnorm*B*(R+1.0)*31557600*I;
    Znorm = sqrt(*Hsnorm*g*S)*pow(Rep, 0.6)*pow(S, 0.07)/vs;
    entnorm = Aa*pow(Znorm, 5)/(1.0 + Aa*pow(Znorm, 5)/0.3);
    *ustarr = sqrt(*Hnorm*g*S)/vs;
    *Hr = *Hnorm/kcnorm;
    FindQsint(zeta, &(*qsint), *ustarr, *Hr, dzeta);
    qsnorm = entnorm*sqrt(g*(*Hnorm)*S)*(*Hnorm)*(*qsint)/0.4;
    *Cnorm = qsnorm/qw;
    *Gsnorm = qsnorm*B*(R+1)*31557600*I;
    *ksid = *Hnorm;
    *qbf = qbnorm;
    *qsf = qsnorm;

    return 0;
}