/*
 *  FindTausmin.c
 *  BackwaterWrightParker
 *
 *  Created by Andrew Leman on 7/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindTausmin.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindTausmin(double *xFr, double *xtausmin) {

    //Initialize
    double ep=0.001, xtausminnew=0, er=0, Ft=0, Ftp=0;
    int i=0, bombed=0;
    
    //Run
    *xtausmin = 0.4;
    for (i=1; i <= 201; i++) {
        Ft = (*xtausmin) - 0.05 - 0.7*pow((*xtausmin), (0.8))*pow((*xFr), (14.0/25.0));
        Ftp = 1 - 0.7*0.8*pow((*xtausmin), -0.2)*pow((*xFr), (14.0/25.0));
        xtausminnew = *xtausmin - (Ft/Ftp);
        er = fabs(2*(xtausminnew - (*xtausmin))/(xtausminnew + (*xtausmin)));
        if (er < ep) {
            break;
        }
        else if (i == 200) {
            bombed = 1;
            break;
        }
        else {
            *xtausmin = xtausminnew;
        }
    }
    if (bombed == 0) {
        *xtausmin = xtausminnew;
    }
    else {
        printf("tausmin calculation did not converge.\n");
        return 1;
    }

    //Finalize
    return 0;
}