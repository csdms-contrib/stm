/*
 *  Findtausmin.c
 *  DredgeSlotBW
 *
 *  Created by Andrew Leman on 7/27/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Findtausmin.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Findtausmin(double *tausmin, double Fr, int *bombed) {

    double ep=0.001, xtausminnew=0, err=0, Ft=0, Ftp=0;
    int i=0;
    
    *tausmin = 0.4;
    for (i=1; i <= 201; i++) {
        Ft = *tausmin - 0.05 - 0.7*pow(*tausmin, 0.8)*pow(Fr, (14.0/25.0));
        Ftp = 1.0 - 0.7*(0.8)*pow(*tausmin, -0.2)*pow(Fr, (14.0/25.0));
        xtausminnew = *tausmin - (Ft/Ftp);
        err = fabs(2*(xtausminnew - *tausmin)/(xtausminnew + (*tausmin)));
        if (err < ep) {
            break;
        }
        else if (i > 200) {
            *bombed = 1;
            break;
        }
        else {
            *tausmin = xtausminnew;
        }
    }
    if (*bombed == 0) {
        *tausmin = xtausminnew;
    }
    else {
        printf("Calculation of tausmin failed to converge!  Please try again.\n");
        return 1;
    }

    return 0;
}