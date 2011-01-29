/*
 *  FindDepthandVelocity.c
 *  Acronym1R
 *
 *  Created by Andrew Leman on 6/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindDepthandVelocity.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int FindDepthandVelocity(float *H, float *ustar, float nk, float Dx90s, float Qf, float B, float S) {
    //Initialize
    float ks=0, alphar=8.1, ep=0.001, Ho=0, Hnew=0, err=0;
    int i=0;
    
    //Run 
    ks = nk*(Dx90s/1000);
    Ho = pow(((cbrt(ks)*Qf*Qf)/(alphar*alphar*g*B*B*S)), 0.3);
    *H = Ho;
    while (i < 100) {
        i += 1;
        Hnew = Ho*pow((1 - ((*H)/B)), (-0.3));
        err = fabs(2*(Hnew - (*H))/(Hnew + (*H)));
        if (err <= ep) {
            *H = Hnew;
            break;
        }
        else {
            *H = Hnew;
        }
    }
    
    if (i == 100) {
        printf("Depth calculation failed. \n");
        return 1;
    }
    
    *ustar = sqrt(g*(*H)*S*(1-((*H)/B)));
    
    //Finalize
    return 0;
}