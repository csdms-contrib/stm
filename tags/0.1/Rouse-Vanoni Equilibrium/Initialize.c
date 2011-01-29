/*
 *  Initialize.c
 *  Rouse-Vanoni Equilibrium
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *, double *, double *);

int Initialize(double *init_ratio, double *vs, double *u) {

    ReadIn(&(*init_ratio), &(*vs), &(*u));
    return 0;
    
}