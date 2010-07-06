/*
 *  Run.c
 *  Rouse-Vanoni Equilibrium
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int RouseVanoni(double, double, double, double [], double []);
int RouseVanoniuserdefined(double, double, double, double [], double []);

int Run(double init_ratio, double vs, double u, double zH[], double cb[], int *terms) {

    int choice=0;
    
    //User chooses predefined points or number of iterations
    
    printf("Enter \n 1. To choose number of iterations\n 2. To use predefined number of iterations\n");
    scanf("%i", &choice);
    switch(choice) {
        case 1:
            *terms = RouseVanoniuserdefined(init_ratio, vs, u, zH, cb);
            break;
        case 2:
            *terms = RouseVanoni(init_ratio, vs, u, zH, cb);
            break;
        default:
            printf("Improper Response!");
            return 1;
    }
    return 0;

}