#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double *, double *, double *, double *, double *, double *, double *,
        double [], double [], double [], double [], double [], double [], double [],
        double [], double *, double *, double *, double *, double *, double *, double *,
        double *, double *, double *, int *, double [], double [], double *, double *,
        double *);
int Run(double [], double [], double [], double [], double [], double [], double [],
        double *, double *, double *, double *, double *, double *, int *, double [],
        int *);
int Finalize(double [], double [], double [], double [], double [], double [], double,
        double, double, double, double, double, int);

int main (int argc, const char * argv[]) {
    //Declarations
    double R=0, D=0, H=0, kc=0, ustar=0, nu=0, Cr=0, una=0, cna=0, qs=0, dzeta=0;
    double ustarr=0, Ristar=0, Rep=0, vs=0, Hr=0, unr=0, unao=0, cnao=0, qso=0;
    double zeta[52], Ri[52], Fstrat[52], un[52], cn[52], intc[52], unold[52], cnold[52];
    double initun[52], initcn[52];
    int n=0, bombed=0;
    
    Initialize(&R, &D, &H, &kc, &ustar, &nu, &Cr, zeta, Ri, Fstrat, un,
        cn, intc, unold, cnold, &una, &cna, &qs, &dzeta, &ustarr, &Ristar, &Rep,
        &vs, &Hr, &unr, &n, initun, initcn, &unao, &cnao, &qso);
    Run(Ri, zeta, Fstrat, un, cn, unold, cnold, &una, &cna, &qs, &dzeta, &ustarr,
        &Ristar, &n, intc, &bombed);
    Finalize(zeta, initun, initcn, un, cn, Ri, unao, cnao, qso, una, cna, qs, bombed);
    
    return 0;
}
