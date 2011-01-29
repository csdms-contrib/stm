#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double [], double [], double [], double [], double [], double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, int *, int *, int *, int *);
int SaveDatatoMatrix(double [][102], double [][102], double [][102], double [][102],
    double [][102], double [][102], double [], double [], double [], double [],
    double [], double [], double [], double [], double, double, double, double, double,
    int, int);
int Run(double [], double [], double [], double [], double [], double [], double [],
    double [], double, double, double, double, double, double, double, double, double,
    double, double, double, double, double, double, double, double, double, double,
    double, double *, double *, double *, double *, double *, double *, double *,
    int *, int, int);
int Finalize(double [][102], double [][102], double [][102], double [][102], double [][102],
    double [][102], double [], double [], double [], double [], double, double, double,
    double, double, double, double, double, double, int, int, int);

int main (int argc, const char * argv[]) {
    
    //Declarations
    int check=0, M=0, prints=0, iterates=0, formulation=0, bombed=0, k=0, m=0;
    double xfbar[102], xfluv[102], etafluv[102], x[102], eta[102], Sl[102], qb[102];
    double H[102], tau[102];
    double qw=0, I=0, qtf=0, D=0, Cz=0, nt=0, tsc=0, etasl=0, etabl=0, Sfi=0, Sb=0;
    double Sa=0, ssfi=0, R=0, lamdap=0, ks=0, alphat=0, alphar=0, dt=0, dxbar=0;
    double Cf=0, sfmax=0, ksid=0, Volinit=0, abase=0, etasdot=0, etatop=0, etabot=0;
    double sss=0, sbb=0, tsn=0, Sn=0, Hn=0, Frn=0, time=0, ssdot=0, sbdot=0, Volfed=0;
    double Volfin=0, ervol=0;
    
    check = Initialize(xfbar, xfluv, etafluv, x, eta, &qw, &I, &qtf, &D, &Cz, &nt,
                &tsc, &etasl, &etabl, &Sfi, &Sb, &Sa, &ssfi, &R, &lamdap, &ks,
                &alphat, &alphar, &dt, &dxbar, &Cf, &sfmax, &ksid, &Volinit, &abase,
                &etasdot, &etabot, &etatop, &sss, &sbb, &tsn, &Sn, &Hn, &Frn, &M, &prints,
                &iterates, &formulation);
    if (check == 1)
        return 1;
        
    //More Declarations
    double printmatrix[prints+3][102], Slmatrix[prints+3][102], qbmatrix[prints+3][102];
    double taumatrix[prints+3][102], Hmatrix[prints+3][102], xmatrix[prints+3][102];
    double sssvector[102], sbbvector[102];
    
    SaveDatatoMatrix(printmatrix, Slmatrix, qbmatrix, Hmatrix, taumatrix, xmatrix,
        eta, Sl, qb, H, tau, x, sssvector, sbbvector, time, sss, sbb, dxbar, ksid, k, M);
        
    for (k=1; k <= prints; k++) {
        for (m=1; m <= iterates; m++) {
            Run(H, etafluv, tau, qb, x, eta, xfluv, xfbar, Cz, dxbar, Hn, qw,
                R, D, tsc, alphat, nt, dt, qtf, I, Sa, Sb, lamdap, ksid, sfmax,
                time, ks, alphar, &etasdot, &etatop, &ssdot, &sbb, &sss, &sbdot,
                &etabot, &bombed, M, formulation);
                if (bombed == 1)
                    break;
            time += dt;
        }
        SaveDatatoMatrix(printmatrix, Slmatrix, qbmatrix, Hmatrix, taumatrix, xmatrix,
            eta, Sl, qb, H, tau, x, sssvector, sbbvector, time, sss, sbb, dxbar, ksid, k, M);
        if (bombed == 1)
            break;
    }
    
    Finalize(printmatrix, xmatrix, Slmatrix, qbmatrix, Hmatrix, taumatrix, sssvector,
        sbbvector, x, eta, Volinit, Volfin, Volfed, ervol, dt, qtf, lamdap, Sb,
        abase, prints, M, iterates);
    
    return 0;
}
