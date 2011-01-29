/*
 *  FindNewEta.c
 *  1DRiverWFRisingBaseLevelNormal
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewEta.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindNewEta(double eta[], double Qt[], double I, double Sinu, double lambig,
    double Bf, double lamp, double dt, double time, double dx, double Qbtffeed,
    double Yearstart, double Yearstop, double etaddot, int M) {

    //Declarations
    int i=0;
    double etaddotdummy=0;
    double Qtback=0, Qtfront=0;
    
    for (i=1; i <= M; i++) {
        if (i == 1) {
            Qtback = Qbtffeed;
        }
        else {
            Qtback = Qt[i-1];
        }
        Qtfront = Qt[i+1];
        eta[i] += I*Sinu*(1 + lambig)*(Qtback - Qtfront)*dt/(2.0*dx*Bf*(1-lamp));
    }
    if ((time + dt) < Yearstart) {
        etaddotdummy = 0;
    }
    else if ((time + dt) < Yearstop) {
        etaddotdummy = etaddot;
    }
    else {
        etaddotdummy = 0;
    }
    eta[M+1] += etaddotdummy*dt;
    
    return 0;
}