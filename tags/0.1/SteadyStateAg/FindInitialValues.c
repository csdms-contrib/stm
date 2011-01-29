/*
 *  FindInitialValues.c
 *  SteadyStateAg
 *
 *  Created by Andrew Leman on 7/22/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindInitialValues.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindInitialValues(double Qtbf[], double Sl[], double etahat[], double etadev[],
    double Bbf[], double Hbf[], double xhat[], double Qt, double beta, double Su, double L,
    double Cf, double aleh, double R, double D, double Qbf, double tauform) {

    int i=0;
    
    for(i=1; i <= 21; i++) {
        Qtbf[i] = Qt*(1.0 - beta*xhat[i]);
        Sl[i] = Su*(1.0 - beta*xhat[i]);
        etahat[i] = Su*((1.0 - (0.5*beta)) - xhat[i] + 0.5*beta*pow(xhat[i], 2));
        etadev[i] = 1000*L*etahat[i];
        Bbf[i] = (Cf/(aleh*pow(tauform, 2.5)*sqrt(R)))*(Qtbf[i]/(sqrt(9.81*D/1000)*(D/1000)));
        Hbf[i] = aleh*(pow(tauform, 2)/sqrt(Cf))*Qbf*(D/1000)/(Qtbf[i]);
    }
    
    return 0;
}