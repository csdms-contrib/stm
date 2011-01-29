/*
 *  fi.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "fi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

double fi(double Hnorm, double qw, double S, double D90) {

    double fi=0;
    
    fi = pow((qw/(Hnorm*sqrt(g*Hnorm*S)*8.32*pow((Hnorm/(3*D90)), (1.0/6.0)))), 1.5);

    return fi;
}