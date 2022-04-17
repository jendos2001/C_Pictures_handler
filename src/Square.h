#ifndef SQUARE_H
#define SQUARE_H

#include "structures.h"
#include "libraries.h"
void MakeSquareWithoutFill(BITMAPINFOV3* bmiV3, RGB** image, int x, int y, int l, int d, int r, int g, int b);
void MakeSquareWithFill(BITMAPINFOV3* bmiV3, RGB** image, int x, int y, int l, int w, int r, int g, int b, int r_z, int g_z, int b_z);

#endif
