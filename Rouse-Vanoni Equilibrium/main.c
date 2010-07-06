#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Initialize(double *, double *, double *);
int Run(double, double, double, double [], double [], int *);
int Finalize(int, double [], double []);

int main (int argc, const char * argv[]) {
    double init_ratio=0.0, vs=0.0, u=0.0;
    double zH[100]={0}, cb[100];
    int terms=0;
    
    Initialize(&init_ratio, &vs, &u);
    Run(init_ratio, vs, u, zH, cb, &terms);
    Finalize(terms, zH, cb);
    return 0;
}
