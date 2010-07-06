/*
 *  ReOrder.c
 *  Acronym1R
 *
 *  Created by Andrew Leman on 6/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Reorder.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Defining the pair struct again

typedef struct {
    float D;
    float pfs;
} pair;

//Compare function used by qsort

int compare(float *ptr1, float *ptr2) {
    if (*ptr1 > *ptr2)
        return 1;
    else if (*ptr1 < *ptr2)
        return -1;
    else
        return 0;
}

int Reorder(pair data[], int npp, int nppo) {
    //Initialize
    
    //Run
    if (nppo != 0)
    qsort(data, nppo, sizeof(data[0]), compare);
    else
    qsort(data, npp, sizeof(data[0]), compare);
    
    //Finalize
    return 0;
}