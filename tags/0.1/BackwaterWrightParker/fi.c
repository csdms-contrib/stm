/*
 *  fi.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "fi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

double fi(double arg, double qw, double Sl, double D90s) {
    double fi=0;
    fi = pow((qw/(arg*sqrt(g*arg*Sl)*8.32*pow((arg/(3.0*D90s)), (1.0/6.0)))), 1.5);
    return fi;
}
