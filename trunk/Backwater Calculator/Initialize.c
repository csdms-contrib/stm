/*
 *  Initialize.c
 *  Backwater Calculator
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, int *);
int ChezyFormulation(float, float, float, float *, float *, float *, float *);
int ManningStricklerFormulation(float, float, float, float, float, float, float, float *, float *, float *, float *);
int CriticalValues(float, float *, float *);

int Initialize(float *S, float *Cz, float *qw, float *R, float *Dmean, float *Ds90,
    float *nk, float *alphar, float *x0, float *step, float *initdepth, int *terms,
    float *chezyH, float *chezyFr, float *chezyU, float *chezytaub, float *MSH,
    float *MSU, float *MSFr, float *MStaub, float *Hc, float *Uc, int *formulation) {

    //Read in input parameters
    *terms = ReadIn(&(*S), &(*Cz), &(*qw), &(*R), &(*Dmean), &(*Ds90), &(*nk), &(*alphar), &(*x0), &(*step), &(*initdepth), &(*formulation));
    if (*terms == 0) {
        printf("Your data was not read in, please try again.\n");
        return 1;
    }

    //Chezy Formulations
    if (*formulation == 1)
        ChezyFormulation(*S, *Cz, *qw, &(*chezyH), &(*chezyU), &(*chezyFr), &(*chezytaub));
            
    //Manning Strickler Formulations
    if (*formulation == 2)
        ManningStricklerFormulation(*S, *qw, *nk, *Ds90, *alphar, *R, *Dmean, &(*MSH), &(*MSU), &(*MSFr), &(*MStaub));
            
    //Critical Values
    CriticalValues(*qw, &(*Hc), &(*Uc));
    return 0;

}