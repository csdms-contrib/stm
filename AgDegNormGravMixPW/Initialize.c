/*
 *  Initialize.c
 *  AgDegNormGravMixPW
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

int ReadIn(quad [], double *, double *, double *, double *,
        double *, double *, double *, int *, int *, int *, double *, double *, double *,
        double *, double *, double *, double *, int *, int *, double *, double *, double *,
        double *, int *);
int Reorder(quad [], int);
int EndpointCheck(quad [], int *, int *);
int dscalculator(quad [], double [], double [], int);
int Fraction(quad [], int, double [], double [], double []);
int FracSand(quad [], int, double *);
int SetStrainCurves(double [], double [], double []);
int GeometricMean(quad [], double [], int, double *);
int Interpolation(quad [], int, double *, double *);
int SetupInitialBedandTime(double [][21], double [], double [], double [], double [],
        double [], double [], double [], double *, double, double, int, double, int,
        double, double, double, double);

int Initialize(quad GSD[], double *qw, double *qbTf, double *I, double *etad, double *S,
    double *L, double *dt, int *M, int *prints, int *iterates, double *nk, double *na,
    double *alphar, double *R, double *lps, double *alphau, double *atrans, int *npp,
    int *np, double *rload, double *Cexp, double *nexp, double ds[], double psi[],
    double plf[], double Fl[], double Fs[], double *fracsandl, double po[], double oo[],
    double so[], double *Dsgsi, double *Dx50si, double *Dx90si, int *bedloadrelation,
    double F[][21], double eta[], double x[], double dsgs[], double Dx90s[], double Dx50s[],
    double fracsand[], double *dx, double *Cf, int *formulation) {

    //Declaration
    int check=0, i=0;
    double tempmat[21];

    //Reads In Values and Makes Preliminary Calculations
    check = ReadIn(GSD, &(*qw), &(*qbTf), &(*I), &(*etad), &(*S), &(*L),
                    &(*dt), &(*M), &(*prints), &(*iterates), &(*nk), &(*na), &(*alphar), &(*R), &(*lps),
                    &(*alphau), &(*atrans), &(*npp), &(*np), &(*rload), &(*Cexp), &(*nexp), &(*Cf),
                    &(*formulation));
    if (check == 1)
        return 1;
        
    //Reorders Data
    Reorder(GSD, *npp);
    
    //Checks for and adds endpoints when necessary
    EndpointCheck(GSD, &(*npp), &(*np));
    
    //Reorders Data Again, after adding Endpoints
    Reorder(GSD, *npp);
    
    //Calculates the ds values
    dscalculator(GSD, ds, psi, *np);
    
    //Finds the fraction values Fl and Fs after Reordering
    Fraction(GSD, *npp, plf, Fl, Fs);
    
    //Finds the constant fracsandl
    FracSand(GSD, *np, &(*fracsandl));
        
    //Sets the Strain Curves for future use
    SetStrainCurves(po, oo, so);
    
    //Calculates the Mean of Ffl
    for(i=1; i < *npp; i++) {
        tempmat[i] = (GSD[i].Ffl - GSD[i+1].Ffl)/100;
    }
    GeometricMean(GSD, tempmat, *npp, &(*Dsgsi));
    
    //Interpolate at 50 & 90
    Interpolation(GSD, *npp, &(*Dx50si), &(*Dx90si));
    
    //User chooses Bedload relation they would like to use
    printf("Specify the bedload relation you want to use:\n1. Parker (1990)\n2. Wilcock and Crowe (2003)\n");
    scanf("%i", &(*bedloadrelation));
    
    //Set up the Initial Bed and Time
    SetupInitialBedandTime(F, Fl, eta, x, dsgs, Dx90s, Dx50s, fracsand, &(*dx),
                        *S, *L, *M, *etad, *np, *Dsgsi, *Dx90si, *Dx50si, *fracsandl);
                            
    return 0;

}