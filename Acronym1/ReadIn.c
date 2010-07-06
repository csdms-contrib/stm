/*
 *  ReadIn.c
 *  Acronym1
 *
 *  Created by Andrew Leman on 6/10/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { 
    float D;
    float pfs;
    } pair; 

int ReadIn(pair data[], float *R, float *ustar, int *npp, float *Dsg, float *Dlg, float *sigmasg, float *sigmalg) {
    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    float temp=0, temp1=0, temp2=0;
    int i=0;

    //Run
    
        //Opens file for reading
        
        printf("Please enter the name of your input file.\n(has to be a *.txt file)\n");
        scanf("%s", &nameIn);
        ptrIn = fopen(nameIn, "r");
        if (ptrIn == NULL) {
            printf("Error! Input file does not exist.  Make sure file is in proper folder.\n");
            return 1;
        }
        
        //Reads in values
        
        //First the constants R and ustar 
        for (i=0; i < 2; i++) {
            fscanf(ptrIn, "%c   %f\n", &indicator, &temp);
            switch (indicator) {
                case 'R':
                        *R = temp;
                        break;
                case 'u':
                        *ustar = temp;
                        break;
                default:
                        printf("Error! Wrong alphabetical indicator, please see 'Key for Inputs' \n");
                        break;
            }
        }
        //Second the values of Ds and % finer
        i=0;
        while (EOF != fscanf(ptrIn, "%f  %f\n", &temp1, &temp2)) {
            data[i].D = temp1;
            data[i].pfs = temp2;
            i++;
        }
        
        //Assigns value to npp
       
         *npp = i;
        
        //checks that npp > 1
        
        if (*npp == 1) {
            *Dsg = data[0].D;
            *Dlg = data[0].D;
            if (*Dsg < 1.0)
                *Dsg = (*Dsg)*100;
            if (*Dlg < 1.0)
                *Dlg = (*Dlg)*100;
            *sigmasg = 1.0;
            *sigmalg = 1.0;
        }
        
        //Recalculates R
        
        *R -= 1;
    
    //Finalize
    fclose(ptrIn);
    return 0;
}
