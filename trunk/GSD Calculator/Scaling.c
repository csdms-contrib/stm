/*
 *  Scaling.c
 *  GSD Calculator
 *
 *  Created by Andrew Leman on 5/28/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Scaling.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void Scaling(float f[], int terms) {
    //Initialize
    int i=0, check=0;

    //Run
    for(i=0; i <= terms; i++) {
       if (f[i] > 1.01)
            check++;
    }
    if (check != 0) {
        for (i=0; i <= terms; i++){
            f[i]=f[i]/100;
        }
    }
    
    //Finalize
    return;
}