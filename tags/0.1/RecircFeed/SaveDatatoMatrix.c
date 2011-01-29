/*
 *  SaveDatatoMatrix.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SaveDatatoMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SaveDatatoMatrix(double printmatrix[][101], double Slmatrix[][101], double qbmatrix[][101],
    double Hmatrix[][101], double etadhat[], double Sl[], double qtil[], double Htil[],
    double time, double Fl, double etatila, int Nreach, int k, int flume) {
    
    //Declarations
    int i=0;
    
    for (i=1; i <= Nreach; i++) {
        if (flume == 1) {
            printmatrix[k][i] = etadhat[i] + Fl*etatila;
        }
        else {
            printmatrix[k][i] = etadhat[i];
        }
        Slmatrix[k][i] = Sl[i];
        qbmatrix[k][i] = qtil[i];
        Hmatrix[k][i] = Htil[i];
    }
    printmatrix[k][0] = time;
    Slmatrix[k][0] = time;
    qbmatrix[k][0] = time;
    Hmatrix[k][0] = time;
    return 0;
}