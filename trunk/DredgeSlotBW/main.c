#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double [], double [], double [], double [], double [], double [],
    double [], double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, int *, int *, int *);
int Run(double [], double [], double [], double [], double [], double [], double [],
    double [], double [], double *, double *, double *, double *, double *, double *,
    double *, double, double, double, double, double, double, double, double, double,
    double, double, double, double, double, double, double, int);
int SaveDatatoMatrix(double [][2002], double [][2002], double [][2002], double [][2002],
    double [][2002], double [][2002], double [], double [], double [], double [],
    double [], double [], double, int, int);
int Finalize(double [][2002], double [][2002], double [][2002], double [][2002],
    double [][2002], double [][2002], double [], double, double, double, double,
    double, double, int, int);

int main (int argc, const char * argv[]) {
    
    //Declarations
    int check=0, M=0, prints=0, iterates=0, k=0, m=0;
    double zeta[52], x[2002], eta[2002], ksi[2002], H[2002], Sf[2002], Hs[2002];
    double qb[2002], qs[2002], Ent[2002];
    double Qww=0, I=0, B=0, D50=0, D90=0, R=0, S=0, lamdap=0, L=0, Hslot=0, ru=0, rd=0;
    double au=0, dt=0, qw=0, dx=0, Rep=0, vs=0, dzeta=0, Hnorm=0, Hsnorm=0, Gbnorm=0;
    double Gsnorm=0, ustarr=0, Hr=0, qsint=0, ksid=0, qbf=0, qsf=0, Cnorm=0, MassIn=0;
    double MassStored=0, MassOut=0, FracDisc=0, time=0;
    
    check = Initialize(zeta, x, eta, ksi, H, Sf, Hs, &Qww, &I, &B, &D50, &D90, &R,
                &S, &lamdap, &L, &Hslot, &ru, &rd, &au, &dt, &qw, &dx, &Rep, &vs, &dzeta,
                &Hnorm, &Hsnorm, &Gbnorm, &Gsnorm, &ustarr, &Hr, &qsint, &ksid, &qbf,
                &qsf, &Cnorm, &MassIn, &MassStored, &MassOut, &FracDisc, &M, &iterates,
                &prints);
    if (check == 1) 
        return 1;
        
    //More Declarations
    double printmatrix[prints+2][2002], Hmatrix[prints+2][2002], ksimatrix[prints+2][2002];
    double qsmatrix[prints+2][2002], qbmatrix[prints+2][2002], Hsmatrix[prints+2][2002];
    
    SaveDatatoMatrix(printmatrix, Hmatrix, ksimatrix, qbmatrix, qsmatrix,
        Hsmatrix, eta, H, ksi, qb, qs, Hs, time, k, M);
        
    for (k=1; k <= prints; k++) {
        for (m=1; m <= iterates; m++) {
            check = Run(qb, Hs, Sf, qs, H, Ent, zeta, eta, ksi, &ustarr, &Hr, &qsint,
                        &MassIn, &MassOut, &MassStored, &FracDisc, D50, R, vs, Rep,
                        qw, dzeta, qbf, qsf, au, dt, I, lamdap, dx, B, ksid, D90, M);
            if (check == 1) 
                return 1;
            time += dt;
        }
        SaveDatatoMatrix(printmatrix, Hmatrix, ksimatrix, qbmatrix, qsmatrix,
            Hsmatrix, eta, H, ksi, qb, qs, Hs, time, k, M);
    }
    
    Finalize(printmatrix, Hmatrix, Hsmatrix, qbmatrix, qsmatrix, ksimatrix, x, Hnorm,
        Hsnorm, Gbnorm, Gsnorm, Cnorm, ksid, M, prints);
    
    return 0;
}
