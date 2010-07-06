/*
 *  ReadIn.c
 *  GravelSandTransition
 *
 *  Created by Andrew Leman on 7/21/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "ReadIn.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ReadIn(double *Qbf, double *L, double *sgsl, double *ksid, double *ksidot,
    double *subrate, double *Yearstart, double *Yearstop, double *dt, double *qfeeds,
    double *qfeedg, double *Ifs, double *Ifg, double *Ds, double *Dg, double *Czs,
    double *Czg, double *Bs, double *Bg, double *Ssl, double *Sgl, double *Bds,
    double *Bdg, double *Omegas, double *Omegag, double *lamdams, double *lamdasg,
    double *Cfs, double *Cfg, double *sfsl, double *dxbars, double *dxbarg, double *qwg,
    double *qws, double *qfg, double *qfs, double *rBg, double *rBs, double *Ifgeff,
    double *Ifseff, double *R, double *lamps, double *lampg, int *prints, int *iterates,
    int *Ms, int *Mg) {
    
    //Initialize
    FILE *ptrIn;
    char nameIn[50], indicator;
    double temp=0, temp1=0, temp2=0;
    double Lmax=0, Hs=0, Ss=0, Frs=0, taus=0, qfeedstar=0, Hg=0, Sg=0, taug=0, Frg=0, ksimin=0;
    double f=1, fprime=0, qgfeedstar=0;
    int i=0;
    
    //Run
    printf("Please enter the name of your input file.\n(has to be a *.txt file)\n");
    scanf("%s", nameIn);
    ptrIn = fopen(nameIn, "r");
    if (ptrIn == NULL) {
        printf("Error! Input file does not exist. Make sure file is in proper folder. \n");
        return 1;
    }
    
    for(i=1; i<= 12; i++) {
        fscanf(ptrIn, "%s  %lf\n", &indicator, &temp);
        switch (indicator) {
            case 'Q':
                    *Qbf = temp;
                    break;
            case 'R':
                    *R = temp;
                    break;
            case 'L':
                    *L = temp;
                    break;
            case 's':
                    *sgsl = temp;
                    break;
            case 'k':
                    *ksid = temp;
                    break;
            case 'x':
                    *ksidot = (temp/1000.0)/31557600.0;
                    break;
            case 'S':
                    *subrate = (temp/1000.0)/31557600.0;
                    break;
            case 'y':
                    *Yearstart = temp*31557600.0;
                    break;
            case 'Y':
                    *Yearstop = temp*31557600.0;
                    break;
            case 't':
                    *dt = temp*31557600.0;
                    break;
            case 'p':
                    *prints = temp;
                    break;
            case 'i':
                    *iterates = temp;
                    break;
            default:
                    printf("Not a valid entry, pleade edit file and try again.\n");
                    return 1;
        }
    }
    
    while (EOF != fscanf(ptrIn, "%s  %lf  %lf\n", &indicator, &temp1, &temp2)) {
        switch (indicator) {
            case 'q':
                    *qfeeds = temp1;
                    *qfeedg = temp2;
                    break;
            case 'I':
                    *Ifs = temp1;
                    *Ifg = temp2;
                    break;
            case 'D':
                    *Ds = temp1/1000.0;
                    *Dg = temp2/1000.0;
                    break;
            case 'C':
                    *Czs = temp1;
                    *Czg = temp2;
                    break;
            case 'B':
                    *Bs = temp1;
                    *Bg = temp2;
                    break;
            case 'S':
                    *Ssl = temp1;
                    *Sgl = temp2;
                    break;
            case 'd':
                    *Bds = temp1;
                    *Bdg = temp2;
                    break;
            case 'O':
                    *Omegas = temp1;
                    *Omegag = temp2;
                    break;
            case 'l':
                    *lamdams = temp1;
                    *lamdasg = temp2;
                    break;
            case 'L':
                    *lamps = temp1;
                    *lampg = temp2;
            case 'M':
                    *Ms = temp1;
                    *Mg = temp2;
                    break;
            default:
                    printf("Not a valid entry, pleade edit file and try again.\n");
                    return 1;
        }
    }
    
    //Calculation of other constants
    *sfsl = *L - *sgsl;
    *dxbarg = 1.0/(*Mg);
    *dxbars = 1.0/(*Ms);
    *Cfg = 1.0/pow(*Czg, 2);
    *Cfs = 1.0/pow(*Czs, 2);
    *qwg = *Qbf/(*Bg);
    *qws = *Qbf/(*Bs);
    *qfg = *qfeedg/(*Bg);
    *qfs = *qfeeds/(*Bs);
    *rBg = *Bdg/(*Bg);
    *rBs = *Bds/(*Bs);
    *Ifgeff = *Ifg*(1.0 + *lamdasg)*(*Omegag)/(*rBg);
    *Ifseff = *Ifs*(1.0 + *lamdams)*(*Omegas)/(*rBs);
    
    //Checks that certain qualifications are met
    if (*ksidot > *subrate) {
        Lmax = 1.0/(*ksidot)*(*Ifg*(1.0 + *lamdasg)*(*Omegag)*(*qfeedg/(*Bg))/((1.0 - *lampg)*(*Bdg/(*Bg))) + *Ifs*(1.0 + *lamdams)*(*Omegas)*((*qfeeds/(*Bs)) - *lamdasg*(*qfeedg/(*Bg)))/((1.0 - *lamps)*(*Bds/(*Bs))));
    }
    else {
        Lmax = 1.0/(*subrate)*(*Ifg*(1.0 + *lamdasg)*(*Omegag)*(*qfeedg/(*Bg))/((1.0 - *lampg)*(*Bdg/(*Bg))) + *Ifs*(1.0 + *lamdams)*(*Omegas)*((*qfeeds/(*Bs)) - *lamdasg*(*qfeedg/(*Bg)))/((1.0 - *lamps)*(*Bds/(*Bs))));
    }
    if (*L > Lmax) {
        printf("The reach length L, must be smaller than the Lmax value!\nLmax = %lf\nL = %lf\n", Lmax, *L);
        return 1;
    }
    
    qfeedstar = *qfs/(sqrt(*R*9.81*(*Ds))*(*Ds));
    taus = pow((*Cfs*qfeedstar/0.05), 0.4);
    Ss = pow((*R*(*Ds)*taus), 1.5)/sqrt(*Cfs*pow((*Qbf/(*Bs)), 2)/9.81);
    Hs = cbrt(*Cfs*pow((*Qbf/(*Bs)), 2)/(9.81*(Ss)));
    Frs = sqrt(pow((*Qbf/(*Bs)), 2)/(9.81*pow((Hs), 3)));
    if (Frs >= 1) {
        printf("The Froude number for sand must be less than 1!\nFrs = %lf\n", Frs);
        return 1;
    }
    
    taug = 0.035;
    qgfeedstar = *qfg/(sqrt(*R*9.81*(*Dg))*(*Dg));
    while (fabs(f) > 0.0000000001) {
        f = 11.2*pow(taug, 1.5)*pow((1.0 - (0.03/taug)), 4.5) - qgfeedstar;
        fprime = 1.5*11.2*sqrt(taug)*pow((1 - (0.03/taug)), 4.5) + 11.2*4.5*pow((1-(0.03/taug)), 3.5)*0.03/sqrt(taug);
        taug += -(f/fprime);
    }
    Sg = pow((*R*(*Dg)*taug), 1.5)/sqrt(*Cfg*pow((*qwg), 2)/9.81);
    Hg = cbrt(*Cfg*pow(*qwg, 2)/(9.81*Sg));
    Frg = sqrt(pow(*qwg, 2)/(9.81*pow(Hg, 3)));
    if (Frg >= 1) {
        printf("The Froude number for gravel must be less than 1!\nFrg = %lf\n", Frg);
        return 1;
    }
    
    ksimin = cbrt(pow((*Qbf/(*Bs)), 2)/9.81);
    if (ksimin >= *ksid) {
        printf("The downstream water surface must be greater than the minimum!\nksimin = %lf\n", ksimin);
    }
    
    //Finalize
    fclose(ptrIn);
    return 0;
}
