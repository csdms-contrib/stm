#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define timeyear 31557600

int Initialize(double [], double [], double [], double [], double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, int *, int *, int *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double *, double *, double *,
    double *, double *, double *, double *, double *, double [], double []);
int Run(double [], double [], double [], double [], double [], double, double, double,
    double, double, double, double, double, double, double, double, double, double,
    double, double, double, double, int);
int SaveDatatoMatrix(double [][101], double [][101], double [][101], double [][101],
    double [][101], double [], double [], double [], double [], double [], double,
    int, int);
int Finalize(double [][101], double [][101], double [][101], double [][101], double [][101],
    double [], int, int);

int main (int argc, const char * argv[]) {
   
   //Declarations
   double Qt[101], Sl[101], x[101], eta[101], Bbf[101], Hbf[101];
   double Qf=0, Qbtffeed=0, lambig=0, I=0, D=0, R=0, L=0, Bf=0, Sinu=0, lamp=0;
   double Cz=0, Sfbl=0, etaddot=0, dt=0, Yearstart=0, Yearstop=0, aleh=0, neh=0;
   double tausforms=0, alp=0, np=0, tausc=0, tausformg=0, Cf=0, rform=0, tausform=0;
   double loadcoef=0, widthcoef=0, depthcoef=0, dx=0, time=0;
   int M=0, prints=0, iterates=0, check=0, k=0, m=0;
   
   
    check = Initialize(Qt, Sl, x, eta, &Qf, &Qbtffeed, &lambig, &I, &D, &R, &L,
            &Bf, &Sinu, &lamp, &Cz, &Sfbl, &etaddot, &M, &prints,
            &iterates, &dt, &Yearstart, &Yearstop, &aleh, &neh,
            &tausforms, &alp, &np, &tausc, &tausformg, &Cf, &rform,
            &tausform, &loadcoef, &widthcoef, &depthcoef, &dx, Bbf, Hbf);
    if (check == 1)
        return 1;
        
    //More Declarations
    double printmatrix[prints+2][101], Bbfmatrix[prints+2][101], Hbfmatrix[prints+2][101];
    double Slmatrix[prints+2][101], qbmatrix[prints+2][101];
        
    SaveDatatoMatrix(printmatrix, Bbfmatrix, Hbfmatrix, Slmatrix, qbmatrix, eta, Bbf,
        Hbf, Sl, Qt, time, k, M);
        
    for (k=1; k <= prints; k++) {
        for (m=1; m <= iterates; m++) {
            Run(Sl, eta, Qt, Bbf, Hbf, dx, loadcoef, widthcoef, depthcoef, D, Qf,
                I, Sinu, lambig, Bf, lamp, dt, time, Qbtffeed, Yearstart, Yearstop,
                etaddot, M);
        time += (dt/timeyear);
        }
        SaveDatatoMatrix(printmatrix, Bbfmatrix, Hbfmatrix, Slmatrix, qbmatrix, eta,
            Bbf, Hbf, Sl, Qt, time, k, M);
    }
    
    Finalize(printmatrix, Bbfmatrix, Hbfmatrix, Slmatrix, qbmatrix, x, prints, M);
        
    return 0;
}
