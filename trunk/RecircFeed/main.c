#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double [], double [], double [], double [], double [], double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, int *, int *, int *, int *, int *, int *);
int SaveDatatoMatrix(double [][101], double [][101], double [][101], double [][101],
    double [], double [], double [], double [], double, double, double, int, int, int);
int Run(double [], double [], double [], double [], double [], double [], double [], double *,
    double *, double *, int *, int *, double, double, double, double, double,
    double, double, double, double *, double, int, int, int, int, int *);
int Finalize(double [][101], double [][101], double [][101], double [][101], double [],
    double [], double [], int, int, int, int);

int main (int argc, const char * argv[]) {
    
    //Declarations
    double xhat[101], etadhat[101], Htil[101], qtil[101], Sl[101], bgh1[101];
    double etatila=0, SNup=0, SNdown=0, Fro=0, nt=0, Fl=0, etatilainit=0, taur=0;
    double SNl=0, dt=0, dxhat=0, Nhalf=0, qw=0, Ntot=0, qtilg=0, timehat=0, Htilend=0;
    int M=0, prints=0, iterates=0, Nreach=0, k=0, m=0, bombed=0, equilibriates=0;
    int SNcounter=0, check=0, flume=0, SNsize=0;
    
    check = Initialize(xhat, etadhat, Htil, qtil, bgh1, &etatila, &SNup, &SNdown, &Fro, &nt, &Fl,
            &etatilainit, &taur, &SNl, &dt, &dxhat, &Nhalf, &qw, &Ntot, &qtilg, &Htilend, &timehat,
            &M, &prints, &iterates, &Nreach, &flume, &bombed);
    if (check == 1)
        return 1;
        
    //More Declarations
    SNsize = (prints*iterates) + 1;
    bombed = 0;
    double SNupvector[SNsize], SNdownvector[SNsize];
    double printmatrix[prints+3][101], Slmatrix[prints+3][101], qbmatrix[prints+3][101], Hmatrix[prints+3][101];
    
    SaveDatatoMatrix(printmatrix, Slmatrix, qbmatrix, Hmatrix, etadhat, Sl, qtil,
        Htil, timehat, Fl, etatila, Nreach, k, flume);
        
    for (k=1; k <= prints; k++) {
        for (m=1; m <= iterates; m++) {
            timehat += dt;
            Run(SNupvector, SNdownvector, etadhat, qtil, Htil, Sl, bgh1, &etatila, &SNup,
                &SNdown, &SNcounter, &equilibriates, dt, qtilg, Fl, dxhat, qw, Fro,
                taur, nt, &Htilend, timehat, Nreach, k, m, flume, &bombed);
            if ((m == iterates) || (equilibriates == 1) || (bombed == 1))
                break;
        }
        SaveDatatoMatrix(printmatrix, Slmatrix, qbmatrix, Hmatrix, etadhat, Sl, qtil,
            Htil, timehat, Fl, etatila, Nreach, k, flume);
        if ((k == prints) || (equilibriates == 1) || (bombed == 1))
            break;
    }
    
    if (bombed != 1)
        Finalize(printmatrix, Slmatrix, qbmatrix, Hmatrix, SNupvector, SNdownvector, xhat, SNcounter, Nreach, k, M);
    
    return 0;
}
