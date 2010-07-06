#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double [], double [], double [], double [], double [], double [],
    double [], double [], double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, int *);
int Run(double [][22], double [], double, double, double, int);
int Finalize(double [][22], double [], double [], double [], double [], double [], double [], double [], double [], int);

int main (int argc, const char * argv[]) {
    
    int check=0, prints=0, k=0;
    double xhat[22], x[22], Qtbf[22], Sl[22], etahat[22], etadev[22], Bbf[22], Hbf[22];
    double Gt=0, L=0, ksidot=0, Qbf=0, B=0, D=0, Lamda=0, tauform=0;
    double aleh=0, lamdap=0, Cz=0, I=0, Cf=0, Omega=0, R=0, ksid=0, dt=0, Qt=0, C=0;
    double BMSS=0, Su=0, beta=0, time=0;
    
    check = Initialize(Qtbf, Sl, etahat, etadev, Bbf, Hbf, xhat, x, &Gt, &L,
                &ksidot, &Qbf, &B, &D, &Lamda, &tauform, &aleh, &lamdap, &Cz, &I,
                &Cf, &Omega, &R, &ksid, &dt, &Qt, &C, &BMSS, &Su, &beta, &prints);
    if (check == 1)
        return 1;
        
    double printmatrix[prints+2][22];
    
    for (k=0; k <= prints; k++) {
        Run(printmatrix, etadev, ksid, ksidot, time, k);
        time += dt;
    }
    
    Finalize(printmatrix, xhat, x, Qtbf, Sl, etahat, etadev, Bbf, Hbf, prints);
    
    return 0;
}
