/*
 *  FluvialBackwater.c
 *  AgDegBW
 *
 *  Created by Andrew Leman on 6/4/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FluvialBackwater.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FluvialBackwater(double eta[], double ksi[], double H[], int M, float qw,
                    float alphar, float kc, float ksio, float dx, float Cf,
                    int formulation) {
    //Initialize
    float Hp=0, fn=0, fnp=0, Cf1=0, Fr2p=0, Fr2=0;
    int i=0;
    
    //Run
    H[M+1] = ksio - eta[M+1];
    
    for(i=1; i<= M; i++) {
        Fr2p = qw*qw/(g*pow(H[M+2-i], 3));
        if (formulation == 1)
            Cf1 = (1/pow(alphar, 2))*(pow((kc/H[M+2-i]), (1.0/3.0)));
        else
            Cf1 = Cf;
        fnp = (eta[M+1-i]-eta[M+2-i]-(Cf1*Fr2p*dx))/(1-Fr2p);
        Hp = H[M+2-i] - fnp;
        Fr2 = qw*qw/(g*pow(Hp, 3));
        fn = (eta[M+1-i]-eta[M+2-i]-Cf1*Fr2*dx)/(1-Fr2);
        H[M+1-i] = H[M+2-i] - 0.5*(fnp + fn);
    }
    
    for(i=1; i <= M; i++) {
        ksi[i] = eta[i] + H[i];
    }
    
    //Finalize
    return 0;
}