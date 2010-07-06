/*
 *  BedExner.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "BedExner.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int BedExner(double etadhat[], double qtil[], double *etatila, double *SNup, double *SNdown,
    double dt, double qtilg, double Fl, double dxhat, int Nreach, int flume) {
    
    //Declarations
    int i=0;
    
    if (flume == 1) {
        *etatila += dt*(qtilg - qtil[Nreach])/Fl;
        for (i=1; i <= Nreach; i++) {
            if (i == 1) {
                etadhat[i] += (qtilg - qtil[i])*(dt/dxhat);
            }
            else {
                etadhat[i] += (qtil[i-1] - qtil[i])*(dt/dxhat);
            }
            etadhat[i] -= ((qtilg - qtil[Nreach]))*dt;
        }
        *SNup = (etadhat[1] - etadhat[2])/dxhat;
        *SNdown = (etadhat[Nreach - 1] - etadhat[Nreach])/dxhat; 
    }
    else {
        etadhat[1] += (qtil[Nreach] - qtil[1])*(dt/dxhat);
        for (i=2; i <= Nreach; i++) {
            etadhat[i] += (qtil[i-1] - qtil[i])*(dt/dxhat);
        }
        *SNup = (etadhat[1] - etadhat[2])/dxhat;
        *SNdown = (etadhat[Nreach - 1] - etadhat[Nreach])/dxhat;
    }
    
    return 0;
}