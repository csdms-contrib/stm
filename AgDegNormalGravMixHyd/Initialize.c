/*
 *  Initialize.c
 *  AgDegNormalGravMixHyd
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

typedef struct {
    double qw;
    double qbTf;
    int nstep;
} triple;

int Reorder(quad [], int);
int EndpointCheck(quad [], int *, int *);
int dscalculator(quad [], double [], double [], int);
int Fraction(quad [], int, double [], double [], double []);
int PreliminaryCalculations(triple [], int, int *, double *, double *, int [],
        double *, double *, double *, double *, double, int, double);
int DischargesforPrint(triple [], int, double, int [], double [], double [], double []);
int CalculateMaxFlow(triple [], int, int *, int []);
int GeometricMean(quad [], double [], int, double *);
int Interpolation(quad [], double [], int, double *);
int SetStrainCurves(double [], double [], double []);
int SetupInitialBedandTime(double [][16], double [], double [], double [], double [],
        double [], double *, double, double, int, double, int, double, double, double []);

int Initialize(quad GSD[], triple hydro[], int *npp, int *np, double ds[], double psi[],
    double plf[], double Fl[], double Fs[], int ndisc, int totstep, double *qbToave,
    double *qwave, int beginstep[], double *durhyd, double *I, double *LoadAnn, double *dt,
    double dtflood, double ncyc, double R, double qwforprint[], double qbToforprint[],
    double dayforprint[], double *Dsgsi, double *Dsgsub, double *Ds90si, double po[],
    double oo[], double so[], double F[][16], double eta[], double x[], double dsgs[],
    double Dx90s[], double *dx, double S, double L, int M, double etad, double Sl[],
    int *maxflow) {

    //Declarations
    int i=0;
    double tempmat[*npp+9];

    //Reorders GSD data
    Reorder(GSD, *npp);
    
    //Checks for and adds endpoints where necessary
    EndpointCheck(GSD, &(*npp), &(*np));
    
    //Reorders again
    Reorder(GSD, *npp);
    
    //Calculates the ds and psi values
    dscalculator(GSD, ds, psi, *np);
    
    //Calculates the fraction in each grain size
    Fraction(GSD, *npp, plf, Fl, Fs);
    
    //Does preliminary calculations for Intermittency and dt
    PreliminaryCalculations(hydro, ndisc, &totstep, &(*qbToave), &(*qwave), beginstep,
            &(*durhyd), &(*I), &(*LoadAnn), &(*dt), dtflood, ncyc, R);
            
    //Calculates the Discharges for Print
    DischargesforPrint(hydro, ndisc, dtflood, beginstep, qwforprint, qbToforprint, dayforprint);
            
    //Calculates the index for the maxflow in the hydrograph
    CalculateMaxFlow(hydro, ndisc, &(*maxflow), beginstep);
    
    //Calculate the Geometric Mean for Fl and Fs
    for(i=1; i <= *np; i++) 
        tempmat[i] = (GSD[i].Ffl - GSD[i+1].Ffl)/100;
    GeometricMean(GSD, tempmat, *npp, &(*Dsgsi));
    
    for(i=1; i <= *np; i++)
        tempmat[i] = (GSD[i].Ffs - GSD[i+1].Ffs)/100;
    GeometricMean(GSD, tempmat, *npp, &(*Dsgsub));
    
    //Interpolates at 90 percent
    for(i=1; i<= *npp; i++)
        tempmat[i] = GSD[i].Ffl;
    Interpolation(GSD, tempmat, *npp, &(*Ds90si));
    
    //Sets the strain curves for interpolation later on
    SetStrainCurves(po, oo, so);
    
    //Setups the bed profile and initial values
    SetupInitialBedandTime(F, Fl, eta, x, dsgs, Dx90s, &(*dx), S, L, M, etad, *np,
        *Dsgsi, *Ds90si, Sl);
    return 0;

}