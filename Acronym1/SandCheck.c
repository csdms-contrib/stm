/*
 *  SandCheck.c
 *  Acronym1
 *
 *  Created by Andrew Leman on 6/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SandCheck.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct { 
    float D;
    float pfs;
    } pair;

int SandCheck(pair data[], int *npp, int *np, int *nppo) {
    //Initialize
    int checklessthan2=0, check2=0, i=0;
    float border=0;
    
    //Run
        //Checks for no sand--this model does not work with sand--and finds the
        // sand-gravel border
        
        for (i=0; i < *npp; i++) {
            if (data[i].D < 2.0) {
                checklessthan2++;
            }
            else if (data[i].D == 2.0) {
                check2++;
                border = data[i].pfs;
            }
        }
        
        //Drops sand and renormalizes if there is a border value, otherwise exits
        if ((checklessthan2 != 0) && (check2 == 0)) {
            printf("Model does not work with sand.  Please reenter data that fits this model.\n");
            return 1;
        }
        else if ((checklessthan2 != 0) && (check2 != 0)) {
            *nppo = *npp;
            for (i=0; i < *nppo; i++) {
                if (data[i].D < 2.0) {
                    data[i].D = 100000;
                    *npp = *npp - 1;
                }
                else if (data[i].D == 2.0)
                    data[i].pfs = 0;
                else
                    data[i].pfs = 100*(data[i].pfs - border)/(100 - border);
            }
            printf("Sand data has been dropped and percent finer has been renormalized. \n");
        }
    
        //define np
        
        *np = *npp - 1;
    
    //Finalize
    return 0;
}