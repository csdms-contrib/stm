/*
 *  Integration.c
 *  DepDistTotLoadCalc
 *
 *  Created by Andrew Leman on 7/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Integration.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Integration(int N, double vsku[], double H[], double kc[], double I[]) {

    //Declarations
    double sigma[N+1][25], trapezoidal[N+1][25];
    double sig=0;
    int i=0, j=0;
    
    //Run
        //Assign values to ΔI
        for (i=1; i <= 19; i++) {
            sig = 0.05*i;
            sigma[0][i] = sig;
            for (j=1; j <= N; j++) {
                sigma[j][i] = pow((((1 - sig)*0.05)/(sig*(1-0.05))), vsku[j])*log(30*H[j]*sig/(kc[j]/1000));
            }
        }
        sig = 0.96;
        i=20;
        sigma[0][i] = sig;
        for (j=1; j <= N; j++) {
            sigma[j][i] = pow((((1 - sig)*0.05)/(sig*(1-0.05))), vsku[j])*log(30*H[j]*sig/(kc[j]/1000));
        }
        sig = 0.97;
        i=21;
        sigma[0][i] = sig;
        for (j=1; j <= N; j++) {
            sigma[j][i] = pow((((1 - sig)*0.05)/(sig*(1-0.05))), vsku[j])*log(30*H[j]*sig/(kc[j]/1000));
        }
        sig = 0.98;
        i=22;
        sigma[0][i] = sig;
        for (j=1; j <= N; j++) {
            sigma[j][i] = pow((((1 - sig)*0.05)/(sig*(1-0.05))), vsku[j])*log(30*H[j]*sig/(kc[j]/1000));
        }
        sig = 0.99;
        i=23;
        sigma[0][i] = sig;
        for (j=1; j <= N; j++) {
            sigma[j][i] = pow((((1 - sig)*0.05)/(sig*(1-0.05))), vsku[j])*log(30*H[j]*sig/(kc[j]/1000));
        }
        sig = 0.9999;
        i=24;
        sigma[0][i] = sig;
        for (j=1; j <= N; j++) {
            sigma[j][i] = pow((((1 - sig)*0.05)/(sig*(1-0.05))), vsku[j])*log(30*H[j]*sig/(kc[j]/1000));
        }
    
        //Use the Trapezoidal Rule for Integration
        for (i=1; i <= 23; i++) {
            for (j=1; j <= N; j++) {
                trapezoidal[j][i] = 0.5*(sigma[j][i] + sigma[j][i+1])*(sigma[0][i+1] - sigma[0][i]);
            }
        }
        
        for (j=1; j <= N; j++) {
            I[j]=0;
        }
        for (j=1; j <= N; j++) {
            for (i=1; i <= 23; i++) {
                I[j] += trapezoidal[j][i];
            }
        }
    
    //Finalize
    return 0;
}