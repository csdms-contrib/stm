/*
 *  Bigh1.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/14/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Bigh1.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Bigh1(double qw, double Ih, double Fro, double Slop, double Fl, double bh1) {

    double x1=0, x2=0, x3=0, x4=0, bigh1=0;
    
    x1 = qw*qw/pow(Ih, 3.0);
    x2 = (x1/Ih)*bh1;
    x3 = 3.0*x2/(1.0 - (Fro*Fro*x1));
    x4 = Fro*Fro*(x1 - Slop)/(1 - (Fro*Fro*x1));
    bigh1 = x3*(1.0 + x4)/Fl;

    return bigh1;
}