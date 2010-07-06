/*
 *  FindHbgh.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/14/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindHbgh.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Littleh(double, double, double, double, double);
double Bigh1(double, double, double, double, double, double);

int FindHbgh(double Htil[], double etadhat[], double bgh1[], double qw, double Fro,
    double Fl, double *Htilend, double dxhat, double timehat, int Nreach, int k) {

    //Declarations
    double Slop=0, Ih=0, bh1=0, Iht=0, bh1t=0;
    int i=0, j=0;
    
    //Run
    if ((timehat == 0) && (k == 2)) {
       *Htilend = 1; 
    }
    Htil[Nreach] = *Htilend;
    bgh1[Nreach] = 1;
    for (i=1; i <= (Nreach - 1); i++) {
        j = Nreach - i + 1;
        Slop = (etadhat[j-1] - etadhat[j])/dxhat;
        Ih = Htil[j];
        bh1 = bgh1[j];
        Iht = Ih - dxhat*Littleh(qw, Ih, Slop, Fro, Fl);
        bh1t = bh1 - dxhat*Bigh1(qw, Ih, Fro, Slop, Fl, bh1);
        Htil[j-1] = Ih - 0.5*(Littleh(qw, Ih, Slop, Fro, Fl) + Littleh(qw, Iht, Slop, Fro, Fl))*dxhat;
        bgh1[j-1] = bh1 - 0.5*(Bigh1(qw, Ih, Fro, Slop, Fl, bh1) + Bigh1(qw, Iht, Fro, Slop, Fl, bh1t))*dxhat;
    }
    
    //Finalize
    return 0;
}