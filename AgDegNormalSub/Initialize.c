/*
 *  Initialize.c
 *  AgDegNormalSub
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Deparmtent.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(float *, float *, float *, float *, float *, float *, float *, float *,
            float *, int *, int *, int *, float *, float *, float *, float *,
            float *, float *, float *, float *, int *, float *, float *, float *,
            float *, float *, float *);
int PrepTimeLoop(double [], double [], float *, float, float, float, float, int);
int FindSlopes(double [], int, double [], float);
int FindDepthShear(double [], double [], int, float, float, float, double [], float, float, float, int);
int FindLoad(double [], int, float, double [], float, float, float, float, float, double []);

int Initialize(float *qw, float *If, float *D, float *lamdap, float *kc, float *S, float *qtf,
    float *L, float *dt, int *iterate, int *prints, int *M, float *alphau, float *alphar,
    float *alphat, float *nt, float *tauc, float *phis, float *R, float *Cf, int *formulation, float *sigma,
    float *rB, float *omega, float *lamda, float *dx, float *Lmax, double eta[], double x[],
    float *qtg, double Sl[], double tau[], double H[], double qb[]) {

    //Declaration
    int check=0;

    //Read in parameters
        
    check = ReadIn(&(*qw), &(*If), &(*D), &(*lamdap), &(*kc), &(*S), &(*qtf), &(*L), &(*dt), &(*iterate), &(*prints),
            &(*M), &(*alphau), &(*alphar), &(*alphat), &(*nt), &(*tauc), &(*phis), &(*R), &(*Cf), &(*formulation),
            &(*sigma), &(*rB), &(*omega), &(*lamda), &(*dx), &(*Lmax));
            
    //Checks that L is less than Lmax, else program ends
            
    if (check == 1) {
        printf("Error! L is greater than Lmax.  Change and try again. \n");
        return 1;
    }
            
    //Prep Time Loop and solves for initial values
    
    PrepTimeLoop(eta, x, &(*qtg), *dx, *S, *qtf, *L, *M);
    FindSlopes(Sl, *M, eta, *dx);
    FindDepthShear(tau, H, *M, *qw, *kc, *alphar, Sl, *D, *R, *Cf, *formulation);
    FindLoad(qb, *M, *phis, tau, *tauc, *nt, *D, *R, *alphat, Sl);
    
    return 0;

}