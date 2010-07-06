#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double [], double [], double [], double [], double *, double *, double *, double *,
    double *, double *, double *, double *, int *, double *, int *, int *, double *,
    double *, double *, double *, double *, double *);
int SaveDatatoMatrix(double [][101], double [][101], double [][101], double [][101],
    double [][101], double [], double [], double [], double [], double [], double, int, int);
int Run(double [], double [], double [], double [], double [], double [], double, double,
    double *, double *, double, double, double, double, double, double, double, double,
    double, double, int);
int Finalize(double [][101], double [][101], double [][101], double [][101], double [][101], int, int);


int main (int argc, const char * argv[]) {
    
    //Declarations
    int M=0, prints=0, iterates=0, check=0, k=0, m=0;
    double qw=0, I=0, qtf=0, D=0, Cz=0, Sbase=0, Sfinit=0, sd=0, dt=0, dxbar=0;
    double time=0, alphas=0, etaup=0, sba=0, R=0, lamdap=0;
    double xbar[101], x[101], eta[101], S[101], qb[101], H[101];

    check = Initialize(xbar, x, eta, S, &qw, &I, &qtf, &D, &Cz, &Sbase, &Sfinit, &sd, &M, &dt,
                &prints, &iterates, &dxbar, &alphas, &etaup, &sba, &R, &lamdap);
    if (check == 1) {
        return 1;
    }
    
    //More Declarations
    double printmatrix[prints+2][101], Slmatrix[prints+2][101], qbmatrix[prints+2][101];
    double Hmatrix[prints+2][101], xmatrix[prints+2][101];
    
    SaveDatatoMatrix(printmatrix, Slmatrix, qbmatrix, Hmatrix, xmatrix, x, eta,
        S, qb, H, time, M, k);
        
    for (k=1; k <= prints; k++) {
        for (m=1; m <= iterates; m++) {
            Run(eta, S, qb, H, xbar, x, dxbar, sd, &etaup, &sba, Cz, I, lamdap,
                Sbase, dt, alphas, qw, R, D, qtf, M);
            time += dt;
        }
        SaveDatatoMatrix(printmatrix, Slmatrix, qbmatrix, Hmatrix, xmatrix, x, eta,
            S, qb, H, time, M, k);
    }
    
    Finalize(printmatrix, xmatrix, Slmatrix, qbmatrix, Hmatrix, M, prints);
                
    return 0;
}
