#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//define struct and prototypes
typedef struct {
        float size;
        float perfiner;
    } pair;

int Initialize(pair [], float [], float [], int *);
int Run(pair [], float [], float [], int, float *, float *, int *);
int Finalize(pair [], int, float, float, float [], float [], int);

//main function

int main (int argc, const char * argv[]) {
    
    int terms=0, numinterp=0;
    float Dg=0.0, sigma=0.0;
    float D[100];
    float f[100];
    float interp[10];
    float input[10];
    pair datapoints[100];
    
    Initialize(datapoints, D, f, &terms);
    Run(datapoints, interp, input, terms, &Dg, &sigma, &numinterp);
    Finalize(datapoints, terms, Dg, sigma, interp, input, numinterp);
    return 0;
}
