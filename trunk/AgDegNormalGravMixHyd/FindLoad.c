/*
 *  FindLoad.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

typedef struct {
    double di;
    double plff;
    double Fft;
    double Ffs;
} quad;

//Functions Called Within FINDLOAD

int GeometricMean(quad [], double [], int, double *);
int GeometricStandardDeviation(quad [], double [], int, double *);
int FindOmega(double, double [], double [], double [], double, double *);
double GG(double);

//Actual FINDLOAD Function

int FindLoad (quad GSD[], int M, int np, int npp, double F[][16], double pl[][16],
              double qbT[], double ds[], double tausg[], double dsgs[], double po[],
              double oo[], double so[], double R, double Ft[], double plt[]) {
    //Initialize
    double sas=0, Dsgt=0, phisgo=0, qbtot=0, Omega=0, arg=0, ustar=0, Gvar=0;
    double lowphi = 0.1, taursgo = 0.0386, beta = 0.0951;
    double zs[npp+2];
    int i=0, j=0;
    
    //Run
    
        //THE PARKER BEDLOAD RELATION
    
        for (i=1; i <=(M+1); i++) {
        
            for (j=1; j<=np; j++) {
                Ft[j] = F[i][j];
            }
        
            GeometricMean(GSD, Ft, npp, &Dsgt);
            GeometricStandardDeviation(GSD, Ft, npp, &sas);
        
            sas = log(sas)/log(2);
            for (j=1; j<=np; j++) 
                zs[j] = ds[j]/Dsgt;
            phisgo = tausg[i]/taursgo;
            if (phisgo < lowphi) {
                qbT[i] = 0;
                for (j=1; j<=np; j++) {
                    pl[i][j] = 1/np;
                }
            }
            else {
                qbtot = 0;
                FindOmega(phisgo, po, oo, so, sas, &Omega);
                for(j=1; j<=np; j++) {
                    arg = Omega*phisgo*exp((-beta)*log(zs[j]));
                    Gvar = GG(arg);
                    plt[j] = Ft[j]*(Gvar);
                    qbtot += plt[j];
                }
                for (j=1; j<=np; j++) {
                    pl[i][j] = plt[j]/qbtot;
                }
                ustar = sqrt(R*g*(dsgs[i]/1000)*tausg[i]);
                qbT[i] = (qbtot*0.00218*pow(ustar, 3))/(R*g);
            }
        }
    
    //Finalize
    return 0;
}
