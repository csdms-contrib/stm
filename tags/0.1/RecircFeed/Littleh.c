/*
 *  Littleh.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Littleh.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Littleh(double qw, double Ih, double Slop, double Fro, double Fl) {

    double x1=0, x2=0, x3=0, littleh=0;
    
    x1 = qw*qw/pow(Ih, 3);
    x2 = Slop - x1;
    x3 = 1 - (Fro*Fro)*x1;
    littleh = (x2/(x3*Fl));
    return littleh;
}