#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double [], double [], double [], double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, int *);
int Run(double [], double [], double [], double [], double [], double, double,
    double, double, double, double, double, int, double *);
int Finalize(double [], double [], double [], double [], double [], int, double);

int main (int argc, const char * argv[]) {

    //Declarations
    double x[101], eta[101], ksi[101], H[101], Sf[101], Hs[101];
    double Sl=0, R=0, D50s=0, D90s=0, B=0, Qw=0, ksid=0, L=0, qw=0, dx=0, Hnorm=0;
    int M=0, check=0;
    
    check = Initialize(x, eta, ksi, &Sl, &R, &D50s, &D90s, &B, &Qw, &ksid, &L, &qw, &dx, &M);
    if (check == 1)
        return 1;
        
    check = Run(eta, H, Sf, ksi, Hs, ksid, qw, dx, R, D90s, D50s, Sl, M, &Hnorm);
    if (check == 1)
        return 1;
        
    Finalize(x, eta, ksi, H, Hs, M, Hnorm);
         
    return 0;
}
