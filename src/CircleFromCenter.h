#ifndef CIRCLEFROMCENTER_H
#define CIRCLEFROMCENTER_H

#include "libraries.h"
#include "structures.h"
void CircleFromCenterWithoutFill(BITMAPINFOV3* bmiV3, RGB** image, int x_c, int y_c, int radius, int r, int g, int b, int w);
void CircleFromCenterWithFill(BITMAPINFOV3* bmiV3, RGB** image, int x_c, int y_c, int radius, int r, int g, int b, int w, int r_z, int g_z, int b_z);

#endif
