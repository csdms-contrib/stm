/*
 *  CalcLoadandDistribution.c
 *  Acronym1D
 *
 *  Created by Andrew Leman on 6/17/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "CalcLoadandDistribution.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81



//CUBIC INTERPOLATION FUNCTION

float CubicInterpolant(float ym1, float y, float yp1, float yp2, float xm1, float x,
                       float xp1, float xp2, float phisgo) {
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

//G CALCULATOR FUNCTION

float GG(float phi) {
//Initialize
    float G=0, Mo=14.2;
    
//Run
    if(phi < 1) 
        G = exp(log(phi)*Mo);
    else if((phi <= 1.59) && (phi >= 1))
        G = exp(Mo*(phi - 1.0) - 9.28*pow((phi - 1.0), 2));
    else
        G = 5474*exp(4.5*log(1.0-(0.853/phi)));

//Finalize
    return G;
}


typedef struct  {
    float D;
    float pfs;
} pair;




int CalcLoadandDistribution(pair data[], int npp, int np, float *tausg, float R,
                            float Dsg, float ustar, float po[], float so[],
                            float oo[], float sigmasg, double *qbtot, float pfl[],
                            float qb[]) {
    //INITIALIZE
    float taursgo=0.0386, lowphi=0.1, hiphi=2320, beta=0.0951, omegao=0, sigmao=0;
    float xm1=0, x=0, xp1=0, xp2=0, ym1=0, y=0, yp1=0, yp2=0, phisgo=0;
    float Omega=0, zs=0, phi=0, F=0;
    int i=0;
     
    //RUN
    
        //Calculates tausg and φsgo
    
        *tausg = (ustar*ustar)/(R*g*(Dsg/1000));
        phisgo = (*tausg)/(taursgo);
        
        //Checks the bounds on φsgo
        
        if (phisgo < lowphi) {
            printf("Friction Velocity is too low.  Try again. \nphisgo = %f\n", phisgo);
            return 1;
        }
        else if (phisgo > hiphi) {
            printf("Friction Velocity is too high.  Try again. \nphisgo = %f\n", phisgo);
            return 1;
        }
    
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
                
                }
            }
        }
        
        //Calculate Omega from these values
        
        Omega = 1.0 + ((log(sigmasg)/log(2))/sigmao)*(omegao - 1.0);
        
        //Calculates qb[i] and qbtot
        
        if (np == 0) {
            phi = Omega*phisgo;
            *qbtot = GG(phi);
            *qbtot = (*qbtot)*0.00218*pow(ustar, 3)/(R*g);
        }
        else {
            for (i=0; i <= (np-1); i++) {
                zs = sqrt(data[i].D*data[i+1].D)/(Dsg);
                phi = Omega*phisgo*exp((0.0-beta)*(log(zs)));
                F = (data[i+1].pfs - data[i].pfs);
                qb[i] = F*GG(phi);
                *qbtot += qb[i];
            }
            for (i=0; i <= (np-1); i++) {  
                qb[i] = qb[i]/(*qbtot);
            }
            *qbtot = (*qbtot)*0.00218*pow(ustar, 3)/(100*R*g);
        }
        
        //Calculates the percent finer
        
        pfl[0] = 0.0;
        for(i=1; i < npp; i++)
            pfl[i] = pfl[i-1] + qb[i-1]*100.0;
    
    //FINALIZE
    return 0;
}