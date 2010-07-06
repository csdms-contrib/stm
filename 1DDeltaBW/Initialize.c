/*
 *  Initialize.c
 *  1DDeltaBW
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    int *, int *, int *, int *);
int SetupInitialBedandTime(double [], double [], double [], double [], double [],
    double *, double *, double *, double *, double *, double *, double *, double,
    double, double, double, double, double, double, double, int);
int ComputeNormalFlow(double *, double *, double *, double *, double, double, double,
    double, double, double, double, double, double, double, double, double, int);

int Initialize(double xfbar[], double xfluv[], double etafluv[], double x[], double eta[],
    double *qw, double *I, double *qtf, double *D, double *Cz, double *nt, double *tsc,
    double *etasl, double *etabl, double *Sfi, double *Sb, double *Sa, double *ssfi,
    double *R, double *lamdap, double *ks, double *alphat, double *alphar, double *dt,
    double *dxbar, double *Cf, double *sfmax, double *ksid, double *Volinit, double *abase,
    double *etasdot, double *etabot, double *etatop, double *sss, double *sbb, double *tsn,
    double *Sn, double *Hn, double *Frn, int *M, int *prints, int *iterates, int *formulation) {

    int check=0;
    
    check = ReadIn(&(*qw), &(*I), &(*qtf), &(*D), &(*Cz), &(*nt), &(*tsc), &(*etasl),
                &(*etabl), &(*Sfi), &(*Sb), &(*ssfi), &(*Sa), &(*R), &(*lamdap), &(*ks),
                &(*alphat), &(*alphar), &(*dt), &(*dxbar), &(*Cf), &(*sfmax), &(*ksid),
                &(*M), &(*prints), &(*iterates), &(*formulation));
    if (check == 1)
        return 1;
        
    SetupInitialBedandTime(xfbar, xfluv, etafluv, x, eta, &(*sss), &(*sbb), &(*etatop),
        &(*etabot), &(*etasdot), &(*abase), &(*Volinit), *dxbar, *ssfi, *Sa, *Sb,
        *lamdap, *etasl, *etabl, *Sfi, *M);
        
    check = ComputeNormalFlow(&(*tsn), &(*Sn), &(*Hn), &(*Frn), *qtf, *alphat, *D, *R, *nt,
                *tsc, *Cz, *qw, *ksid, *etasl, *alphar, *ks, *formulation);
    if (check == 1)
        return 1;

    return 0;
}