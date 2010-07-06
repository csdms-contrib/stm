/*
 *  Initialize.c
 *  RecircFeed
 *
 *  Created by Andrew Leman on 7/13/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *, double *, double *, double *, double *, double *, int *, double *,
    int *, int *, int *, double *, double *, double *, double *, double *);
int SetInitialBed(double [], double [], double *, double *, double *, double, double,
    double, int);
int Backwater(double [], double [], double [], double, double, double, double, double, double *, double, int *, int, int);
int Load(double [], double [], double, double, int);

int Initialize(double xhat[], double etadhat[], double Htil[], double qtil[], double bgh1[],
    double *etatila, double *SNup, double *SNdown, double *Fro, double *nt,
    double *Fl, double *etatilainit, double *taur, double *SNl, double *dt,
    double *dxhat, double *Nhalf, double *qw, double *Ntot, double *qtilg, double *Htilend,
    double *timehat, int *M, int *prints, int *iterates, int *Nreach, int *flume, int *bombed) {

    //Initialize
    int check=0;
    
    //Run
    check = ReadIn(&(*Fro), &(*nt), &(*Fl), &(*etatilainit), &(*taur), &(*SNl), &(*M), &(*dt),
        &(*prints), &(*iterates), &(*Nreach), &(*dxhat), &(*Nhalf), &(*qw), &(*Ntot), &(*qtilg));
    if (check == 1)
        return 1;
    SetInitialBed(xhat, etadhat, &(*etatila), &(*SNup), &(*SNdown), *etatilainit, *dxhat, *SNl, *Nreach);
    printf("Is this data for:\n1. a feed flume\n2. a recirculating flume\n");
    scanf("%i", &(*flume));
    if ((*flume != 1) && (*flume != 2)) {
        printf("Improper Response! Please try again.\n");
        return 1;
    }
    Backwater(etadhat, Htil, bgh1, *dxhat, *qw, *Fro, *etatila, *Fl, &(*Htilend), *timehat, &(*bombed), *Nreach, *flume);
    Load(Htil, qtil, *taur, *nt, *Nreach);
    
    //Finalize
    return 0;
}