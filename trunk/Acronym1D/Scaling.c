/*
 *  Scaling.c
 *  Acronym1D
 *
 *  Created by Andrew Leman on 6/17/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Scaling.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct  {
    float D;
    float pfs;
} pair;

void Scaling(pair data[], int npp) {
    //Initialize
    int i=0, check=0;

    //Run
    for(i=0; i < npp; i++) {
       if (data[i].pfs <= 1.01)
            check++;
    }
    if (check == (npp)) {
        for (i=0; i < npp; i++){
            data[i].pfs = data[i].pfs*100;
        }
    }
    
    //Finalize
    return;
}
