/*
 *  Reorder.c
 *  AgDegNormGravMixPW
 *
 *  Created by Andrew Leman on 6/18/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Reorder.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Defining the pair struct again

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

//Compare function used by qsort

int compare(double *ptr1, double *ptr2) {
    if (*ptr1 > *ptr2)
        return -1;
    else if (*ptr1 < *ptr2)
        return 1;
    else
        return 0;
}

int Reorder(quad data[], int npp) {
    //Initialize
    int i=0;
    
    //Run
    data[0].di = 0;
    qsort(data, npp+1, sizeof(data[0]), compare);
    for (i=(npp); i >= 0; i--) {
        data[i+1].di = data[i].di;
        data[i+1].plff = data[i].plff;
        data[i+1].Ffl = data[i].Ffl;
        data[i+1].Ffs = data[i].Ffs;
    }
    
    //Finalize
    return 0;
}