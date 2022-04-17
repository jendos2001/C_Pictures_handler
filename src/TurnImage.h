#ifndef TURNIMAGE_H
#define TURNIMAGE_H

#include "structures.h"
#include "libraries.h"
#include "WriteImage.h"
int TurnImage(BITMAPFILEHEADER* bmfh, BITMAPINFOV3* bmiV3, RGB** image, int x1, int y1, int x2, int y2, int alpha, char* outputfile);

#endif
