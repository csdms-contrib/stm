#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Prototypes

int Initialize(double [], double *, double *, double *, double *);
int Run(double *, double *, double *, double, double, double, double);
int Finalize(double, double, double);

int main (int argc, const char * argv[]) {

    double viscosity=0.0, spec_grav=0.0, grain_size=0.0, grav=0.0, velocity=0.0;
    double Rep=0, Rf=0, data[4];

    Initialize(data, &viscosity, &spec_grav, &grain_size, &grav);
    Run(&velocity, &Rep, &Rf, viscosity, spec_grav, grain_size, grav);
    Finalize(Rep, Rf, velocity);
    
    return 0;
}
