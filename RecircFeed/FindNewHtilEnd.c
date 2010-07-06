/*
 *  FindNewHtilEnd.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/14/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "FindNewHtilEnd.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindNewHtilEnd(double Htil[], double bgh1[], double *Htilendnew, double Htilend, double dxhat, int Nreach) {
    
    double inth=0, intbgh1=0;
    int i=0;
    
    inth = 0.5*(Htil[1] + Htil[Nreach])*dxhat;
    intbgh1 = 0.5*(bgh1[1] + bgh1[Nreach])*dxhat;
    for (i=2; i <= (Nreach - 1); i++) {
        inth += Htil[i]*dxhat;
        intbgh1 += bgh1[i]*dxhat;
    }
    *Htilendnew = Htilend - (inth - 1.0)/intbgh1;
    
    return 0;
}