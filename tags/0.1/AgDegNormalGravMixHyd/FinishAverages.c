/*
 *  FinishAverages.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FinishAverages.h"
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

int Renormalize(double [], int);
int GeometricMean(quad [], double [], int, double *);

int FinishAverages(quad GSD[], double Fave[][16], double plave[][16], double qbTave[], double eta[],
    double etaendcyc[], double Ft[], double plt[], double dsgsave[], double dsglave[], int M,
    int np, int npp, int totstep) {
    //Initialize
    int i=0, j=0;
    double dsgt=0, dlgt=0;
    
    //Run
    for (i=1; i <= (M+1); i++) {
        etaendcyc[i] = eta[i];
        qbTave[i] = qbTave[i]/totstep;
        for (j=1; j <= np; j++) {
            Fave[i][j] = Fave[i][j]/totstep;
            plave[i][j] = plave[i][j]/qbTave[i];
        }
    }
    for (i=1; i <= (M+1); i++) {
        for (j=1; j <= np; j++) {
            Ft[j] = Fave[i][j];
            plt[j] = plave[i][j];
        }
        Renormalize(Ft, np);
        Renormalize(plt, np);
        GeometricMean(GSD, Ft, npp, &dsgt);
        GeometricMean(GSD, plt, npp, &dlgt);
        dsgsave[i] = dsgt;
        dsglave[i] = dlgt;
    }
    
    //Finalize
    return 0;
}