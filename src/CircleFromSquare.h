#ifndef CIRCLEFROMSQUARE_H
#define CIRCLEFROMSQUARE_H

#include "libraries.h"
#include "structures.h"
void CircleFromSquareWithoutFill(BITMAPINFOV3* bmiV3, RGB** image ,int x1, int y1, int x2, int y2, int r, int g, int b, int d);
void CircleFromSquareWithFill(BITMAPINFOV3* bmiV3, RGB** image ,int x1, int y1, int x2, int y2, int r, int g, int b, int d, int r_z, int g_z, int b_z);

#endif
