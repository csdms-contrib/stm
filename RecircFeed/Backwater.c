/*
 *  Backwater.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Backwater.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindDepth(double [], double [], double, double, double, double, double, int);
int FindHbgh(double [], double [], double [], double, double, double, double *, double, double, int, int);
int FindNewHtilEnd(double [], double [], double *, double, double, int);
int TestConvergence(double, double *, int *);

int Backwater(double etadhat[], double Htil[], double bgh1[], double dxhat, double qw, double Fro,
    double etatila, double Fl, double *Htilend, double timehat, int *bombed, int Nreach, int flume) {

    //Declarations
    int i=0, converged=0;
    double Htilendnew=0;
    
    //Different flumes have different Backwater calculations
    if (flume == 1) {
        FindDepth(etadhat, Htil, dxhat, qw, Fro, etatila, Fl, Nreach);
    }
    else {
        for (i=2; i <= 100; i++) {
            FindHbgh(Htil, etadhat, bgh1, qw, Fro, Fl, &(*Htilend), dxhat, timehat, Nreach, i);
            FindNewHtilEnd(Htil, bgh1, &Htilendnew, *Htilend, dxhat, Nreach);
            if (i == 100) {
                *bombed = 1;
                break;
            }
            TestConvergence(Htilendnew, &(*Htilend), &converged);
            if (converged == 1) {
                break;
            }
        }
    }

    //Finalize
    return 0;
}