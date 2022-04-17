#ifndef WRITEIMAGE_H
#define WRITEIMAGE_H

#include "structures.h"
#include "libraries.h"
void WriteImage(BITMAPFILEHEADER* bmfh, BITMAPINFOV3* bmiV3, RGB** image, char* outputfile);

#endif