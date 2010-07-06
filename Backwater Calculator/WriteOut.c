/*
 *  WriteOut.c
 *  Backwater Calculator
 *
 *  Created by Andrew Leman on 6/1/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "WriteOut.h"
#include <stdio.h>
#include <stdlib.h>

int WriteOut(float chezyH, float chezyU, float chezyFr, float chezytaub, float MSH,
                float MSU, float MSFr, float MStaub, float Hc, float Uc, int x[],
                float U[], float H[], float taub[], float eta[], float ksi[], int xMS[],
                float UMS[], float HMS[], float taubMS[], float etaMS[], float ksiMS[],
                int N, int formulation) {
    //Initialize
    FILE *ptrOut;
    char nameOut[50];
    int i=0;
    
    //Run
    printf("What do you want to call the output file? (less than 50 characters, please)\n");
    printf("WARNING: If you have a file with this name it will be overwritten.\n");
    scanf("%s", &nameOut);
    ptrOut = fopen(nameOut, "w");
    if(ptrOut == NULL) {
        return 1; }
    
    if (formulation == 1) {
        fprintf(ptrOut,"The chezy formulation H is: \t\t\t%f\n", chezyH);
        fprintf(ptrOut,"The chezy formulation U is: \t\t\t%f\n", chezyU);
        fprintf(ptrOut,"The chezy formulation Fr is: \t\t\t%f\n", chezyFr);
        fprintf(ptrOut,"The chezy formulation tau(b) is: \t\t\t%f\n", chezytaub);
    }
    
    if (formulation == 2) {
        fprintf(ptrOut,"\nThe Manning Stricker formulation H is: \t\t\t%f\n", MSH);
        fprintf(ptrOut,"The Manning Stricker formulation U is: \t\t\t%f\n", MSU);
        fprintf(ptrOut,"The Manning Stricker formulation Fr is: \t\t\t%f\n", MSFr);
        fprintf(ptrOut,"The Manning Stricker formulation tau(b) is: \t\t\t%f\n", MStaub);
    }
    
    fprintf(ptrOut, "\nThe critical value for H is: \t\t\t%f\n", Hc);
    fprintf(ptrOut, "The critical value for U is: \t\t\t%f\n", Uc);
        
    if (formulation == 1) {
        fprintf(ptrOut,"\nFor the Chezy formulation: \nx\tH\tU\ttau(b)\teta\tksi\n");
            for(i=0; i < N; i++) {
                    fprintf(ptrOut,"%i\t%f\t%f\t%f\t%f\t%f\n", x[i], H[i], U[i], taub[i], eta[i], ksi[i]);
            }
    }
     
    if (formulation == 2) {
        fprintf(ptrOut,"\nFor the Manning Strickler formulation: \nx\tH\tU\ttau(b)\teta\tksi\n");
            for(i=0; i < N; i++) {
                    fprintf(ptrOut,"%i\t%f\t%f\t%f\t%f\t%f\n", xMS[i], HMS[i], UMS[i], taubMS[i], etaMS[i], ksiMS[i]);
            }
    }

    //Finalize
    fclose(ptrOut);
    return 0;
}