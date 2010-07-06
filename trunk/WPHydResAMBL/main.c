#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double *, double *, double *, double *, double *, double *, double *, int *, double *);
int Run(int, double [], double [], double [], double [], double [], double [], double [], double [],
    double [], double [], double [], double, double, double, double, double, double, double, double,
    double []);
int Finalize(int, double [], double [], double [], double [], double [], double [], double [],
    double [], double [], double [], double [], double []);

int main (int argc, const char * argv[]) {
    
    //Declarations
    int check=0, N=0;
    double Sl=0, R=0, D50s=0, D90s=0, nk=0, Hso=0, Hstep=0, astrat=1;
    
    check = Initialize(&Sl, &R, &D50s, &D90s, &nk, &Hso, &Hstep, &N, &astrat);
    if (check == 1)
        return 1;
    
    //Extra Declarations
    double Hs[N+1], tausg[N+1], U[N+1], Gamma[N+1], H[N+1], qw[N+1], tau[N+1], Fr[N+1];
    double ratio[N+1], u[N+1], us[N+1], qb[N+1];

    Run(N, Hs, U, Gamma, H, tausg, qw, ratio, Fr, u, us, qb, Hso, Hstep, Sl, R,
        D50s, D90s, astrat, nk, tau);
        
    Finalize(N, Hs, tausg, U, Gamma, H, qw, tau, ratio, Fr, u, us, qb);
    
   return 0;
}
