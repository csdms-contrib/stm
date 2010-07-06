/*
 *  FluvialBackwater.c
 *  1DDeltaBW
 *
 *  Created by Andrew Leman on 7/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FluvialBackwater.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FluvialBackwater(double Hfluv[], double etafluv[], double Cz, double sss,
    double dxbar, double Hn, double qw, double ksid, double ks, double alphar,
    int M, int formulation) {

    //Declarations
    double Hpred=0, fr2p=0, fr2=0, fnp=0, fn=0, Cf=0;
    int i=0;

    Hfluv[M+1] = ksid - etafluv[M+1];
    if (formulation == 1) {
        Cf = (1.0/pow(Cz, 2.0));
        for (i=1; i <= M; i++) {
            fr2p = qw*qw/(g*pow(Hfluv[M+2-i], 3));
            fnp = (etafluv[M+1-i] - etafluv[M+2-i] - Cf*fr2p*sss*dxbar)/(1.0 - fr2p);
            Hpred = Hfluv[M+2-i] - fnp;
            fr2 = qw*qw/(g*pow(Hpred, 3));
            fn = (etafluv[M+1-i] - etafluv[M+2-i] - Cf*fr2*sss*dxbar)/(1.0 - fr2);
            Hfluv[M+1-i] = Hfluv[M+2-i] - 0.5*(fn+fnp);
            if (Hfluv[M+1-i] < Hn)
                Hfluv[M+1-i] = Hn;
        }
    }
    else {
       for (i=1; i <= M; i++) {
            fr2p = qw*qw/(g*pow(Hfluv[M+2-i], 3));
            fnp = (etafluv[M+1-i] - etafluv[M+2-i] - (1.0/(alphar*alphar))*cbrt(ks/Hfluv[M+2-i])*fr2p*sss*dxbar)/(1.0 - fr2p);
            Hpred = Hfluv[M+2-i] - fnp;
            fr2 = qw*qw/(g*pow(Hpred, 3));
            fn = (etafluv[M+1-i] - etafluv[M+2-i] - (1.0/(alphar*alphar))*cbrt(ks/Hpred)*fr2*sss*dxbar)/(1.0 - fr2);
            Hfluv[M+1-i] = Hfluv[M+2-i] - 0.5*(fn+fnp);
            if (Hfluv[M+1-i] < Hn)
                Hfluv[M+1-i] = Hn;
        }
 
    }
    return 0;
}