#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

//Prototypes
int Initialize(float *, float *, float *, float *, float *, float *, float *, float *,
        float *, float *, float *, int *, float *, float *, float *, float *, float *,
        float *, float *, float *, float *, float *, int *);
int Run(float, float, float, float, float, float, float, float, float, float, int [],
        float [], float [], float [], float [], float [], int [], float [], float [],
        float [], float [], float [], int);
int Finalize(float, float, float, float, float, float, float, float, float, float,
        int [], float [], float [], float [], float [], float [], int [], float [],
        float [], float [], float [], float [], int, int);

int main (int argc, const char * argv[]) {
    
    float chezyH=0, chezyU=0, chezyFr=0, chezytaub=0;
    float MSH=0, MSU=0, MSFr=0, MStaub=0;
    float S=0, Cz=0, qw=0, R=0, Dmean=0, Ds90=0, nk=0, alphar=0;
    float Hc=0, Uc=0;
    float x0=0, step=0, initdepth=0;
    int terms=0, formulation=0;
    
        Initialize(&S, &Cz, &qw, &R, &Dmean, &Ds90, &nk, &alphar, &x0, &step, &initdepth,
            &terms, &chezyH, &chezyFr, &chezyU, &chezytaub, &MSH, &MSU, &MSFr, &MStaub,
            &Hc, &Uc, &formulation);
        
        //Declare variables that depend on N, the number of segments
        int N=(x0/step)+1;
        float U[N], taub[N], eta[N], ksi[N], H[N], UMS[N], taubMS[N], etaMS[N], ksiMS[N], HMS[N];
        int x[N], xMS[N];
        
        Run(S, qw, Cz, initdepth, x0, step, N, nk, Ds90, alphar, x, U, taub, eta,
            ksi, H, xMS, UMS, taubMS, etaMS, ksiMS, HMS, formulation);
        Finalize(chezyH, chezyU, chezyFr, chezytaub, MSH, MSU, MSFr, MStaub, Hc, Uc, x,
            U, H, taub, eta, ksi, xMS, UMS, HMS, taubMS, etaMS, ksiMS, N, formulation);
        return 0;
}
