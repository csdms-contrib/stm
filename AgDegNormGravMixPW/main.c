#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

//Defines the data structure for GSD values

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

//Prototypes used in the main function

int Initialize(quad [], double *, double *, double *, double *, double *, double *, double *,
        int *, int *, int *, double *, double *, double *, double *, double *, double *, double *,
        int *, int *, double *, double *, double *, double [], double [], double [], double [],
        double [], double *, double [], double [], double [], double *, double *, double *, int *,
        double [][21], double [], double [], double [], double [], double [], double [], double *,
        double *, int *);
int SaveDatatoMatrix(double [][101], double [][101], double [][101], double [][101], double [][101],
        double [][101], double [][101], double [], double [], double [], double [], double [],
        double [], double [], double, double, int, int);
int Run(int, double [], double [], double [], double [], double [], double, double, double [],
        double [], double, double, double, double [], quad [], double, double, double [][21],
        double [][21], double [], double [], double [], double [], double [], double [], int,
        double [], double, double [][101], double, double, double [], double [], double, double,
        double, double, double, double [], double, int);
int Finalize(double [][101], double [], int, int, quad [], int, double [][101], double [][101],
        double [], double [][21], double [][21], double [][101], double [][101], double [][101],
        double [][101], double);

//The MAIN function

int main (int argc, const char * argv[]) {

    //DECLARATIONS
    quad GSD[21];
    double ds[21], psi[21], plf[21], Fl[21], Fs[21], Ft[21], po[37], oo[37], so[37];
    double qw=0, qbTf=0, I=0, etad=0, S=0, L=0, dt=0, nk=0, na=0, alphar=0, R=0;
    double lps=0, alphau=0, atrans=0, rload=0, Cexp=0, nexp=0, fracsandl=0;
    double Dsgsi=0, Dx50si=0, Dx90si=0, dx=0, time=0, Cf=0;
    int M=0, prints=0, iterates=0, npp=0, np=0, check=0, k=0, m=0, bedloadrelation=1, formulation=0;
    double F[101][21], pl[101][21], eta[101], x[101], Dx90s[101], Dx50s[101], Sl[101];
    double dsgs[101], fracsand[101], qbT[101], tausg[101], taus50[101], H[101], Laold[101];
    
        check = Initialize(GSD, &qw, &qbTf, &I, &etad, &S, &L, &dt, &M, &prints, &iterates,
                    &nk, &na, &alphar, &R, &lps, &alphau, &atrans, &npp, &np, &rload, &Cexp,
                    &nexp, ds, psi, plf, Fl, Fs, &fracsandl, po, oo, so, &Dsgsi, &Dx50si,
                    &Dx90si, &bedloadrelation, F, eta, x, dsgs, Dx90s, Dx50s, fracsand, &dx,
                    &Cf, &formulation);
        if (check == 1)
            return 1;
                            
        //Declare variables dependent on user inputted values
        double printmatrix[prints+2][101], dsgmatrix[prints+2][101], qbTmatrix[prints+2][101];
        double Hmatrix[prints+2][101], tausgmatrix[prints+2][101], Slmatrix[prints+2][101];
        double D90matrix[prints+2][101];
        
        //Saves Initial Bed Profile to print later
        SaveDatatoMatrix(printmatrix, dsgmatrix, qbTmatrix, Hmatrix, tausgmatrix,
            Slmatrix, D90matrix, eta, dsgs, qbT, H, tausg, Sl, Dx90s, qbTf, time, M, k);        
        
        //TIME LOOP
        for (k=1; k <= (prints); k++) {
            for (m=1; m <= (iterates); m++) {
                Run(M, eta, Sl, tausg, taus50, H, dx, nk, Dx90s, Dx50s, qw, alphar, R, dsgs,
                    GSD, np, npp, F, pl, qbT, ds, po, oo, so, Ft, bedloadrelation, fracsand,
                    qbTf, qbTmatrix, time, na, Fs, plf, alphau, atrans, dt, I, lps, Laold,
                    Cf, formulation);
                time += dt;
            }
            SaveDatatoMatrix(printmatrix, dsgmatrix, qbTmatrix, Hmatrix, tausgmatrix,
                Slmatrix, D90matrix, eta, dsgs, qbT, H, tausg, Sl, Dx90s, qbTf, time, M, k);
        }
        
    Finalize(printmatrix, x, M, prints, GSD, npp, dsgmatrix, qbTmatrix, H, F, pl, Slmatrix,
        Hmatrix, tausgmatrix, D90matrix, qbTf);
   
    return 0;
}
