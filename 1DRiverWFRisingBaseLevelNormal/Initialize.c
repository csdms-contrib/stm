/*
 *  Initialize.c
 *  1DRiverWFRisingBaseLevelNormal
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double [], double [], double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    int *, int *, int *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *);
int SetInitialBedandTime(double [], double [], double, double, double, int);
int FindSlopeandLoad(double [], double [], double [], double [], double [], double,
    double, double, double, double, double, int);

int Initialize(double Qt[], double Sl[], double x[], double eta[], double *Qf, double *Qbtffeed, double *lambig,
    double *I, double *D, double *R, double *L, double *Bf, double *Sinu, double *lamp,
    double *Cz, double *Sfbl, double *etaddot, int *M, int *prints, int *iterates, double *dt,
    double *Yearstart, double *Yearstop, double *aleh, double *neh, double *tausforms,
    double *alp, double *np, double *tausc, double *tausformg, double *Cf, double *rform,
    double *tausform, double *loadcoef, double *widthcoef, double *depthcoef, double *dx,
    double Bbf[], double Hbf[]) {

    //Declarations
    int check=0;
    
    check = ReadIn(Qt, Sl, &(*Qf), &(*Qbtffeed), &(*lambig), &(*I), &(*D), &(*R), &(*L),
            &(*Bf), &(*Sinu), &(*lamp), &(*Cz), &(*Sfbl), &(*etaddot), &(*M), &(*prints),
            &(*iterates), &(*dt), &(*Yearstart), &(*Yearstop), &(*aleh), &(*neh),
            &(*tausforms), &(*alp), &(*np), &(*tausc), &(*tausformg), &(*Cf), &(*rform),
            &(*tausform), &(*loadcoef), &(*widthcoef), &(*depthcoef), &(*dx));
    if (check == 1) 
        return 1;
        
    SetInitialBedandTime(x, eta, *Sfbl, *L, *dx, *M);
    
    FindSlopeandLoad(Sl, eta, Qt, Bbf, Hbf, *dx, *loadcoef, *widthcoef, *depthcoef, *D, *Qf, *M);

    return 0;
}