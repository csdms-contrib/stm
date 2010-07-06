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
    int *, int *, float [], float *, float [], float [], float [], float []);
int Run(pair [], float [], int, int, float *, float, float *, float, float [], float [],
    float [], float *, double *, float [], float *, float *, float *, float *, float *,
    float *, float *, float *, float *, float, float *);
int Finalize(pair [], int, float [], float, double, float, float, float, float, float,
    float, float, float, float, float, float, float);

int main (int argc, const char * argv[]) {

    //DECLARATIONS
  
    pair data[23];
    float R=0, ustar=0, Dsg=0, sigmasg=0, po[37], oo[37], so[37], tausg=0;
    float Dx30s=0, Dx50s=0, Dx70s=0, Dx90s=0, Dx30l=0, Dx50l=0, Dx70l=0, Dx90l=0;
    float Dlg=0, sigmalg=0, swap=0;
    double qbtot=0;
    int npp=0, np=0, nppo=0;
    float pfl[23], qb[23];
        
        Initialize(data, &R, &ustar, &npp, &Dsg, &Dlg, &sigmasg, &sigmalg, &np,
            &nppo, qb, &swap, pfl, po, oo, so);
            
        Run(data, pfl, npp, np, &tausg, R, &Dsg, ustar, po, so, oo, &sigmasg, &qbtot,
            qb, &Dx30s, &Dx50s, &Dx70s, &Dx90s, &Dx30l, &Dx50l, &Dx70l, &Dx90l, &Dlg,
            swap, &sigmalg);
        
        Finalize(data, npp, pfl, tausg, qbtot, Dsg, Dlg, sigmasg, sigmalg, Dx30s,
            Dx50s, Dx70s, Dx90s, Dx30l, Dx50l, Dx70l, Dx90l);
            
    return 0;
}
