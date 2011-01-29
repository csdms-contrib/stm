/*
 *  FindNewEta.c
 *  AgDegNormalSub
 *
 *  Created by Andrew Leman on 6/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewEta.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindNewEta(double eta[], int M, float dt, float lamdap, float If, float alphau,
                float dx, double qb[], float qtg, float sigma, float rB, float omega,
                float lamda) {
    //Initialize
    int i=0;
    float dq[M+2], qbfront=0, qbback=0;
    
    //Run
    for(i=1; i <= (M); i++) {
        if (i == 1) {
            qbback = qtg;
            qbfront = qb[i+1];
            dq[i] = ((alphau)*(qbback-qb[i])/dx)+((1-alphau)*(qb[i]-qbfront)/dx);
        }
        else {
            qbback = qb[i-1];
            qbfront = qb[i+1];
            dq[i] = ((alphau)*(qbback-qb[i])/dx)+((1-alphau)*(qb[i]-qbfront)/dx);
        }    
    }
        
    for (i=1; i <= (M); i++) {
        eta[i] = eta[i] - ((sigma/1000)*dt) + (dt*60*60*24*365.25/((1-lamdap)*rB))*If*dq[i]*omega*(1+lamda);
    }
    
    //Finalize
    return 0;
}