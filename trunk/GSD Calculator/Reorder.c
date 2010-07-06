/*
 *  Reorder.c
 *  GSD Calculator
 *
 *  Created by Andrew Leman on 5/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Deptartment.
 *  All rights reserved.
 */

#include "Reorder.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float size;
    float perfiner;
} pair;

int compare(float *ptr1, float *ptr2) {
    if (*ptr1 > *ptr2)
        return 1;
    else if (*ptr1 < *ptr2)
        return -1;
    else
        return 0;
}

int Reorder(pair datapoints[], int terms) {
    //Initialize
    int i=0, j=0;
   
    printf("Your data before sorting:\n");
    for(i=0; i <= terms; i++) {
        printf("%f\t%f\n", datapoints[i].size, datapoints[i].perfiner);
    }
    
    //Run
    qsort(datapoints, terms+1, sizeof(datapoints[0]), compare);
    
    //Finalize
    printf("\nYour data after sorting:\n");
    for(j=0; j <= terms; j++) {
        printf("%f\t%f\n", datapoints[j].size, datapoints[j].perfiner);
    }
    for(j=0; j <= terms-1; j++) {
        if (datapoints[j].size > datapoints[j+1].size)
            return 1;
    }
    return 0;
}