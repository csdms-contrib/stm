/*
 *  SetStrainCurves.c
 *  Acronym1R
 *
 *  Created by Andrew Leman on 6/16/09.
 *  Copyright 2009 The University of Illinois-Civil Engineering Department.
 *  All rights reserved.
 */

#include "SetStrainCurves.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.81

int SetStrainCurves(float po[], float oo[], float so[]) {
    //Initialize
    
    //Run
    po[1] = 0.6684;
    po[2] = 0.7639;
    po[3] = 0.8601;
    po[4] = 0.9096;
    po[5] = 0.9615;
    po[6] = 1.0000;
    po[7] = 1.055;
    po[8] = 1.108;
    po[9] = 1.197;
    po[10] = 1.302;
    po[11] = 1.407;
    po[12] = 1.529;
    po[13] = 1.641;
    po[14] = 1.702;
    po[15] = 1.832;
    po[16] = 1.937;
    po[17] = 2.044;
    po[18] = 2.261;
    po[19] = 2.499;
    po[20] = 2.732;
    po[21] = 2.993;
    po[22] = 3.477;
    po[23] = 4.075;
    po[24] = 4.469;
    po[25] = 5.016;
    po[26] = 6.158;
    po[27] = 7.821;
    po[28] = 10.06;
    po[29] = 14.38;
    po[30] = 19.97;
    po[31] = 25.79;
    po[32] = 38.57;
    po[33] = 68.74;
    po[34] = 91.95;
    po[35] = 231.2;
    po[36] = 2320.0;
    
    oo[1] = 1.011;
    oo[2] = 1.011;
    oo[3] = 1.01;
    oo[4] = 1.008;
    oo[5] = 1.004;
    oo[6] = 0.9997;
    oo[7] = 0.9903;
    oo[8] = 0.9789;
    oo[9] = 0.9567;
    oo[10] = 0.9273;
    oo[11] = 0.8964;
    oo[12] = 0.8604;
    oo[13] = 0.8287;
    oo[14] = 0.8123;
    oo[15] = 0.7796;
    oo[16] = 0.7554;
    oo[17] = 0.7326;
    oo[18] = 0.6928;
    oo[19] = 0.6585;
    oo[20] = 0.6345;
    oo[21] = 0.615;
    oo[22] = 0.5877;
    oo[23] = 0.564;
    oo[24] = 0.5523;
    oo[25] = 0.5395;
    oo[26] = 0.5209;
    oo[27] = 0.5045;
    oo[28] = 0.4917;
    oo[29] = 0.479;
    oo[30] = 0.4712;
    oo[31] = 0.4668;
    oo[32] = 0.462;
    oo[33] = 0.4578;
    oo[34] = 0.4564;
    oo[35] = 0.4541;
    oo[36] = 0.4527;

    so[1] = 0.8157;
    so[2] = 0.8157;
    so[3] = 0.8182;
    so[4] = 0.8233;
    so[5] = 0.8333;
    so[6] = 0.8439;
    so[7] = 0.8621;
    so[8] = 0.8825;
    so[9] = 0.9214;
    so[10] = 0.9723;
    so[11] = 1.025;
    so[12] = 1.083;
    so[13] = 1.13;
    so[14] = 1.153;
    so[15] = 1.196;
    so[16] = 1.225;
    so[17] = 1.25;
    so[18] = 1.287;
    so[19] = 1.313;
    so[20] = 1.333;
    so[21] = 1.352;
    so[22] = 1.38;
    so[23] = 1.403;
    so[24] = 1.414;
    so[25] = 1.426;
    so[26] = 1.444;
    so[27] = 1.458;
    so[28] = 1.469;
    so[29] = 1.48;
    so[30] = 1.486;
    so[31] = 1.49;
    so[32] = 1.493;
    so[33] = 1.497;
    so[34] = 1.498;
    so[35] = 1.499;
    so[36] = 1.5;
    
    //Finalize
    return 0;
}