/*
 *  Initialize.c
 *  GSD Calculator
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
        float size;
        float perfiner;
    } pair;
    
int ReadIn(float [], float []);
void Scaling(float [], int);
int Reorder(pair [], int);
int EndpointCheck(pair [], int);

int Initialize(pair datapoints[], float D[], float f[], int *terms) {

    //Variable Declarations
    int check=0, i=0;

    //Reads in file
    *terms = ReadIn(D, f);
    if(terms == 0) {
        printf("There was an error reading in your file, please try again.\n");
        return 1; 
    }
    
    //Scales percentages as needed
    Scaling(f, *terms);

    for(i=0; i <= *terms; i++) {
        datapoints[i].size=D[i];
        datapoints[i].perfiner=f[i];
    }

    //Orders data
    check = Reorder(datapoints, *terms);
    if(check == 1) {
        printf("Error in reorganizing terms!");
        return 1;
    }

    //adds endpoints where they are missing
    *terms = EndpointCheck(datapoints, *terms);
    return 0;
}