/*
 *  Run.c
 *  Acronym1D
 *
 *  Created by Andrew Leman on 7/2/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Run.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  {
    float D;
    float pfs;
} pair;

typedef struct {
    float Qwd;
    float pQf;
} pair2;

int GeometricMean(pair [], float [], int, float *, float *, int);
int GeometricStandardDeviation(pair [], float [], int, float *, float *, int);
int FindDepthandVelocity(float *, float *, float, float, float, float, float);
int CalcLoadandDistribution(pair [], int, int, float *, float, float, float,
        float [], float [], float [], float, double *, float [], float []);
int CalculateAverages(float [], float [], float [][16], float [], float [], float [],
        float [], float [], float [], float *, float *, float *, float *, float *, int, int, int);
int Interpolation(pair [], float [], int, int, float *, float *, float *, float *, float *,
        float *, float *, float *, int);

int Run(pair data[], pair2 flowdata[], int ndd, float *Qf, float *Qwa, float *H, float *ustar,
    float nk, float *Dx90s, float B, float S, float *Ha, float *ustara, int npp, int np,
    float *tausg, float R, float *Dsg, float po[], float so[], float oo[], float *sigmasg,
    double *qbtot, float pfl[], float qb[], float *tausga, float *qTa, float pla[],
    float pfla[], int nd, float Qwr[], float Hd[], float ustard[], float tausgd[], float qTd[],
    float pQ[], float pfld[][16], float swap, float *Dx30s, float *Dx50s, float *Dx70s,
    float *Dx30l, float *Dx50l, float *Dx70l, float *Dx90l, float *Dlg, float *sigmalg) {

    //Declaration
    int i=0, j=0, check=0;

    //NDD = 1 (Note that it is 2 due to the way that it is read in)
    //This is in fact the case of only one flow rate being entered
    
    if (ndd == 2) {
        
        //Assign value to Qf and Qwa
        *Qf = flowdata[1].Qwd;
        *Qwa = flowdata[1].Qwd;
        
        //Calculates H and ustar
        check = FindDepthandVelocity(&(*H), &(*ustar), nk, *Dx90s, *Qf, B, S);
        if (check == 1)
            return 1;
            
        //Assigns those values out
        *Ha = *H;
        *ustara = *ustar;
        
        //Calculates the Load Distribution
        CalcLoadandDistribution(data, npp, np, &(*tausg), R, *Dsg, *ustar, po,
                                so, oo, *sigmasg, &(*qbtot), pfl, qb);
                                
        //Assigns those values out again
        *tausga = *tausg;
        *qTa = *qbtot;
        
        //Calculates the pla values
        if(npp > 1) {
            for (i=0; i <= np; i++) {
                pla[i] = pfl[i];
                pfla[i] = pla[i];
            }
        }
    }
    
    //NDD > 1
    
    else {
        for (i=0; i < nd; i++) {
    
                //Assign value to Qf
                *Qf = Qwr[i];
    
                //Calculates H and ustar
                check = FindDepthandVelocity(&(*H), &(*ustar), nk, *Dx90s, *Qf, B, S);
                if (check == 1)
                    return 1;
                
                //Assigns those values out to a matrix
                Hd[i] = *H;
                ustard[i] = *ustar;
    
                //Calculates the Load Distribution
                CalcLoadandDistribution(data, npp, np, &(*tausg), R, *Dsg, *ustar, po,
                                        so, oo, *sigmasg, &(*qbtot), pfl, qb);
                                
                //Assigns the values out to a matrix
                tausgd[i] = *tausg;
                qTd[i] = *qbtot;
                for (j=0; j < npp; j++) {
                    pfld[j][i] = pfl[j];
                }
        }
   
        //Calculates Averages of the matrices above
        CalculateAverages(Qwr, pQ, pfld, qTd, Hd, ustard, tausgd, pfla, pla, &(*Qwa),
                    &(*qTa), &(*Ha), &(*ustara), &(*tausga), npp, np, nd);
    }
    
    //Crunches Load Distribution
    
        //Calculates Interpolants for Bedload
        if (npp != 1)
        Interpolation(data, pfla, npp, np, &(*Dx30s), &(*Dx50s), &(*Dx70s), &(*Dx90s), &(*Dx30l), &(*Dx50l),
                    &(*Dx70l), &(*Dx90l), swap);
                  
        //Calculates Bedload Geometric Mean
        if (npp != 1)
        GeometricMean(data, pla, npp, &(*Dsg), &(*Dlg), swap);
    
        //Calculates Bedload Standard Deviation
        if (npp != 1)
        GeometricStandardDeviation(data, pla, npp, &(*sigmasg), &(*sigmalg), swap);

    return 0;

}