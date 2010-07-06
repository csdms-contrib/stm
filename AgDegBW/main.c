#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

//prototypes for use in main function

int Initialize(float *, float *, float *, float *, float *, float *, float *, float *,
        float *, float *, int *, int *, int *, float *, float *, float *, float *,
        float *, float *, float *, float *, int *, float *, float *, float *, float *,
        float *, float *, float *, float *, float *, float *, float *, float *, double *,
        double *, double *, double *, double *, double [], double [], double [], float *,
        double []);
int SaveDatatoMatrix(double [][101], double [][101], double [][101], double [][101],
        double [][101], double [][101], double [],  double [],  double [], 
        double [],  double [],  double [], float, int, int);
int Run(double [], int, double [], float, double [], double [], float, float, double [],
        float, float, float, float, float, float, float, float, int, float, float,
        float, float, float, double [], float);
int Finalize(double [][101], double [][101], double [][101], double [], int, int, float,
        float, float, float, float, float, float, float, float, double, double, double,
        double, double, double [][101], double [][101], double [][101]);


int main (int argc, const char * argv[]) {
    //DECLARATIONS
    float Qf=0, If=0, B=0, D=0, lamdap=0, kc=0, S=0, Gtf=0, dt=0, alphau=0, alphar=0;
    float alphat=0, nt=0, tauc=0, phis=0, R=0, Cf=0, ksio=0, dx=0, qw=0, L=0, qtg=0;
    float Ha=0, taustar=0, qstar=0, qt=0, Gt=0, qtf=0, tauult=0, Sult=0, Hult=0, time=0;
    double Frni=0, Frnu=0, Hc=0, ksimin=0, ksiinit=0;
    int iterate=0, prints=0, M=0, formulation=0, j=0, k=0, check=0;
    double eta[101], x[101], ksi[101], H[101];
    
        check = Initialize(&Qf, &If, &B, &D, &lamdap, &kc, &S, &Gtf, &L, &dt, &iterate,
                &prints, &M, &alphau, &alphar, &alphat, &nt, &tauc, &phis, &R, &Cf,
                &formulation, &ksio, &dx, &qw, &Ha, &taustar, &qstar, &qt, &Gt, &qtg,
                &tauult, &Sult, &Hult, &Frni, &Frnu, &Hc, &ksimin, &ksiinit, eta, x,
                ksi, &qtf, H);
        if (check == 1)
            return 1;
        
        //Declare variables that depend upon M and prints
        double qb[M+2], tau[M+2], Sl[M+2];
        double printmatrix[prints+2][101], Slmatrix[prints+2][101], Hmatrix[prints+2][101];
        double taumatrix[prints+2][101], qbmatrix[prints+2][101], ksimatrix[prints+2][101];
    
        //Save Initial Bed Profile
        SaveDatatoMatrix(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix, ksimatrix,
            eta, Sl, H, tau, qb, ksi, time, j, M);
        
        //Time Loop
        for (j=1; j <= prints; j++) {
            for (k=1; k <= iterate; k++) {
                Run(Sl, M, eta, dx, tau, qb, Cf, alphar, H, kc, qw, R, D, tauc, nt,
                    phis, alphat, formulation, dt, lamdap, If, alphau, qtg, ksi, ksio);
            }
            time = (j)*dt/(3600*24*365.25)*iterate;
            SaveDatatoMatrix(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix, ksimatrix,
                eta, Sl, H, tau, qb, ksi, time, j, M);
        }
        
        Finalize(printmatrix, Hmatrix, ksimatrix, x, M, prints, Ha, taustar, qstar, qt,
            Gt, qtf, tauult, Sult, Hult, Frni, Frnu, Hc, ksimin, ksiinit, Slmatrix,
            taumatrix, qbmatrix);

    return 0;
}
