/*
 *  Preliminary Calculations.c
 *  SuspSedDensityStrat
 *
 *  Created by Andrew Leman on 7/6/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Preliminary Calculations.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double FallVelocity(double, double, double);

int PreliminaryCalculations(double *Rep, double *vs, double *Hr, double *ustarr,
    double *unr, double *Cr, double *Ristar, double R, double D, double H, double kc,
    double ustar, double nu) {
    
    //Initialize
    int choice=0;
    double Zgp=0, Aa=0.00000013;
    
    //Run
        *Rep = sqrt((R-1)*981*(D/10.0))*(D/10.0)/nu;
        *Hr = (H*100.0)/(kc/10.0);
        *unr = (1.0/0.4)*log(30.0*0.05*(*Hr));
        *vs = FallVelocity(*Rep, R, D);
        *ustarr = ustar/(*vs);
        
    
        printf("Would you like to\n1. Use the C value as a shear velocity due to skin friction to use Garcia Parker\n2. Use the C value as the reference concentration\n");
        scanf("%i", &choice);
        
        if (choice == 1) {
           Zgp = ((*Cr)/(*vs))*pow((*Rep), 0.6);
           *Cr = Aa*pow(Zgp, 5)/(1 + (Aa/0.3)*pow(Zgp, 5));
        }
        else if (choice != 2) {
            printf("Improper response! Restart the program and try again\n");
            return 1;
        }
        
        *Ristar = (R-1)*981*H*100*(*Cr)/pow(ustar, 2);
    
    //Finalize
    return 0;
}