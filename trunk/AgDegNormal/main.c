#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

//Prototypes

int Initialize(float *, float *, float *, float *, float *, float *, float *, float *,
        float *, float *, int *, int *, int *, float *, float *, float *, float *,
        float *, float *, float *, float *, int *, float *, float *, float *, float *,
        float *, float *, float *, float *, float *, float *, float *, double [], double []);
int Run(double [], int, double [], float, double [], double [], float, float, float, float,
        float, float, float, int, double [], float, float, float, float, float, float,
        float, float, float);
int SaveDatatoMatrix(double [][101], double [][101], double [][101], double [][101],
        double [][101], double [], double [], double [], double [], double [], float, int, int);
int Finalize(double [][101], double [], int, int, float, float, float, float, float, float,
        float, float, float, float, float, double [][101], double [][101], double[][101],
        double[][101]);

int main (int argc, const char * argv[]) {
    //INITIALIZE
    
    float Qf=0, If=0, B=0, D=0, lamdap=0, kc=0, S=0, Gtf=0, L=0, dt=0, time=0;
    float alphau=0, alphar=0, alphat=0, nt=0, tauc=0, phis=0, R=0, qtg=0, Cf=0;
    float H=0, taustar=0, qstar=0, qt=0, Gt=0, qtf=0, tauult=0, Sult=0, Hult=0, dx=0;
    int M=0, iterate=0, prints=0, formulation=0, j=0, k=0;
    double eta[101], x[101];
        
        Initialize(&Qf, &If, &B, &D, &lamdap, &kc, &S, &Gtf, &L, &dt, &iterate, &prints,
            &M, &alphau, &alphar, &alphat, &nt, &tauc, &phis, &R, &Cf, &formulation, &H,
            &taustar, &qstar, &qt, &Gt, &qtf, &tauult, &Sult, &Hult, &qtg, &dx, eta, x);
        
        //Declares Variables Dependent on Initialize Values
        double qb[M+2], Sl[M+2], tau[M+2], Ht[M+2];
        double printmatrix[prints+2][101], Slmatrix[prints+2][101], Hmatrix[prints+2][101];
        double taumatrix[prints+2][101], qbmatrix[prints+2][101];
        
        //Saves initial bed data
        
        SaveDatatoMatrix(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix,
            eta, Sl, Ht, tau, qb, time, k, M);
        
        //TIME LOOP
        
        for (k=1; k <= prints; k++) {
            for (j=1; j <= iterate; j++) {
                Run(Sl, M, eta, dx, tau, Ht, Qf, kc, alphar, B, D, R, Cf, formulation,
                    qb, phis, tauc, nt, alphat, dt, lamdap, If, alphau, qtg);
            }
            time = k*dt*iterate;
            SaveDatatoMatrix(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix,
                eta, Sl, Ht, tau, qb, time, k, M);
        }
        
        Finalize(printmatrix, x, M, prints, L, dx, Sult, H, taustar, qstar, qt, Gt,
            qtf, tauult, Hult, Slmatrix, Hmatrix, taumatrix, qbmatrix);
    
    return 0;
}
