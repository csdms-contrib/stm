/*
 *  Finalize.c
 *  Rouse-Vanoni Equilibrium
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(double [], double [], int);

int Finalize(int terms, double zH[], double cb[]) {

    int i=0;
    
    for (i=0; i<terms; i++) {
        printf("%i\t\t%lf\t\t%lf\n", i, zH[i], cb[i]);
    }
    WriteOut(zH, cb, terms);
    printf("Your solutions have been written to the file\n");
    
    return 0;

}