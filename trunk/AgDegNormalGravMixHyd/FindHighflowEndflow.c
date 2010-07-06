/*
 *  FindHighflowEndflow.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindHighflowEndflow.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

int GeometricMean(quad [], double [], int, double *);
int Perfiner(double [], double [], int);

int FindHighflowEndflow(quad GSD[], double F[][16], double pl[][16], double Ffinerflowmaxds[],
    double plfinerflowmaxds[], double Hflowmax[], double tausgflowmax[], double H[],
    double tausg[], double Fflowmax[], double plflowmax[], double dsgsflowmax[],
    double dsglflowmax[], double Ffinerflowendds[], double plfinerflowendds[],
    double Hflowend[], double tausgflowend[], double Fflowend[], double plflowend[],
    double dsgsflowend[], double dsglflowend[], int o, int maxflow, int np, int npp, int M,
    int totstep) {
    //Initialize
    int i=0, j=0;
    double Fflowmaxds[npp+2], plflowmaxds[npp+2];
    double Fflowendds[npp+2], plflowendds[npp+2];
    double dsgsflowmaxt=0, dsglflowmaxt=0;
    double dsgsflowendt=0, dsglflowendt=0;
    
    //Run
        if (o == maxflow) {
            for (i=1; i <= np; i++) {
                Fflowmaxds[i] = F[M+1][i];
                plflowmaxds[i] = pl[M+1][i];
            }
            Perfiner(Fflowmaxds, Ffinerflowmaxds, npp);
            Perfiner(plflowmaxds, plfinerflowmaxds, npp);
            for (i=1; i <= (M+1); i++) {
                Hflowmax[i] = H[i];
                tausgflowmax[i] = tausg[i];
                for (j=1; j <= np; j++) {
                    Fflowmax[j] = F[i][j];
                    plflowmax[j] = pl[i][j];
                }
                for (j=1; j <= np; j++) {
                    GeometricMean(GSD, Fflowmax, npp, &dsgsflowmaxt);
                    GeometricMean(GSD, plflowmax, npp, &dsglflowmaxt);
                }
                dsgsflowmax[i] = dsgsflowmaxt;
                dsglflowmax[i] = dsglflowmaxt;
            }
        }
        if (o == totstep) {
            for (i=1; i <= np; i++) {
                Fflowendds[i] = F[M+1][i];
                plflowendds[i] = pl[M+1][i];
            }
            Perfiner(Fflowendds, Ffinerflowendds, npp);
            Perfiner(plflowendds, plfinerflowendds, npp);
            for (i=1; i <= (M+1); i++) {
                Hflowend[i] = H[i];
                tausgflowend[i] = tausg[i];
                for (j=1; j <= np; j++) {
                    Fflowend[j] = F[i][j];
                    plflowend[j] = pl[i][j];
                }
                for (j=1; j <= np; j++) {
                    GeometricMean(GSD, Fflowend, npp, &dsgsflowendt);
                    GeometricMean(GSD, plflowend, npp, &dsglflowendt);
                }
                dsgsflowend[i] = dsgsflowendt;
                dsglflowend[i] = dsglflowendt;
            }
        }
    
    //Finalize
    return 0;
}