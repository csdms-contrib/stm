/*
 *  FindOmega.c
 *  AgDegNormGravMixSubPW
 *
 *  Created by Andrew Leman on 7/7/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindOmega.h"
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

//CUBIC INTERPOLATION FUNCTION

double CubicInterpolant(double ym1, double y, double yp1, double yp2, double xm1, double x,
                       double xp1, double xp2, double phisgo) {
//Initialize
    float output=0, a1=0, a2=0, a3=0, a4=0;

//Run
    a1 = ym1;
    a2 = (y - a1)/(x - xm1);
    a3 = (yp1 - a1 - a2*(xp1 - xm1))/((xp1 - xm1)*(xp1 - x));
    a4 = yp2 - a1 - a2*(xp2 - xm1) - a3*(xp2 - xm1)*(xp2 - x);
    a4 = a4/((xp2 - xm1)*(xp2-x)*(xp2-xp1));
    
    output = a1 + a2*(phisgo - xm1) + a3*(phisgo-xm1)*(phisgo - x) + a4*(phisgo - xm1)*(phisgo - x)*(phisgo - xp1);

//Finalize
    return output;
}

//FIND OMEGA FUNCTION

int FindOmega(double phisgo, double po[], double oo[], double so[], double sigmasg, double *Omega) {
    //Initiailize
    double omegao=0, sigmao=0, xm1=0, x=0, xp1=0, xp2=0, ym1=0, y=0, yp1=0, yp2=0;
    int i=0;
    
    
    //Run
        //Calculates ωo and σo for high and low values or interpolates
    
        if (phisgo > po[35]) {
            omegao = oo[35] + ((oo[36] - oo[35])/(po[36] - po[35]))*((phisgo)-po[35]);
            sigmao = so[35] + ((so[36] - so[35])/(po[36] - po[35]))*((phisgo)-po[35]);
        }
        else if (phisgo <= 0.7639) {
            omegao = 1.011;
            sigmao = 0.8157;
        }
        else {
            for (i=1; i<=34; i++) {
                if (((phisgo) > po[i]) && ((phisgo) <= po[i+1])) {
                    
                    xm1 = po[i-1];
                    x = po[i];
                    xp1 = po[i+1];
                    xp2 = po[i+2];
                    
                    ym1 = oo[i-1];
                    y = oo[i];
                    yp1 = oo[i+1];
                    yp2 = oo[i+2];
                    
                    omegao = CubicInterpolant(ym1, y, yp1, yp2, xm1, x, xp1, xp2, phisgo);
                    
                    ym1 = so[i-1];
                    y = so[i];
                    yp1 = so[i+1];
                    yp2 = so[i+2];
                    
                    sigmao = CubicInterpolant(ym1, y, yp1, yp2, xm1, x, xp1, xp2, phisgo);
                    break;
                }
            }
        }
        
        //Calculate Omega from these values
        
        *Omega = 1.0 + (sigmasg/sigmao)*(omegao - 1.0);
    
    //Finalize
    return 0;
}