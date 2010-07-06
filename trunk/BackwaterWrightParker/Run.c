/*
 *  Run.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindNormalDepth(double *, double, double, double, double, double);
int FluvialBackwater(double [], double [], double [], double [], double [], double,
    double, double, double, double, double, int);

int Run(double eta [], double H[], double Sf[], double ksi[], double Hs[], double ksid,
    double qw, double dx, double R, double D90s, double D50s, double Sl, int M, double *Hnorm) {
    
    int check=0;
    FindNormalDepth(&(*Hnorm), qw, D90s, D50s, Sl, R);
    check = FluvialBackwater(eta, H, Sf, ksi, Hs, ksid, qw, dx, R, D90s, D50s, M);
    if (check == 1)
        return 1;
    return 0;
    
}