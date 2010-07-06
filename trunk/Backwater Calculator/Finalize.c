/*
 *  Finalize.c
 *  Backwater Calculator
 *
 *  Created by Andrew Leman on 6/30/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Finalize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WriteOut(float, float, float, float, float, float, float, float, float, float, int [], float [], float [],
        float [], float [], float [], int [], float [], float [], float [], float [], float [], int, int);

int Finalize(float chezyH, float chezyU, float chezyFr, float chezytaub, float MSH,
    float MSU, float MSFr, float MStaub, float Hc, float Uc, int x[], float U[],
    float H[], float taub[], float eta[], float ksi[], int xMS[], float UMS[], float HMS[],
    float taubMS[], float etaMS[], float ksiMS[], int N, int formulation) {

    WriteOut(chezyH, chezyU, chezyFr, chezytaub, MSH, MSU, MSFr, MStaub, Hc,
                Uc, x, U, H, taub, eta, ksi, xMS, UMS, HMS, taubMS, etaMS, ksiMS, N,
                formulation);
    printf("\nYour file has been written.\n");
    return 0;

}