#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

//defines the pair structure

typedef struct  {
    float D;
    float pfs;
} pair;

//prototypes of functions
int Initialize(pair [], float *, float *, int *, float *, float *, float *, float *,
        float *, float *, float *, float *, int *, int *, float [], float *, float [],
        float *, float *, float *, float *, float *, float *, float *, float [],
        float [], float []);
int Run(pair [], float *, float *, float, float *, float, float, float, int, int,
        float *, float, float *, float [], float [], float [], float *, double *,
        float [], float [], float, float *, float *, float *, float *, float *,
        float *, float *, float *, float *);
int Finalize(pair [], int, float [], float, double, float, float, float, float,
        float, float, float, float, float, float, float, float, float, float);

int main (int argc, const char * argv[]) {

    //DECLARATIONS
  
    pair data[23];
    float R=0, ustar=0, Dsg=0, sigmasg=0, po[37], oo[37], so[37], tausg=0;
    float Dx30s=0, Dx50s=0, Dx70s=0, Dx90s=0, Dx30l=0, Dx50l=0, Dx70l=0, Dx90l=0;
    float Dlg=0, sigmalg=0, swap=0, H=0, Qf=0, B=0, S=0, nk=0;
    double qbtot=0;
    int npp=0, np=0, nppo=0, check=0;
    float pfl[23], qb[23];
        

        check = Initialize(data, &R, &Qf, &npp, &Dsg, &Dlg, &sigmasg, &sigmalg, &S, &B, &nk,
                &Dx90s, &np, &nppo, qb, &swap, pfl, &Dx70s, &Dx50s, &Dx30s, &Dx90l, &Dx70l,
                &Dx50l, &Dx30l, po, oo, so);
        if (check == 1)
            return 1;
        
        check = Run(data, &H, &ustar, nk, &Dx90s, Qf, B, S, npp, np, &tausg, R, &Dsg, po,
                so, oo, &sigmasg, &qbtot, pfl, qb, swap, &Dx70s, &Dx50s, &Dx30s, &Dx90l,
                &Dx70l, &Dx50l, &Dx30l, &Dlg, &sigmalg);
        if (check == 1)
            return 1;
        
        Finalize(data, npp, pfl, tausg, qbtot, Dsg, Dlg, sigmasg, sigmalg, Dx30s,
                Dx50s, Dx70s, Dx90s, Dx30l, Dx50l, Dx70l, Dx90l, H, ustar);
        
    return 0;
}