#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

//Prototypes

int Initialize(double *, double *, double *, double *, double *, double *, double *, double *, double *,
    double *, int *, int *, int *, double *, double *, double *, double *, double *, double *, double *,
    double *, int *, double *, double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double [], double [], double *, double *);
int SaveDatatoMatrix(double [][101], double [][101], double [][101], double [][101],
        double [][101], double [], double [], double [], double [], double [], double,
        int, int);
int Run(int *, double, double, double, int, double [], double, double, double [], double, double [],
    double [], double, double, double, double, double, double, double, int, double [], double, double,
    double, double, double, double, double, double, double);
int Finalize(double [][101], double [], int, int, double, double, double, double, double,
    double, double, double [][101], double [][101], double [][101], double [][101]);


int main (int argc, const char * argv[]) {

    //INITIALIZE
    
    double Qf=0, If=0, B=0, D=0, lamdap=0, kc=0, S=0, Gtf=0, L=0, dt=0, alphau=0, dx=0;
    double alphar=0, alphat=0, nt=0, tauc=0, phis=0, R=0, Cf=0, rf=0, deltaeta=0, tf=0;
    double H=0, taustar=0, qstar=0, qt=0, Gt=0, qtf=0, tauult=0, Sult=0, Hult=0, qtg=0;
    double time=0, ifault=1, Slmin=0;
    int iterate=0, prints=0, M=0, formulation=0, k=0, j=0, notfaultedyet=1, check=0;
    double eta[101], x[101], qb[101], Sl[101], tau[101], Ht[101];
    
        
        check =Initialize(&Qf, &If, &B, &D, &lamdap, &kc, &S, &Gtf, &L, &dt, &iterate, &prints,
                &M, &alphau, &alphar, &alphat, &nt, &tauc, &phis, &R, &Cf, &formulation, &rf,
                &deltaeta, &tf, &dx, &Slmin, &H, &taustar, &qstar, &qt, &Gt, &qtf, &tauult,
                &Sult, &Hult, eta, x, &qtg, &ifault);
        if (check == 1)
            return 1;
        
        //Declare variables dependent on prints
        
        double printmatrix[prints+2][101], Slmatrix[prints+2][101], Hmatrix[prints+2][101];
        double taumatrix[prints+2][101], qbmatrix[prints+2][101];
        
        //Save initial data
        
        SaveDatatoMatrix(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix, eta,
            Sl, Ht, tau, qb, time, k, M);
        
        //Time Loop
        
        for(k = 1; k <= prints; k++) {
            for(j = 1; j <= iterate; j++) {
                Run(&notfaultedyet, tf, time, ifault, M, eta, deltaeta, dt, Sl, dx, tau,
                    Ht, Qf, kc, alphar, B, D, R, Cf, formulation, qb, phis, tauc, nt,
                    alphat, Slmin, lamdap, If, alphau, qtg);
                    time += (dt/(3600*24*365.25));
            }
            SaveDatatoMatrix(printmatrix, Slmatrix, Hmatrix, taumatrix, qbmatrix, eta,
                Sl, Ht, tau, qb, time, k, M);
        }
    
    Finalize(printmatrix, x, M, prints, H, taustar, qstar, qt, Gt, qtg, dx, Slmatrix,
        Hmatrix, taumatrix, qbmatrix);
    
    return 0;
}
