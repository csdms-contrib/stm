/*
 *  Initialize.c
 *  AgDegNormal
 *
 *  Created by Andrew Leman on 7/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Prototypes

int ReadIn(float *, float *, float *, float *, float *, float *, float *, float *,
        float *, float *, int *, int *, int *, float *, float *, float *, float *,
        float *, float *, float *, float *, int *);
int AmbientEquilibria(float *, float *, float *, float *, float *, float, float,
        float, float, float, float, float, float, float, float, float, float, float, int);
int UltimateEquilibria(float *, float *, float *, float *, float, float, float,
        float, float, float, float, float, float, float, float, float, float, int, float);
int PrepTimeLoop(double [], double [], float *, float *, float, float, float, int);

//The MAIN FUNCTION

int Initialize(float *Qf, float *If, float *B, float *D, float *lamdap, float *kc,
    float *S, float *Gtf, float *L, float *dt, int *iterate, int *prints, int *M,
    float *alphau, float *alphar, float *alphat, float *nt, float *tauc, float *phis,
    float *R, float *Cf, int *formulation, float *H, float *taustar, float *qstar,
    float *qt, float *Gt, float *qtf, float *tauult, float *Sult, float *Hult,
    float *qtg, float *dx, double eta[], double x[]) {

    //Read in parameters
    
    ReadIn(&(*Qf), &(*If), &(*B), &(*D), &(*lamdap), &(*kc), &(*S), &(*Gtf), &(*L), &(*dt), &(*iterate), &(*prints),
            &(*M), &(*alphau), &(*alphar), &(*alphat), &(*nt), &(*tauc), &(*phis), &(*R), &(*Cf), &(*formulation));
    
    //Find the Ambient Equilibria
    
    AmbientEquilibria(&(*H), &(*taustar), &(*qstar), &(*qt), &(*Gt), *Qf, *kc, *alphar, *S, *B, *R,
            *alphat, *phis, *nt, *If, *D, *tauc, *Cf, *formulation);
            
    //Find the Ultimate Equilibria
    
    UltimateEquilibria(&(*qtf), &(*tauult), &(*Sult), &(*Hult), *Gtf, *R, *If, *B, *tauc, *D,
            *alphat, *nt, *phis, *alphar, *Qf, *kc, *Cf, *formulation, *S);
            
    //Prep the time loop by finding ghost node and Δx and setting initial bed
    
    PrepTimeLoop(eta, x, &(*qtg), &(*dx), *S, *qtf, *L, *M);
    
    return 0;
}