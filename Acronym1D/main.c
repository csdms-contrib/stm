#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

//defines the pair structure

typedef struct  {
    float D;
    float pfs;
} pair;

typedef struct {
    float Qwd;
    float pQf;
} pair2;

//prototypes of functions
int Initialize(pair [], pair2 [], float [], float [], float *, int *, int *, int *,
        float *, float *, float *, float *, float *, float *, float *, float *, int *,
        int *, float [], float *, float [], float *, float *, float *, float *, float *,
        float *, float *, float [], float [], float []);
int Run(pair [], pair2 [], int, float *, float *, float *, float *, float, float *,
        float, float, float *, float *, int, int, float *, float, float *, float [],
        float [], float [], float *, double *, float [], float [], float *, float *,
        float [], float [], int, float [], float [], float [], float [], float [], float [],
        float [][16], float, float *, float *, float *, float *, float *, float *, float *,
        float *, float *);
int Finalize(pair [], float [], float, float, float, float, float, float, float, float,
        float, int, float, float, float, float, float, float, float, float, int, float [],
        float [], float [], float [], float [], float []);


int main (int argc, const char * argv[]) {

    //INITIALIZE
  
    pair data[23];
    pair2 flowdata[16];
    float R=0, ustar=0, Dsg=0, sigmasg=0, tausg=0;
    float Dx30s=0, Dx50s=0, Dx70s=0, Dx90s=0, Dx30l=0, Dx50l=0, Dx70l=0, Dx90l=0;
    float Dlg=0, sigmalg=0, swap=0, H=0, Qf=0, B=0, S=0, nk=0;
    float po[37], oo[37], so[37], Qwr[15], pQ[15];
    float Qwa=0, qTa=0, Ha=0, ustara=0, tausga=0;
    double qbtot=0;
    int npp=0, np=0, nppo=0, ndd=0, nd=0, check=0;
    float pfl[23], qb[23], Hd[16], ustard[16], tausgd[16], qTd[16], pla[23], pfla[23], pfld[23][16];

        check = Initialize(data, flowdata, Qwr, pQ, &R, &npp, &ndd, &nd, &Dsg, &Dlg, &sigmasg, &sigmalg,
                &S, &B, &nk, &Dx90s, &np, &nppo, qb, &swap, pfl, &Dx30s, &Dx50s, &Dx70s, &Dx30l,
                &Dx50l, &Dx70l, &Dx90l, po, so, oo);
        if (check == 1)
            return 1;
            
        check = Run(data, flowdata, ndd, &Qf, &Qwa, &H, &ustar, nk, &Dx90s, B, S, &Ha, &ustara,
                npp, np, &tausg, R, &Dsg, po, so, oo, &sigmasg, &qbtot, pfl, qb, &tausga, &qTa,
                pla, pfla, nd, Qwr, Hd, ustard, tausgd, qTd, pQ, pfld, swap, &Dx30s, &Dx50s, &Dx70s,
                &Dx30l, &Dx50l, &Dx70l, &Dx90l, &Dlg, &sigmalg);
        if (check == 1)
            return 1;
                
        Finalize(data, pfla, qTa, tausga, Qwa, Ha, ustara, Dsg, Dlg, sigmasg, sigmalg,
            npp, Dx90s, Dx70s, Dx50s, Dx30s, Dx90l, Dx70l, Dx50l, Dx30l, nd, Qwr, pQ,
            qTd, Hd, ustard, tausgd);
        
            
    //FINALIZE
    return 0;
}