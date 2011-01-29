/*
 *  Initialize.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
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
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, int *, int *, int *, int *);
int SetupInitialBed(double [], double [], double [], double [], double *, double,
    double, double, double, double, double, int, int);

int Initialize(double xbarg[], double x[], double eta[], double xbars[], double *sgs,
    double *Qbf, double *L, double *sgsl, double *ksid, double *ksidot, double *subrate,
    double *Yearstart, double *Yearstop, double *dt, double *qfeeds, double *qfeedg,
    double *Ifs, double *Ifg, double *Ds, double *Dg, double *Czs, double *Czg,
    double *Bs, double *Bg, double *Ssl, double *Sgl, double *Bds, double *Bdg, double *Omegas,
    double *Omegag, double *lamdams, double *lamdasg, double *Cfs, double *Cfg,
    double *sfsl, double *dxbars, double *dxbarg, double *qwg, double *qws, double *qfg,
    double *qfs, double *rBg, double *rBs, double *Ifgeff, double *Ifseff, double *R,
    double *lamps, double *lampg, int *prints, int *iterates, int *Ms, int *Mg) {

    int check=0;
    
    check = ReadIn(&(*Qbf), &(*L), &(*sgsl), &(*ksid), &(*ksidot), &(*subrate),
                &(*Yearstart), &(*Yearstop), &(*dt), &(*qfeeds), &(*qfeedg),
                &(*Ifs), &(*Ifg), &(*Ds), &(*Dg), &(*Czs), &(*Czg), &(*Bs),
                &(*Bg), &(*Ssl), &(*Sgl), &(*Bds), &(*Bdg), &(*Omegas),
                &(*Omegag), &(*lamdams), &(*lamdasg), &(*Cfs), &(*Cfg), &(*sfsl),
                &(*dxbars), &(*dxbarg), &(*qwg), &(*qws), &(*qfg), &(*qfs),
                &(*rBg), &(*rBs), &(*Ifgeff), &(*Ifseff), &(*R), &(*lamps),
                &(*lampg), &(*prints), &(*iterates), &(*Ms), &(*Mg));
    if (check == 1)
        return 1;
        
    SetupInitialBed(xbarg, x, eta, xbars, &(*sgs), *sgsl, *Ssl, *sfsl, *dxbars, *Sgl, *dxbarg, *Mg, *Ms);

    return 0;
}