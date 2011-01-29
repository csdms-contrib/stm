/*
 *  FindSlopesandShieldsStress.c
 *  AgDegNormGravMixPW
 *
 *  Created by Andrew Leman on 6/18/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindSlopesandShieldsStress.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindSlopesandShieldsStress(int M, double eta[], double Sl[], double tausg[], double taus50[],
            double H[], double dx, double nk, double Dx90s[], double Dx50s[], double qw,
            double alphar, double R, double dsgs[], double Cf, int formulation) {
    //Initialize
    double kc=0;
    int i=0;
    
    //Run
        //Find Slopes
        for (i=1; i <= (M+1); i++) {
            if (i == 1)
                Sl[i] = (eta[1]-eta[2])/dx;
            else if (i == (M+1))
                Sl[i] = (eta[M]-eta[M+1])/dx;
            else
                Sl[i] = (eta[i-1]-eta[i+1])/(2*dx);
        }
        for (i=1; i <= (M+1); i++) {
            if (formulation == 1) {
                kc = nk*Dx90s[i]/1000;
                tausg[i] = pow(((qw*qw*pow(kc, (1.0/3.0)))/(alphar*alphar*g)), 0.3);
                taus50[i] = tausg[i];
                if (Sl[i] <= 0) {
                    tausg[i] = 0;
                    taus50[i] = 0;
                    H[i] = 0;
                }
                else {
                    tausg[i] = tausg[i]*pow(Sl[i], 0.7)/(R*(dsgs[i]/1000));
                    taus50[i] = taus50[i]*pow(Sl[i], 0.7)/(R*(Dx50s[i]/1000));
                    H[i] = pow(((cbrt(kc)*qw*qw)/(alphar*alphar*g*Sl[i])), 0.3);
                }
            }
            else {
                if (Sl[i] <= 0) {
                    tausg[i] = 0;
                    taus50[i] = 0;
                    H[i] = 0;
                }
                else {
                    H[i] = pow((qw*qw*Cf/(g*Sl[i])), (1.0/3.0));
                    tausg[i] = H[i]*Sl[i]/(R*(dsgs[i]/1000));
                    taus50[i] = H[i]*Sl[i]/(R*(Dx50s[i]/1000));
                }
            }
        }
    
    //Finalize
    return 0;
}