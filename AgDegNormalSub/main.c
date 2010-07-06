#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

//Prototypes
int Initialize(float *, float *, float *, float *, float *, float *, float *, float *,
        float *, int *, int *, int *, float *, float *, float *, float *, float *, float *,
        float *, float *, int *, float *, float *, float *, float *, float *, float *,
        double [], double [], float *, double [], double [], double [], double []);
int Run(double [], int, double [], float, double [], double [], float, float, float, float, float,
        float, int, double [], float, float, float, float, float, float, float, float, float, float,
        float, float, float);
int SaveDatatoMatrix(double [][101], double [][101], double [][101], double [][101],
        double [][101], double [], double [], double [], double [], double [],
        float, int, int);
int Finalize(double [][101], double [][101], double [][101], double [][101], double [][101],
        double [], int, int, float);

int main (int argc, const char * argv[]) {
    
    //DECLARATIONS
    
    float qw=0, If=0, D=0, lamdap=0, kc=0, S=0, qtf=0, L=0, dt=0, alphau=0, alphar=0, qtg=0, time=0;
    float alphat=0, nt=0, tauc=0, phis=0, R=0, Cf=0, sigma=0, rB=0, omega=0, lamda=0, dx=0, Lmax=0;
    int iterate=0, prints=0, M=0, formulation=0, check=0, k=0, j=0;
    double eta[101], x[101], qb[101], Sl[101], tau[101], H[101];
    
        check= Initialize(&qw, &If, &D, &lamdap, &kc, &S, &qtf, &L, &dt, &iterate, &prints, &M,
                &alphau, &alphar, &alphat, &nt, &tauc, &phis, &R, &Cf, &formulation, &sigma, &rB,
                &omega, &lamda, &dx, &Lmax, eta, x, &qtg, Sl, tau, H, qb);
        if (check == 1) 
            return 1;
        
        //Declare variables dependent on prints
                
        double printmatrix[prints+2][101], Slmatrix[prints+2][101], Hmatrix[prints+2][101];
        double taumatrix[prints+2][101], qbmatrix[prints+2][101];
        
        //Save initial data
        
        SaveDatatoMatrix(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix, eta,
            Sl, H, tau, qb, time, k, M);
        
        //Time Loop
        
        for (k=1; k <= prints; k++) {
            for (j=1; j <= iterate; j++) {
                time += dt;
                Run(Sl, M, eta, dx, tau, H, qw, kc, alphar, D, R, Cf, formulation, qb,
                    phis, tauc, nt, alphat, dt, lamdap, If, alphau, qtg, sigma, rB, omega,
                    lamda);
            }
            SaveDatatoMatrix(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix, eta,
                Sl, H, tau, qb, time, k, M);
        }
    
    Finalize(printmatrix, Slmatrix, qbmatrix, Hmatrix, taumatrix, x, M, prints, qtf);
    
    return 0;
}