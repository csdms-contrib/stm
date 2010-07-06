#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double *, double *, double *, double *, double *, double *, double *,
    int *, double *, double *, double *);
int Run(int, double [], double [], double [], double [], double [], double [], double [],
    double [], double [], double [], double [], double, double, double, double, double,
    double, double, double, double, double [], double [], double [], double [], double [],
    double [], double [], double [], double [], double []);
int Finalize(int, double [], double [], double [], double [], double [], double [],
    double [], double [], double [], double [], double [], double [], double [],
    double [], double [], double [], double [], double [], double [], double [], double []);

int main (int argc, const char * argv[]) {

    //Declarations
    int N=0, check = 0;
    double Sl=0, R=0, D50s=0, D90s=0, nk=0, Hso=0, Hstep=0, astrat=1, nu=0, ks=0;

    check = Initialize(&Sl, &R, &D50s, &D90s, &nk, &Hso, &Hstep, &N, &astrat, &nu, &ks);
    if (check == 1)
        return 1;

    //More Declarations
    double Hs[N+1], tausg[N+1], U[N+1], Gamma[N+1], H[N+1], qw[N+1], tau[N+1], Fr[N+1];
    double ratio[N+1], u[N+1], us[N+1], qb[N+1], Cz[N+1], kc[N+1], Zu[N+1], E[N+1];
    double I[N+1], qs[N+1], qt[N+1], qbqt[N+1], vsku[N+1];

    Run(N, Hs, U, Gamma, H, tausg, qw, ratio, Fr, u, us, qb, Hso, Hstep, Sl, R, D50s,
        D90s, astrat, nk, nu, tau, Cz, kc, Zu, E, I, qs, qt, qbqt, vsku);
    Finalize(N, Hs, tausg, U, Gamma, H, qw, tau, ratio, Fr, u, us, qb, Cz, kc, Zu, E,
        I, qs, qt, qbqt, vsku);

    return 0;
}
