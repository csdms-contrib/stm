/*
 *  EndpointChecker.c
 *  Acronym1R
 *
 *  Created by Andrew Leman on 6/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "EndpointChecker.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float D;
    float pfs;
} pair;

int EndpointChecker(pair data[], int *npp, int *np) {
    //Initialize
    int i=0, count1=0, count2=0;
    float psi[3];
    
    //Run
    for (i=0; i < *npp; i++) {
        if (fabs(100.0-data[i].pfs) < 0.00001)
        count1++; 
        else if (data[i].pfs < 0.00001)
        count2++;
    }
    
    if (count1 == 0) {
        psi[1] = (log(data[*npp-1].D))/(log(2));
        psi[0] = (log(data[*npp-2].D))/(log(2));
        psi[2] = psi[1] + ((psi[1]-psi[0])/(data[*npp-1].pfs - data[*npp-2].pfs))*(100 - data[*npp-1].pfs);
        data[*npp].D = pow(2, psi[2]);
        data[*npp].pfs = 100.0;
        *npp = *npp + 1;
    }
    
    if (count2 == 0) {
        psi[1] = (log(data[1].D))/(log(2));
        psi[0] = (log(data[0].D))/(log(2));
        psi[2] = psi[0] - ((psi[1] - psi[0])/(data[1].pfs - data[0].pfs))*(data[0].pfs);
        data[*npp].D = pow(2, psi[2]);
        data[*npp].pfs = 0.0;
        *npp = *npp + 1;
    }
    
    *np = *npp - 1;
    
    //Finalize
    return 0;
}