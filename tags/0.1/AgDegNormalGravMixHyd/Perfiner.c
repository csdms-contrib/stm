/*
 *  Perfiner.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Perfiner.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int Perfiner(double Ft[], double Fft[], int npp) {
    //Initialize
    int i=0;
    
    //Run
    Fft[1] = 100;
    for (i=2; i <= npp; i++) {
        Fft[i] = Fft[i-1] - Ft[i-1]*100;
    }
    
    //Finalize
    return 0;
}
