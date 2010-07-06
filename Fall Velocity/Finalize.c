/*
 *  Finalize.c
 *  Fall Velocity
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int WriteOut(float, float, float);

int Finalize(double Rep, double Rf, double velocity) {

    if (Rep > 2500000) {
        printf("Particle Reynolds Number is too high, formulas do not hold!\n");
        }
    else {
        WriteOut(velocity, Rep, Rf);
        printf("Your file has been written.\n");
        }
    return 0;
}