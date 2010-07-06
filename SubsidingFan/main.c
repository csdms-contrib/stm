#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double [], double [], double [], double [], double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, int *, int *, int *);
int Run(double [], double [], double [], double [], double, double, double, double,
    double, double, double, double, double, double, double, int);
int SaveDatatoMatrix(double [][101], double [][101], double [][101], double [],
    double [], double [], double, int, int);
int Finalize(double [][101], double [][101], double [][101], double [], int, int);

int main (int argc, const char * argv[]) {

    //Declarations
    int check=0, M=0, prints=0, iterates=0, k=0, m=0;
    double x[101], eta[101], Sl[101], qb[101];
    double Qtfeed=0, Lb=0, Qbf=0, D=0, Lamda=0, theta=0, lamdap=0, I=0, Cz=0, Sinu=0;
    double sigma=0, aleh=0, neh=0, tauforms=0, alp=0, np=0, tausc=0, tauformg=0, Cf=0;
    double dx=0, Su=0, R=0, dt=0, loadcoef=0, time=0;
    
    check = Initialize(x, eta, qb, Sl, &Qtfeed, &Lb, &Qbf, &D, &Lamda, &theta,
        &lamdap, &I, &Cz, &Sinu, &sigma, &aleh, &neh, &tauforms, &alp, &np, &tausc,
        &tauformg, &Cf, &dx, &Su, &R, &dt, &loadcoef, &M, &prints, &iterates);
    if (check == 1)
        return 1;
        
    //More Declarations
    double printmatrix[prints+2][101], Slmatrix[prints+2][101], qbmatrix[prints+2][101];
    
    SaveDatatoMatrix(printmatrix, Slmatrix, qbmatrix, eta, Sl, qb, time, k, M);
        
    for (k=1; k <= prints; k++) {
        for (m=1; m <= iterates; m++) {
            Run(Sl, qb, eta, x, dx, loadcoef, Qbf, theta, sigma, dt, I, Lamda,
                Sinu, lamdap, Su, M);
            time += dt;
        }
        SaveDatatoMatrix(printmatrix, Slmatrix, qbmatrix, eta, Sl, qb, time, k, M);
    }
    
    Finalize(printmatrix, Slmatrix, qbmatrix, x, prints, M);
    
    return 0;
}