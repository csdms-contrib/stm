/*
 *  Run.c
 *  Backwater Calculator
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Backwater(float, float, float, float, float, float, float, float, float, float,
        int [], float [], float [], float [], float [], float [], int [], float [],
        float [], float [], float [], float [], int formulation);

int Run(float S, float qw, float Cz, float initdepth, float x0, float step, float N,
    float na, float Ds90, float alpha, int x[], float U[], float taub[], float eta[],
    float ksi[], float H[], int xMS[], float UMS[], float taubMS[], float etaMS[],
    float ksiMS[], float HMS[], int formulation) {

    Backwater(S, qw, Cz, initdepth, x0, step, N, na, Ds90, alpha, x, U, taub,
                    eta, ksi, H, xMS, UMS, taubMS, etaMS, ksiMS, HMS, formulation);
    return 0;

}