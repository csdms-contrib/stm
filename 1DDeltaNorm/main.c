#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double [], double [], double [], double [], double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    int *, int *, int *, int *);
int SaveDatatoMatrix(double [][102], double [][102], double [][102], double [][102],
    double [][102], double [][102], double [], double [], double [], double [],
    double [], double [], double [], double [], double [], double, double, double,
    double, int, int);
int Run(double [], double [], double [], double [], double [], double [], double [],
    double, double, double, double *, double *, double *, double *, double *, double,
    double, double, double, double, double, double, double, double, double, double,
    double, double, double, double, int, int);
int Finalize(double [][102], double [][102], double [][102], double [][102], double [][102],
    double [][102], double [], double [], double [], double [], double [], double, double,
    double, double, double, double, int, int, int);

int main (int argc, const char * argv[]) {

    //Declarations
    int check=0, M=0, prints=0, iterates=0, formulation=0, k=0, m=0;
    double xfbar[102], x[102], eta[102], Sl[102], qb[102], H[102], tau[102];
    double qw=0, I=0, qtf=0, D=0, Cz=0, nt=0, tsc=0, etasl=0, etabl=0, Sfi=0, Sb=0;
    double ssfi=0, Sa=0, R=0, lamdap=0, ks=0, alphar=0, alphat=0, dt=0, time=0;
    double dxbar=0, su=0, sss=0, sbb=0, etatop=0, etabot=0, abase=0, Volinit=0;
    double etaup=0;
    
    check = Initialize(xfbar, x, eta, Sl, &qw, &I, &qtf, &D, &Cz, &nt, &tsc, &etasl,
                &etabl, &Sfi, &Sb, &ssfi, &Sa, &R, &lamdap, &ks, &alphat, &alphar,
                &dt, &dxbar, &su, &sss, &sbb, &etaup, &etatop, &etabot, &abase,
                &Volinit, &M, &prints, &iterates, &formulation);
    if (check == 1) 
        return 1;
        
    //More Declarations
    double printmatrix[prints+3][102], Slmatrix[prints+3][102], qbmatrix[prints+3][102];
    double Hmatrix[prints+3][102], taumatrix[prints+3][102], xmatrix[prints+3][102];
    double suvector[prints+3], sssvector[prints+3], sbbvector[prints+3];
    
    SaveDatatoMatrix(printmatrix, Slmatrix, qbmatrix, Hmatrix, taumatrix, xmatrix, eta, Sl,
        qb, H, tau, x, suvector, sssvector, sbbvector, time, su, sss, sbb, k, M);
        
    for (k=1; k <= prints; k++) {
        for (m=1; m <= iterates; m++) {
            Run(Sl, eta, H, tau, qb, xfbar, x, etasl, I, lamdap, &sbb, &sss, &etaup,
                &etatop, &etabot, Sa, Sb, dxbar, qw, Cz, ks, alphar, alphat, tsc, nt,
                R, D, dt, qtf, su, formulation, M);
            time += dt;
        }
        SaveDatatoMatrix(printmatrix, Slmatrix, qbmatrix, Hmatrix, taumatrix, xmatrix, eta,
            Sl, qb, H, tau, x, suvector, sssvector, sbbvector, time, su, sss, sbb, k, M);
    }
    
    Finalize(printmatrix, xmatrix, Slmatrix, qbmatrix, Hmatrix, taumatrix, suvector,
        sssvector, sbbvector, x, eta, Volinit, qtf, lamdap, dt, Sb, abase, iterates, prints, M);
     
    return 0;
}
