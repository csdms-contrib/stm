/*
 *  UltimateEquilibria.c
 *  AgDegNormalFault
 *
 *  Created by Andrew Leman on 6/9/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "UltimateEquilibria.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int UltimateEquilibria(double *qtf, double *tauult, double *Sult, double *Hult, double Gtf,
                        double R, double If, double B, double tauc, double D, double alphat,
                        double nt, double phis, double alphar, double Qf, double kc, double Cf,
                        int formulation, double S) {
    //Initialize
    double exponent1=(10.0/7.0), exponent2=(3.0/7.0), arg1=0, arg2=0;
    
    //Run
    *qtf = Gtf/((R+1)*60*60*24*365.25*B*If);
    *tauult = (tauc + pow((*qtf/(sqrt(g*R*D)*D*alphat)),(1/nt)))/phis;
    if (formulation == 1) {
        arg1 = (R*D*(*tauult));
        arg2 = ((alphar*alphar*B*B*g)/(Qf*Qf*cbrt(kc)));
        *Sult = pow(arg1, exponent1)*pow(arg2, exponent2);
    }
    else {
        arg1 = (R*D*(*tauult))*cbrt(g*B*B/(Qf*Qf*Cf));
        *Sult = pow(arg1, 1.5);
    }
    *Hult = R*D*(*tauult)/(*Sult);
    
    //Finalize
    return 0;
}
