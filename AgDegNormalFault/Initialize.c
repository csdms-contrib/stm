/*
 *  Initialize.c
 *  AgDegNormalFault
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *, double *, double *, double *, double *, double *, double *, double *,
        double *, double *, int *, int *, int *, double *, double *, double *, double *,
        double *, double *, double *, double *, int *, double *, double *, double *, double *, double *);
int AmbientEquilibria(double *, double *, double *, double *, double *, double, double,
        double, double, double, double, double, double, double, double, double, double, double, int);
int UltimateEquilibria(double *, double *, double *, double *, double, double, double,
        double, double, double, double, double, double, double, double, double, double, int,
        double);
int PrepTimeLoop(double [], double [], double *, double, double, double, double, int,
        double, double *);

int Initialize(double *Qf, double *If, double *B, double *D, double *lamdap, double *kc,
    double *S, double *Gtf, double *L, double *dt, int *iterate, int *prints, int *M,
    double *alphau, double *alphar, double *alphat, double *nt, double *tauc, double *phis,
    double *R, double *Cf, int *formulation, double *rf, double *deltaeta, double *tf,
    double *dx, double *Slmin, double *H, double *taustar, double *qstar, double *qt,
    double *Gt, double *qtf, double *tauult, double *Sult, double *Hult, double eta[],
    double x[], double *qtg, double *ifault) {

    //Declaration
    int check=0;
    
    //Read in parameters
        
    check=ReadIn(&(*Qf), &(*If), &(*B), &(*D), &(*lamdap), &(*kc), &(*S), &(*Gtf), &(*L), &(*dt), &(*iterate), &(*prints),
            &(*M), &(*alphau), &(*alphar), &(*alphat), &(*nt), &(*tauc), &(*phis), &(*R), &(*Cf), &(*formulation),
            &(*rf), &(*deltaeta), &(*tf), &(*dx), &(*Slmin));
    if (check == 1) {
        return 1;
    }
    
    //Find the Ambient Equilibria
    
    AmbientEquilibria(&(*H), &(*taustar), &(*qstar), &(*qt), &(*Gt), *Qf, *kc, *alphar, *S, *B, *R,
        *alphat, *phis, *nt, *If, *D, *tauc, *Cf, *formulation);
        
    //Find the Ultimate Equilibria
    
    UltimateEquilibria(&(*qtf), &(*tauult), &(*Sult), &(*Hult), *Gtf, *R, *If, *B, *tauc, *D,
        *alphat, *nt, *phis, *alphar, *Qf, *kc, *Cf, *formulation, *S);
        
    //Set initial bed and prep for time loop
    
    PrepTimeLoop(eta, x, &(*qtg), *dx, *S, *qtf, *L, *M, *rf, &(*ifault));
    return 0;

}