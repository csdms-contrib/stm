#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double [], double [], double [], double [], double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, int *, int *, int *, int *);
int SaveDatatoMatrix(double [][202], double [][203], double [][202], double [][202],
    double [][202], double [][202], double [], double [], double [], double [],
    double [], double [], double [], double [], double, double, double, int, int, int);
int Run(double [][203], double [][202], double [][202], double [][202], double [],
    double [], double [], double [], double [], double [], double [],
    double [], double [], double [], double [], double [], double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double, double, double,
    double, double, double, double, double, double, double, double, double, double,
    double, double, double, double, double, double, double, double, double, double,
    int, int);
int Finalize(double [][202], double [][202], double [][202], double [][203],
    double [][202], double [][202], double [], double [], double [], int, int, int);

int main (int argc, const char * argv[]) {

    //Declarations
    int check=0, prints=0, iterates=0, Ms=0, Mg=0, k=0, m=0;
    double xbarg[101], xbars[101], x[202], eta[202], Sl[203], H[202], qb[202], tau[202];
    double Sgrav[101], Ssand[202], qgrav[101], qsand[202];
    double sgs=0, Qbf=0, L=0, sgsl=0, ksid=0, ksidot=0, subrate=0, Yearstart=0, Yearstop=0;
    double dt=0, qfeeds=0, qfeedg=0, Ifs=0, Ifg=0, Ds=0, Dg=0, Czs=0, Czg=0, Bs=0, Bg=0;
    double Ssl=0, Sgl=0, Bds=0, Bdg=0, Omegas=0, Omegag=0, lamdams=0, lamdasg=0, Cfs=0;
    double Cfg=0, sfsl=0, dxbars=0, dxbarg=0, qwg=0, qws=0, qfg=0, qfs=0, rBg=0, rBs=0;
    double Ifgeff=0, Ifseff=0, R=0, lamps=0, lampg=0, Sbgb=0, Ssgs=0, Sggs=0, Ssd=0, time=0;
    double sgsdot=0, qgravghost=0, qsandghost=0;
    
    check = Initialize(xbarg, x, eta, xbars, &sgs, &Qbf, &L, &sgsl, &ksid, &ksidot,
                &subrate, &Yearstart, &Yearstop, &dt, &qfeeds, &qfeedg, &Ifs, &Ifg,
                &Ds, &Dg, &Czs, &Czg, &Bs, &Bg, &Ssl, &Sgl, &Bds, &Bdg, &Omegas,
                &Omegag, &lamdams, &lamdasg, &Cfs, &Cfg, &sfsl, &dxbars, &dxbarg,
                &qwg, &qws, &qfg, &qfs, &rBg, &rBs, &Ifgeff, &Ifseff, &R, &lamps,
                &lampg, &prints, &iterates, &Ms, &Mg);
    if (check == 1)
        return 1;
        
    //More Declarations
    double printmatrix[prints+2][202], Slmatrix[prints+2][203], qbmatrix[prints+2][202];
    double Hmatrix[prints+2][202], xmatrix[prints+2][202], taumatrix[prints+2][202];
    double sgsvector[prints+2], Lvector[prints+2];
    
    SaveDatatoMatrix(printmatrix, Slmatrix, Hmatrix, qbmatrix, taumatrix, xmatrix,
        eta, Sl, H, qb, tau, x, sgsvector, Lvector, time, sgs, L, Ms, Mg, k);
    
    for (k=1; k <= prints; k++) {
        for (m=1; m <= iterates; m++) {
            Run(Slmatrix, Hmatrix, qbmatrix, taumatrix, H, eta, x, Sgrav, Ssand, Sl,
                qb, qgrav, qsand, tau, xbarg, xbars, &Sbgb, &Sggs, &Ssgs, &Ssd, &qgravghost,
                &qsandghost, &sgsdot, &sgs, &ksid, Cfs, Cfg, qws, qwg, R, Dg, Ds, qfs,
                qfg, lamdasg, Ifseff, Ifgeff, L, dxbarg, dxbars, lamps, lampg, Yearstart,
                Yearstop, subrate, dt, ksidot, time, Ms, Mg);
            time += dt;
        }
        SaveDatatoMatrix(printmatrix, Slmatrix, Hmatrix, qbmatrix, taumatrix, xmatrix,
            eta, Sl, H, qb, tau, x, sgsvector, Lvector, time, sgs, L, Ms, Mg, k);
    }
    
    Finalize(printmatrix, xmatrix, Hmatrix, Slmatrix, qbmatrix, taumatrix, sgsvector,
        Lvector, H, Ms, Mg, prints);
    
    return 0;
}
