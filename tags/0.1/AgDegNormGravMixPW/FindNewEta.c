/*
 *  FindNewEta.c
 *  AgDegNormGravMixPW
 *
 *  Created by Andrew Leman on 6/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewEta.h"
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
int Perfiner(double [], double [], int);
int Interpolation2(quad [], double [], int, double *, double *);
int FracSand2(quad [], double [], int, double *);

int FindNewEta(quad GSD[], int M, int npp, int np, double na, double Dx90s[], double Dx50s[], 
               double qbT[], double Fs[], double Ft[], double plf[], double F[][21],
               double pl[][21], double eta[], double alphau, double qbTf, double dx,
               double atrans, double dt, double I, double lps, double time, double dsgs[],
               double fracsand[], double Laold[]) {
    //Initialize
    double La[M+2], Flexc[M+2][npp+2], qjj1dev[npp+2], qjj2dev[npp+2], etanew[M+2];
    double Fnew[M+2][npp+2], Fft[npp+2];
    double qbTdev=0, dsgst=0, Dx50st=0, Dx90st=0, fracsandt=0;
    int i=0, j=0;
    
    //Run
    for(i=1; i<= (M+1); i++) {
        La[i] = (na*Dx90s[i])/1000;
        //Special Cases for the first and last nodes
        if (i == 1) {
            qbTdev = (alphau*(qbT[i] - qbTf)/dx) + (1.0 - alphau)*((qbT[i+1] - qbT[i])/dx);
            for (j=1; j<= np; j++) {
                if (qbTdev > 0) {
                    Flexc[i][j] = Fs[j];
                }
                else {
                    Flexc[i][j] = atrans*F[i][j] + (1.0 - atrans)*pl[i][j];
                }
                qjj1dev[j] = (alphau*(qbT[i]*pl[i][j] - qbTf*plf[j])/dx) + ((1.0 - alphau)*(qbT[i+1]*pl[i+1][j] - qbT[i]*pl[i][j])/dx);
                qjj2dev[j] = Flexc[i][j]*qbTdev;
            }
        }
        else if (i == (M+1)) {
            qbTdev = (qbT[i] - qbT[i-1])/dx;
            for (j=1; j <= np; j++) {
                if (qbTdev > 0) {
                    Flexc[i][j] = Fs[j];
                }
                else {
                    Flexc[i][j] = atrans*F[i][j] + (1.0 - atrans)*pl[i][j];
                }
                qjj1dev[j] = (qbT[i]*pl[i][j] - qbT[i-1]*pl[i-1][j])/dx;
                qjj2dev[j] = Flexc[i][j]*qbTdev;
            }
        }
        else {
            qbTdev = (alphau*(qbT[i] - qbT[i-1])/dx) + ((1.0 - alphau)*(qbT[i+1] - qbT[i])/dx);
            for (j=1; j <= np; j++) {
                if (qbTdev > 0) {
                    Flexc[i][j] = Fs[j];
                }
                else {
                    Flexc[i][j] = atrans*F[i][j] + (1.0 - atrans)*pl[i][j];
                }
                qjj1dev[j] = (alphau*(qbT[i]*pl[i][j] - qbT[i-1]*pl[i-1][j])/dx) + ((1.0 - alphau)*(qbT[i+1]*pl[i+1][j] - qbT[i]*pl[i][j])/dx);
                qjj2dev[j] = Flexc[i][j]*qbTdev;
            }
        }
        //Uses constants to calculate a new eta
        etanew[i] = eta[i] + dt*(-qbTdev*I/(1.0 - lps));
        for (j=1; j <= np; j++) {
            Fnew[i][j] = F[i][j] + dt*I*(-qjj1dev[j] + qjj2dev[j])/(La[i]*(1.0-lps));
            if (time > 0) {
                Fnew[i][j] += (Flexc[i][j] - F[i][j])*(La[i] - Laold[i])/(La[i]);
            }
        }
    }
    
    //Takes the new data for La and eta and assigns it to the old positions
    for (i=1; i <= (M+1); i++) {
        Laold[i] = La[i];
        if (i < (M+1)) {
            eta[i] = etanew[i];
        }
        for (j=1; j <= np; j++) {
            Ft[j] = Fnew[i][j];
            if (Ft[j] < 0) {
                Ft[j] = 0;
            }
        }
        Renormalize(Ft, np);
        GeometricMean(GSD, Ft, npp, &dsgst);
        dsgs[i] = dsgst;
        Perfiner(Ft, Fft, npp);
        Interpolation2(GSD, Fft, npp, &Dx50st, &Dx90st);
        FracSand2(GSD, Fft, np, &fracsandt);
        Dx50s[i] = Dx50st;
        Dx90s[i] = Dx90st;
        fracsand[i] = fracsandt;
        for (j=1; j <= np; j++) {
            F[i][j] = Ft[j];
        }
    }
    
    //Finalize
    return 0;
}