/*
 *  FindNewEta.c
 *  AgDegBW
 *
 *  Created by Andrew Leman on 6/5/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewEta.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindNewEta(double eta[], int M, float dt, float lamdap, float If, float alphau,
                float dx, double qb[], float qtg) {
    //Initialize
    int i=0;
    float dq[M+2], qbfront=0, qbback=0;
    
    //Run
    for(i=1; i <= (M+1); i++) {
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
        
    for (i=1; i <= (M+1); i++) {
        eta[i] = eta[i] + (dt/(1-lamdap))*If*dq[i];
    }
    
    //Finalize
    return 0;
}
