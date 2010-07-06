/*
 *  Run.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int BedExner(double [], double [], double *, double *, double *, double, double,
    double, double, int, int);
int Backwater(double [], double [], double [], double, double, double, double, double,
    double *, double, int *, int, int);
int Load(double [], double [], double, double, int);
int ComputeError(double [], double [], double, int *, int);

int Run(double SNupvector[], double SNdownvector[], double etadhat[], double qtil[],
    double Htil[], double Sl[], double bgh1[], double *etatila, double *SNup, double *SNdown,
    int *SNcounter, int *equilibriates, double dt, double qtilg, double Fl,
    double dxhat, double qw, double Fro, double taur, double nt, double *Htilend,
    double timehat, int Nreach, int k, int m, int flume, int *bombed) {

    if ((k==1) && (m==1)) {
        SNupvector[*SNcounter] = *SNup;
        SNdownvector[*SNcounter] = *SNdown;
        (*SNcounter)++;
    }

    BedExner(etadhat, qtil, &(*etatila), &(*SNup), &(*SNdown), dt, qtilg, Fl, dxhat, Nreach, flume);
        SNupvector[*SNcounter] = *SNup;
        SNdownvector[*SNcounter] = *SNdown;
        (*SNcounter)++;
    Backwater(etadhat, Htil, bgh1, dxhat, qw, Fro, *etatila, Fl, &(*Htilend), timehat, &(*bombed), Nreach, flume);
    if (*bombed == 1) {
        printf("Calculations failed to converge.\n");
        return 1;
    }
    Load(Htil, qtil, taur, nt, Nreach);
    ComputeError(Sl, etadhat, dxhat, &(*equilibriates), Nreach);
    return 0;
}