/*
 *  Initialize.c
 *  AgDegBW
 *
 *  Created by Andrew Leman on 7/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(float *, float *, float *, float *, float *, float *, float *, float *,
            float *, float *, int *, int *, int *, float *, float *, float *,
            float *, float *, float *, float *, float *, int *, float *, float *,
            float *);
int AmbientEquilibria(float *, float *, float *, float *, float *, float, float,
            float, float, float, float, float, float, float, float, float, float, 
            float, int);
int UltimateEquilibria(float *, float *, float *, float *, float, float, float,
            float, float, float, float, float, float, float, float, float, float,
            int, float);
int DownstreamCondition(double *, double *, double *, double *, double *, float,
            float, float, float);
int PrepTimeLoop(double [], double [], double [], float *, float, float, float,
            int, float, float);
int FluvialBackwater(double [], double [], double [], int, float, float, float,
            float, float, float, int);

int Initialize(float *Qf, float *If, float *B, float *D, float *lamdap, float *kc,
    float *S, float *Gtf, float *L, float *dt, int *iterate, int *prints, int *M,
    float *alphau, float *alphar, float *alphat, float *nt, float *tauc, float *phis,
    float *R, float *Cf, int *formulation, float *ksio, float *dx, float *qw,
    float *Ha, float *taustar, float *qstar, float *qt, float *Gt, float *qtg,
    float *tauult, float *Sult, float *Hult, double *Frni, double *Frnu, double *Hc,
    double *ksimin, double *ksiinit, double eta[], double x[], double ksi[], float *qtf,
    double H[]) {

    //Declarations
    int check=0;

    //Reads in initial values and computes dx and qw
    ReadIn(&(*Qf), &(*If), &(*B), &(*D), &(*lamdap), &(*kc), &(*S), &(*Gtf), &(*L), &(*dt), &(*iterate), &(*prints),
            &(*M), &(*alphau), &(*alphar), &(*alphat), &(*nt), &(*tauc), &(*phis), &(*R), &(*Cf), &(*formulation),
            &(*ksio), &(*dx), &(*qw));
      
    //Computes Ambient Equilibria
    AmbientEquilibria(&(*Ha), &(*taustar), &(*qstar), &(*qt), &(*Gt), *Qf, *kc, *alphar, *S, *B, 
                        *R, *alphat, *phis, *nt, *If, *D, *tauc, *Cf, *formulation);

    //Computes Ultimate Equilibria
    UltimateEquilibria(&(*qtf), &(*tauult), &(*Sult), &(*Hult), *Gtf, *R, *If, *B, *tauc, *D,
                        *alphat, *nt, *phis, *alphar, *Qf, *kc, *Cf, *formulation, *S);
                        
    //Downstream Conditions
    check = DownstreamCondition(&(*Frni), &(*Frnu), &(*Hc), &(*ksimin), &(*ksiinit), *Qf, *B, *Ha, *Hult);
    if (check == 1) {
        printf("Initial and Ultimate normal Froude numbers must be less than 1!\n");
        return 1;
    }
    if (*ksimin > *ksio) {
        printf("Initial downstream water surface must be greater than the critical depth!\n");
        return 1;
    }
                        
    //Sets Initial Bed and Time
    PrepTimeLoop(eta, x, ksi, &(*qtg), *dx, *S, *qtf, *M, *ksio, *L);
    
    //Fluvial Backwater Function
    FluvialBackwater(eta, ksi, H, *M, *qw, *alphar, *kc, *ksio, *dx, *Cf, *formulation);

    return 0;
    
}