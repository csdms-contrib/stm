/*
 *  Run.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */
 
#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

typedef struct {
    double qw;
    double qbTf;
    int nstep;
} triple;

int InitializeAverages(double [][16], double [][16], double [], int, int);
int FindDischargeandFeed(triple [], double *, double *, int [], int, int);
int FindSlopesandShieldsStress(int, double [], double [], double [], double, double,
        double [], double, double, double, double [], double []);
int FindLoad(quad [], int, int, int, double [][16], double [][16], double [], double [],
        double [], double [], double [], double [], double [], double, double [], double []);
int FindNewEta(quad [], int, int, int, double, double [], double [], double [],
        double [], double [], double [][16], double [][16], double [], double,
        double, double, double, double, double, double, int *, double [], double []);
int UpdateAverages(double [][16], double [][16], double [][16], double [][16],
        double [], double [], int, int);
int FindHighflowEndflow(quad [], double [][16], double [][16], double [], double [],
        double [], double [], double [], double [], double [], double [], double [],
        double [], double [], double [], double [], double [], double [], double [],
        double [], double [], int, int, int, int, int, int);
int FinishAverages(quad [], double [][16], double [][16], double [], double [], double [],
        double [], double [], double [], double [], int, int, int, int);

int Run(double Fave[][16], double plave[][16], double qbTave[], triple hydro[],
    double *qw, double *qbTo, double eta[], double tausg[], double H[], double dx,
    double nk, double Dx90s[], double alphar, double R, double dsgs[], double Sl[],
    quad GSD[], double F[][16], double pl[][16], double qbT[], double ds[], double po[],
    double oo[], double so[], double na, double Fs[], double Ft[], double plf[],
    double alphau, double atrans, double dt, double I, double lps, double Laold[],
    double Ffinerflowmaxds[], double plfinerflowmaxds[], double Hflowmax[],
    double tausgflowmax[], double Fflowmax[], double plflowmax[], double dsgsflowmax[],
    double dsglflowmax[], double Ffinerflowendds[], double plfinerflowendds[],
    double Hflowend[], double tausgflowend[], double Fflowend[], double plflowend[],
    double dsgsflowend[], double dsglflowend[], int maxflow, double etaendcyc[],
    double plt[], double dsgsave[], double dsglave[], int np, int ndisc, int beginstep[],
    int totstep, int M, int npp, int k, int m, int *counter, double qbTfforprint[],
    int prints, int iterates) {

    //Declarations
    int o=0;

    InitializeAverages(Fave, plave, qbTave, M, npp);
    for (o=1; o <= totstep; o++) {
        FindDischargeandFeed(hydro, &(*qw), &(*qbTo), beginstep, o, ndisc);
        FindSlopesandShieldsStress(M, eta, tausg, H, dx, nk, Dx90s,
            *qw, alphar, R, dsgs, Sl);
        FindLoad(GSD, M, np, npp, F, pl, qbT, ds, tausg, dsgs, po, oo,
            so, R, Ft, plt);
        if ((k == prints) && (m == iterates)) {
            qbTfforprint[o] = qbT[M+1];
        }
        FindNewEta(GSD, M, npp, np, na, Dx90s, qbT, Fs, Ft, plf, F,
            pl, eta, alphau, *qbTo, dx, atrans, dt, I, lps, &(*counter), dsgs,
            Laold);
        UpdateAverages(Fave, F, plave, pl, qbTave, qbT, M, np);
        if ((k == prints) && (m == iterates)) {
            FindHighflowEndflow(GSD, F, pl, Ffinerflowmaxds, plfinerflowmaxds,
                Hflowmax, tausgflowmax, H, tausg, Fflowmax, plflowmax, dsgsflowmax,
                dsglflowmax, Ffinerflowendds, plfinerflowendds, Hflowend,
                tausgflowend, Fflowend, plflowend, dsgsflowend, dsglflowend, o,
                maxflow, np, npp, M, totstep);
        }
    }
    FinishAverages(GSD, Fave, plave, qbTave, eta, etaendcyc, Ft, plt,
        dsgsave, dsglave, M, np, npp, totstep);
    return 0;

}