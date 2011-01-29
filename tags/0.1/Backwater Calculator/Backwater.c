/*
 *  Backwater.c
 *  Backwater Calculator
 *
 *  Created by Andrew Leman on 5/29/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "Backwater.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int Backwater(float S, float qw, float Cz, float initdepth, float x0, float step, float N, float na, 
                float Ds90, float alpha, int x[], float U[], float taub[], float eta[], float ksi[],
                float H[], int xMS[], float UMS[], float taubMS[], float etaMS[], float ksiMS[],
                float HMS[], int formulation) {
    //Initialize
    
    float Hp=0, FnH=0, FnHp=0, Cf=0;
    int i=0;
    
    //Run
        if (formulation == 1) {
            //Cf value for the Chezy formulation
            Cf = 1/(pow(Cz, 2));
            
            //CHEZY FORMULATION
            
            //  0 node values
            x[0] = x0;
            H[0] = initdepth;
            FnH = (S-(Cf*pow(qw,2)/(g*pow(H[0],3))))/(1-(pow(qw,2)/(g*pow(H[0],3))));
            Hp = H[0]-(FnH*step);
            FnHp = (S-(Cf*pow(qw,2)/(g*pow(Hp,3))))/(1-(pow(qw,2)/(g*pow(Hp,3))));
            U[0] = qw/H[0];
            taub[0] = 1000*Cf*pow(U[0],2);
            eta[0] = 0;
            ksi[0] = H[0] + eta[0];
            
            //  1 to N-1 nodes
            for(i=1; i < N; i++) {
                x[i] = x[i-1]-step;
                H[i] = H[i-1] - (0.5*(FnH + FnHp)*step);
                FnH = (S-(Cf*pow(qw,2)/(g*pow(H[i],3))))/(1-(pow(qw,2)/(g*pow(H[i],3))));
                Hp = H[i]-(FnH*step);
                FnHp = (S-(Cf*pow(qw,2)/(g*pow(Hp,3))))/(1-(pow(qw,2)/(g*pow(Hp,3))));
                U[i] = qw/H[i];
                taub[i] = 1000*Cf*pow(U[i],2);
                eta[i] = eta[i-1] + (S*step);
                ksi[i] = H[i] + eta[i];
            }
        }
        
        //Cf value for Manning Strickler changes with the for loop, so it is included
        //MANNING STRICKLER FORMULATION
        
        if (formulation == 2) {
            //  0 node values
            xMS[0] = x0;
            HMS[0] = initdepth;
            Cf = (cbrt((na*Ds90)/HMS[0]))/(pow(alpha,2));
            FnH = (S-(Cf*pow(qw,2)/(g*pow(HMS[0],3))))/(1-(pow(qw,2)/(g*pow(HMS[0],3))));
            Hp = HMS[0]-(FnH*step);
            Cf = (cbrt((na*Ds90)/Hp))/(pow(alpha,2));
            FnHp = (S-(Cf*pow(qw,2)/(g*pow(Hp,3))))/(1-(pow(qw,2)/(g*pow(Hp,3))));
            U[0] = qw/HMS[0];
            taubMS[0] = 1000*Cf*pow(UMS[0],2);
            etaMS[0] = 0;
            ksiMS[0] = HMS[0] + etaMS[0];
            
            //  1 to N-1 nodes
            for(i=1; i < N; i++) {
                xMS[i] = xMS[i-1]-step;
                HMS[i] = HMS[i-1] - (0.5*(FnH + FnHp)*step);
                Cf = (cbrt((na*Ds90)/HMS[i]))/(pow(alpha,2));
                FnH = (S-(Cf*pow(qw,2)/(g*pow(HMS[i],3))))/(1-(pow(qw,2)/(g*pow(HMS[i],3))));
                Hp = HMS[i]-(FnH*step);
                Cf = (cbrt((na*Ds90)/Hp))/(pow(alpha,2));
                FnHp = (S-(Cf*pow(qw,2)/(g*pow(Hp,3))))/(1-(pow(qw,2)/(g*pow(Hp,3))));
                UMS[i] = qw/HMS[i];
                taubMS[i] = 1000*Cf*pow(UMS[i],2);
                etaMS[i] = etaMS[i-1] + (S*step);
                ksiMS[i] = HMS[i] + etaMS[i];
            }
        }
                
    //Finalize
    return 0;
}