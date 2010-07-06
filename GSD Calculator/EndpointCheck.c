/*
 *  EndpointCheck.c
 *  GSD Calculator
 *
 *  Created by Andrew Leman on 5/28/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "EndpointCheck.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float size;
    float perfiner;
} pair;

int EndpointCheck(pair datapoints[], int terms) {
    //Initialize
    int i=0, check1=0, check2=0;
    float psi[terms+3];

    //Run
    for(i=0; i<=terms; i++) {
        if(datapoints[i].perfiner == 1.0)
            check1++;
        else if(datapoints[i].perfiner == 0.0)
            check2++;
    }
    
    if(check1 == 0) {
        psi[terms]=(log(datapoints[terms].size))/(log(2));
        psi[terms-1]=(log(datapoints[terms-1].size))/(log(2));
        psi[terms+1]=psi[terms]+((psi[terms]-psi[terms-1])/(datapoints[terms].perfiner-datapoints[terms-1].perfiner))*(1-datapoints[terms].perfiner);
        datapoints[terms+1].size=pow(2, psi[terms+1]);
        datapoints[terms+1].perfiner=1.0;
        terms++;
    }
    
    if(check2 == 0) {
        psi[0]=(log(datapoints[0].size))/(log(2));
        psi[1]=(log(datapoints[1].size))/(log(2));
        psi[terms+2]=psi[0]-((psi[1]-psi[0])/(datapoints[1].perfiner-datapoints[0].perfiner))*(datapoints[0].perfiner-0);
        for(i=terms+1; i >= 0; i--) {
            datapoints[i+1].size=datapoints[i].size;
            datapoints[i+1].perfiner=datapoints[i].perfiner;
        }
        datapoints[0].size=pow(2, psi[terms+2]);
        datapoints[0].perfiner=0.0;
        terms++;
    }
    
    //Finalize
    return terms;
}