#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

//Defining the data structures for GSD and hydro

typedef struct {
    double di;
    double plff;
    double Ffl;
    double Ffs;
} quad;

typedef struct {
    double qw;
    double qbTf;
    int nstep;
} triple;

//Prototypes of the functions used in main

int ReadIn(quad [], triple [], int *, double *, double *, double *, int *, int *,
        int *, double *, double *, double *, double *, double *, double *, double *,
        int *, int *, int *, double *, double *, int *);
int Initialize(quad [], triple [], int *, int *, double [], double [], double [], double [],
        double [], int, int, double *, double *, int [], double *, double *, double *, double *,
        double, double, double, double [], double [], double [], double *, double *, double *,
        double [], double [], double [], double [][16], double [], double [], double [],
        double [], double *, double, double, int, double, double [], int *);
int SaveDatatoMatrix(double [][101], double [][101], double [][101], double [][101],
        double [][101], double [][101], double [][101], double [][101], double [],
        double [], double [], double [], double [], double [], double, double, int,
        int, double [], double []);
int Run(double [][16], double [][16], double [], triple [], double *, double *, double [],
        double [], double [], double, double, double [], double, double, double [], double [],
        quad [], double [][16], double [][16], double [], double [], double [], double [],
        double [], double, double [], double [], double [], double, double, double, double,
        double, double [], double [], double [], double [], double [], double [], double [],
        double [], double [], double [], double [], double [], double [], double [], double [],
        double [], double [], int, double [], double [], double [], double [], int, int, int [],
        int, int, int, int, int, int *, double [], int, int);
int Finalize(quad [], double [][101], double [][101], double [][101], double [][101],
        double [][101], double [][101], double [][101], double [][16], double [][16],
        double [], double [][101], double [], double [], double [], double [], double [],
        double [], double [], double [], double [], double [], double [], double [],
        double [], double [], int, double [], double [], double [], double [], double,
        double, double, double, double, int, int, int);

//The MAIN FUNCTION

int main (int argc, const char * argv[]) {
    //INITIALIZE
    quad GSD[16];
    triple hydro[17];
    double etad=0, S=0, L=0, nk=0, na=0, alphar=0, R=0, lps=0, alphau=0, dt=0;
    double dtflood=0, atrans=0, dx=0, qbToave=0, qwave=0, durhyd=0, I=0, LoadAnn=0;
    double Dsgsi=0, Ds90si=0, Dsgsub=0, time=0, qbTo=0, qw=0;
    double po[37], so[37], oo[37];
    int M=0, prints=0, iterates=0, npp=0, np=0, ndisc=0, ncyc=0, totstep=0;
    int maxflow=0, k=0, m=0, check=0, counter=0;
        
        
        //Reads in values to function and scales where needed
        check = ReadIn(GSD, hydro, &ncyc, &etad, &S, &L, &M, &prints, &iterates, &nk, &na,
                    &alphar, &R, &lps, &alphau, &atrans, &npp, &np, &ndisc, &dtflood,
                    &dx, &totstep);
        if (check == 1)
            return 1;
               
        //Variable declarations dependent on ReadIn values
        int beginstep[ndisc+2];
        double ds[np+8], psi[np+8], plf[np+8], Fl[np+8], Fs[np+8], H[M+2], tausg[M+2], qbT[M+2];
        double F[M+2][16], pl[M+2][16], eta[M+2], x[M+2], dsgs[M+2], Dx90s[M+2], qbTave[101], Sl[M+2];
        double printmatrix[prints+2][101], dsgmatrix[prints+2][101], qbTmatrix[prints+2][101];
        double Hmatrix[prints+2][101], tausgmatrix[prints+2][101], D90matrix[prints+2][101];
        double Ft[npp+9], plt[npp+9], Laold[M+2], Ffinerflowmaxds[npp+9];
        double plfinerflowmaxds[npp+9], Hflowmax[M+2], tausgflowmax[M+2], Fflowmax[npp+9];
        double plflowmax[npp+9], dsgsflowmax[M+2], dsglflowmax[M+2];
        double Ffinerflowendds[npp+9], plfinerflowendds[npp+9];
        double Hflowend[M+2], tausgflowend[M+2], Fflowend[npp+9], plflowend[npp+9];
        double dsgsflowend[M+2], dsglflowend[M+2];
        double Smatrix[prints+2][101], dlgmatrix[prints+2][101];
        double Fave[M+2][16], plave[M+2][16];
        double etaendcyc[M+2], dsgsave[M+2], dsglave[M+2];
        
         //Declares variables dependent on totstep
        double qwforprint[totstep+2], qbToforprint[totstep+2], qbTfforprint[totstep+2];
        double dayforprint[totstep+2];
        
        Initialize(GSD, hydro, &npp, &np, ds, psi, plf, Fl, Fs, ndisc, totstep, &qbToave,
        &qwave, beginstep, &durhyd, &I, &LoadAnn, &dt, dtflood, ncyc, R, qwforprint, qbToforprint,
        dayforprint, &Dsgsi, &Dsgsub, &Ds90si, po, oo, so, F, eta, x, dsgs, Dx90s, &dx, S, L, M,
        etad, Sl, &maxflow);
               
        //Saves Data to Matrix
        SaveDatatoMatrix(printmatrix, dsgmatrix, qbTmatrix, dlgmatrix, Smatrix,
            Hmatrix, tausgmatrix, D90matrix, eta, dsgsave, qbTave, H, tausg, Dx90s,
            qbToave, time, M, k, Sl, dsglave);
        
        //The TIME LOOP
        for (k=1; k <= prints; k++) {
            for (m=1; m <= iterates; m++) {
                Run(Fave, plave, qbTave, hydro, &qw, &qbTo, eta, tausg, H, dx, nk, Dx90s,
                    alphar, R, dsgs, Sl, GSD, F, pl, qbT, ds, po, oo, so, na, Fs, Ft, plf,
                    alphau, atrans, dt, I, lps, Laold, Ffinerflowmaxds, plfinerflowmaxds,
                    Hflowmax, tausgflowmax, Fflowmax, plflowmax, dsgsflowmax, dsglflowmax,
                    Ffinerflowendds, plfinerflowendds, Hflowend, tausgflowend, Fflowend,
                    plflowend, dsgsflowend, dsglflowend, maxflow, etaendcyc, plt, dsgsave,
                    dsglave, np, ndisc, beginstep, totstep, M, npp, k, m, &counter,
                    qbTfforprint, prints, iterates);
                time += (dt*(totstep*1.0));
            }
            SaveDatatoMatrix(printmatrix, dsgmatrix, qbTmatrix, dlgmatrix, Smatrix,
                Hmatrix, tausgmatrix, D90matrix, eta, dsgsave, qbTave, H, tausg, Dx90s,
                qbToave, time, M, k, Sl, dsglave);
        }
        
    Finalize(GSD, printmatrix, dsgmatrix, qbTmatrix, tausgmatrix, Smatrix, dlgmatrix,
        Hmatrix, F, pl, H, D90matrix, x, etaendcyc, Hflowmax, Hflowend, tausgflowmax,
        tausgflowend, dsgsflowmax, dsgsflowend, dsglflowmax, dsglflowend, Ffinerflowmaxds,
        Ffinerflowendds, plfinerflowmaxds, plfinerflowendds, totstep, qbTfforprint,
        dayforprint, qwforprint, qbToforprint, qwave, qbToave, Dsgsi, Dsgsub, LoadAnn, M,
        prints, npp);
    
    return 0;
}
