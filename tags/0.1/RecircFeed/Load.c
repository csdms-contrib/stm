/*
 *  Load.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Load.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Load(double Htil[], double qtil[], double taur, double nt, int Nreach) {

    //Initialize
    int i=0;
    
    //Run
    for (i=1; i <= Nreach; i++) {
        if ((pow(Htil[i], (-2.0))) <= (1.0/taur)) {
            qtil[i] = 0;
        }
        else {
            qtil[i] = pow((pow(Htil[i], (-2.0)) - (1.0/taur))/(1.0 - (1.0/taur)), nt);
        }
    }
    
    //Finalize
    return 0;
}