/*
 *  EndpointCheck.c
 *  AgDegNormalGravMixHyd
 *
 *  Created by Andrew Leman on 6/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "EndpointCheck.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

int EndpointCheck(quad GSD[], int *npp, int *np) {
    //Initialize
    int check1=0, check2=0, check3=0;
    double psi[3];
    
    //Run
        //Checks the three GSDs for 0 values
        if (fabs(GSD[*npp].plff) > 0.0001)
            check1++;
        if (fabs(GSD[*npp].Ffl) > 0.0001)
            check2++;
        if (fabs(GSD[*npp].Ffs) > 0.0001)
            check3++;
            
        //Adds them where necessary
        if (check1 == 1) {
            psi[1] = log(GSD[*npp].di)/log(2);
            psi[0] = log(GSD[*npp-1].di)/log(2);
            psi[2] = psi[1] - ((psi[0] - psi[1])/(GSD[*npp-1].plff - GSD[*npp].plff))*(GSD[*npp].plff);
            GSD[*npp+1].di = pow(2, psi[2]);
            GSD[*npp+1].plff = 0;
            GSD[*npp+1].Ffl = 0;
            GSD[*npp+1].Ffs = 0;
            if((GSD[*npp+1].di != GSD[*npp].di) && (GSD[*npp+1].di != GSD[*npp-1].di))
                *npp += 1;
        }
        if (check2 == 1) {
            psi[1] = log(GSD[*npp].di)/log(2);
            psi[0] = log(GSD[*npp-1].di)/log(2);
            psi[2] = psi[1] - ((psi[0] - psi[1])/(GSD[*npp-1].Ffl - GSD[*npp].Ffl))*(GSD[*npp].Ffl);
            GSD[*npp+1].di = pow(2, psi[2]);
            GSD[*npp+1].plff = 0;
            GSD[*npp+1].Ffl = 0;
            GSD[*npp+1].Ffs = 0;
            if((GSD[*npp+1].di != GSD[*npp].di) && (GSD[*npp+1].di != GSD[*npp-1].di))
                *npp += 1;
        }
        if (check3 == 1) {
            psi[1] = log(GSD[*npp].di)/log(2);
            psi[0] = log(GSD[*npp-1].di)/log(2);
            psi[2] = psi[1] - ((psi[0] - psi[1])/(GSD[*npp-1].Ffs - GSD[*npp].Ffs))*(GSD[*npp].Ffs);
            GSD[*npp+1].di = pow(2, psi[2]);
            GSD[*npp+1].plff = 0;
            GSD[*npp+1].Ffl = 0;
            GSD[*npp+1].Ffs = 0;
            if((GSD[*npp+1].di != GSD[*npp].di) && (GSD[*npp+1].di != GSD[*npp-1].di))
                *npp += 1;
        }
        
        //Checks the three GSDs for 100 values
        check1=0;
        check2=0;
        check3=0;
        if (fabs(GSD[1].plff - 100.0) > 0.0001)
            check1++;
        if (fabs(GSD[1].Ffl - 100.0) > 0.0001)
            check2++;
        if (fabs(GSD[1].Ffs - 100.0) > 0.0001)
            check3++;
            
        //Adds them where necessary
        if (check1 == 1) {
            psi[1] = log(GSD[1].di)/log(2);
            psi[0] = log(GSD[2].di)/log(2);
            psi[2] = psi[1] + ((psi[1] - psi[0])/(GSD[1].plff - GSD[2].plff))*(100.0 - GSD[1].plff);
            GSD[*npp+1].di = pow(2, psi[2]);
            GSD[*npp+1].plff = 100.0;
            GSD[*npp+1].Ffl = 100.0;
            GSD[*npp+1].Ffs = 100.0;
            if((GSD[*npp+1].di != GSD[*npp].di) && (GSD[*npp+1].di != GSD[*npp-1].di))
                *npp += 1;
        }
        if (check2 == 1) {
            psi[1] = log(GSD[1].di)/log(2);
            psi[0] = log(GSD[2].di)/log(2);
            psi[2] = psi[1] + ((psi[1] - psi[0])/(GSD[1].Ffl - GSD[2].Ffl))*(100.0 - GSD[1].Ffl);
            GSD[*npp+1].di = pow(2, psi[2]);
            GSD[*npp+1].plff = 100.0;
            GSD[*npp+1].Ffl = 100.0;
            GSD[*npp+1].Ffs = 100.0;
            if((GSD[*npp+1].di != GSD[*npp].di) && (GSD[*npp+1].di != GSD[*npp-1].di))
                *npp += 1;
        }
        if (check3 == 1) {
            psi[1] = log(GSD[1].di)/log(2);
            psi[0] = log(GSD[2].di)/log(2);
            psi[2] = psi[1] + ((psi[1] - psi[0])/(GSD[1].Ffs - GSD[2].Ffs))*(100.0 - GSD[1].Ffs);
            GSD[*npp+1].di = pow(2, psi[2]);
            GSD[*npp+1].plff = 100.0;
            GSD[*npp+1].Ffl = 100.0;
            GSD[*npp+1].Ffs = 100.0;
            if((GSD[*npp+1].di != GSD[*npp].di) && (GSD[*npp+1].di != GSD[*npp-1].di))
                *npp += 1;
        }
        
        //Corrects np as well
        *np = *npp - 1;
    
    //Finalize
    return 0;
}
