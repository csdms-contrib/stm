/*
 *  FindDepth.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindDepth.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Littleh(double, double, double, double, double);

int FindDepth(double etadhat[], double Htil[], double dxhat, double qw, double Fro,
    double etatila, double Fl, int Nreach) {

    //Initialize
    double hend=0, Slop=0, Ih=0, Iht=0;
    int i=0, j=0;
    
    //Run
    hend = (1.0 - etatila) - (0.5 + etadhat[Nreach])/Fl;
    Htil[Nreach] = hend;
    for (i=1; i <= (Nreach - 1); i++) {
        j = Nreach - i + 1;
        Slop = (etadhat[j - 1] - etadhat[j])/dxhat;
        Ih = Htil[j];
        Iht = Ih - dxhat*Littleh(qw, Ih, Slop, Fro, Fl);
        Htil[j-1] = Ih - 0.5*(Littleh(qw, Ih, Slop, Fro, Fl) + Littleh(qw, Iht, Slop, Fro, Fl))*dxhat;
    }
    
    //Finalize
    return 0;
}